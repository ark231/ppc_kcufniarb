cmake_minimum_required(VERSION 3.23.2)

project(ppc_kcufniarb::test CXX)

add_library(ppc_kcufniarb STATIC kcufniarb.cpp)
target_compile_features(ppc_kcufniarb PUBLIC cxx_std_17)
if(DEFINED BRAINFUCK_CPP_CELL_BITWIDTH)
    if(DEFINED BRAINFUCK_CPP_CELL_IS_SIGNED)
        target_compile_definitions(ppc_kcufniarb PUBLIC BRAINFUCK_CPP_CELL_BITWIDTH=${BRAINFUCK_CPP_CELL_BITWIDTH})
        if(BRAINFUCK_CPP_CELL_IS_SIGNED)
            target_compile_definitions(ppc_kcufniarb PUBLIC BRAINFUCK_CPP_CELL_IS_SIGNED=true)
        else()
            target_compile_definitions(ppc_kcufniarb PUBLIC BRAINFUCK_CPP_CELL_IS_SIGNED=false)
        endif()
    endif()
endif()
if(DEFINED BRAINFUCK_CPP_STEP_SLEEP_TIME)
    target_compile_definitions(ppc_kcufniarb PUBLIC BRAINFUCK_CPP_STEP_SLEEP_TIME=${BRAINFUCK_CPP_STEP_SLEEP_TIME})
endif()
if(DEFINED BRAINFUCK_CPP_ENABLE_PRINT_MEMORY)
    target_compile_definitions(ppc_kcufniarb PUBLIC ENABLE_PRINT_MEMORY)
endif()

target_compile_options(
    ppc_kcufniarb
    PRIVATE $<$<CXX_COMPILER_ID:Clang>:-Wall
            -Weverything
            -Wno-c++98-compat
            -Wno-c++98-compat-pedantic>
            $<$<CXX_COMPILER_ID:GNU>:-pedantic
            -Wall
            -Wextra
            -Wcast-align
            -Wcast-qual
            -Wctor-dtor-privacy
            -Wdisabled-optimization
            -Wformat=2
            -Winit-self
            -Wlogical-op
            -Wmissing-declarations
            -Wmissing-include-dirs
            -Wnoexcept
            -Wold-style-cast
            -Woverloaded-virtual
            -Wredundant-decls
            -Wshadow
            -Wsign-conversion
            -Wsign-promo
            -Wstrict-null-sentinel
            -Wstrict-overflow=2
            -Wswitch-default
            -Wundef
            -Wno-unused
            -Wunsafe-loop-optimizations
            -Wfloat-equal>
            $<$<CXX_COMPILER_ID:MSVC>:/W4>)

if(BRAINFUCK_CPP_COMPILE_TEST)
    add_executable(test test.cpp)
    target_link_libraries(test ppc_kcufniarb)

    target_compile_features(test PUBLIC cxx_std_20)
    target_compile_options(
        test
        PRIVATE $<$<CXX_COMPILER_ID:Clang>:-Wall
                -Weverything
                -Wno-c++98-compat
                -Wno-c++98-compat-pedantic>
                $<$<CXX_COMPILER_ID:GNU>:-pedantic
                -Wall
                -Wextra
                -Wcast-align
                -Wcast-qual
                -Wctor-dtor-privacy
                -Wdisabled-optimization
                -Wformat=2
                -Winit-self
                -Wlogical-op
                -Wmissing-declarations
                -Wmissing-include-dirs
                -Wnoexcept
                -Wold-style-cast
                -Woverloaded-virtual
                -Wredundant-decls
                -Wshadow
                -Wsign-conversion
                -Wsign-promo
                -Wstrict-null-sentinel
                -Wstrict-overflow=2
                -Wswitch-default
                -Wundef
                -Wno-unused
                -Wunsafe-loop-optimizations
                -Wfloat-equal>
                $<$<CXX_COMPILER_ID:MSVC>:/W4>)
endif()
