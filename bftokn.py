#!/bin/env python3

import argparse
import sys


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
        input = sys.stdin.read()
    else:
        with open(args.infile, "r") as infile:
            input = infile.read()
    result = ""

    if args.use_macro:
        section_start = "_"
    elif args.use_using:
        section_start = "_()"
    else:
        section_start = "::kcufniarb::kcufniarB()"

    for c in reversed(input):
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
    if args.outfile is None:
        print(result)
    else:
        with open(args.outfile, "w") as outfile:
            outfile.write(result)


if __name__ == "__main__":
    main()
