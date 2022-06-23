#!/bin/env python3

import argparse
import sys
from pathlib import Path
import shutil
import subprocess


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--infile", type=str)
    parser.add_argument("-o", "--outfile", type=str)
    parser.add_argument("--loop-type", choices=["shift-equal", "operator-bracket"], default="operator-bracket")
    parser.add_argument("--use-macro", action="store_true")
    parser.add_argument("--use-using", action="store_true")
    parser.add_argument(
        "--output-type",
        choices=["kcufniarb-only", "cpp-line", "cpp-source", "cpp-source-with-cmake"],
        default="kcufniarb-only",
    )
    args = parser.parse_args()

    if args.infile is None:
        source = sys.stdin.read()
    else:
        with open(args.infile, "r") as infile:
            source = infile.read()
    result = ""

    if args.use_macro:
        section_start = "_"
    elif args.use_using:
        section_start = "_()"
    else:
        section_start = "::kcufniarb::kcufniarB()"

    for c in reversed(source):
        if c == ">":
            result += "!"
        elif c == "<":
            result += "~"
        elif c == "+":
            result += "+"
        elif c == "-":
            result += "-"
        elif c == ".":
            result += "*"
        elif c == ",":
            result += "&"
        elif c == "[":
            if args.loop_type == "shift-equal":
                result += section_start
                result += ">>="
            elif args.loop_type == "operator-bracket":
                result += section_start
                result += "]"
                result += "|="
        elif c == "]":
            if args.loop_type == "shift-equal":
                result += section_start
                result += "<<="
            elif args.loop_type == "operator-bracket":
                # result += section_start
                # result += "="
                result += section_start
                result += "["
    result += section_start
    if "cpp" in args.output_type:
        result += ";"
    if "cpp-source" in args.output_type:
        if args.use_macro:
            pre_def = "#define BRAINFUCK_CPP_ENABLE_MACRO"
        elif args.use_using:
            pre_def = "#define BRAINFUCK_CPP_ENABLE_USING"
        else:
            pre_def = ""
        result = f"""\
{pre_def}
#include "kcufniarb.hpp"
int main(){{
    {result}
}}\
        """
    cmake_result = f"""\
cmake_minimum_required(VERSION 3.23.2)
project({Path(args.infile).stem if args.infile is not None else "unnamed"} CXX)

# include(ExternalProject)
# ExternalProject_Add(
#     ppc_kcufniarb_git
#     GIT_REPOSITORY git@github.com:ark231/ppc_kcufniarb.git
#     GIT_TAG {"bracket" if args.loop_type == "operator-bracket" else "main"}
#     GIT_PROGRESS ON
# )
# add_subdirectory(${{CMAKE_CURRENT_BINARY_DIR}}/ppc_kcufniarb_git-prefix/src/ppc_kcufniarb_git)
add_subdirectory(${{CMAKE_CURRENT_SOURCE_DIR}}/ppc_kcufniarb)

add_executable({Path(args.infile).stem if args.infile is not None else "unnamed"} {args.outfile})
target_link_libraries({Path(args.infile).stem if args.infile is not None else "unnamed"} PRIVATE ppc_kcufniarb)\
    """
    if args.outfile is None:
        print(result)
        if "cmake" in args.output_type:
            print("\n/*=========================================*/\n")
            print(cmake_result)
    else:
        with open(args.outfile, "w") as outfile:
            outfile.write(result)
        if "cmake" in args.output_type:
            cmake_filepath = Path(args.outfile).parent / "CMakeLists.txt"
            write_output = True
            if cmake_filepath.exists():
                answer = input(f"file {cmake_filepath} exists. Do you Want to overwrite it?[y/N] ")
                if answer.lower() != "y":
                    write_output = False
            if write_output:
                with open(cmake_filepath, "w") as cmakefile:
                    cmakefile.write(cmake_result)
                repo_path = cmake_filepath.parent / "ppc_kcufniarb"
                if repo_path.exists():
                    answer = input(f"repository {repo_path} exists. Do you Want to overwrite it?[y/N] ")
                    if answer.lower() == "y":
                        shutil.rmtree(repo_path)

                subprocess.run(
                    [
                        "git",
                        "clone",
                        "git@github.com:ark231/ppc_kcufniarb.git",
                        repo_path,
                        "-b",
                        "bracket" if args.loop_type == "operator-bracket" else "main",
                    ],
                    check=True,
                )


if __name__ == "__main__":
    main()
