# brainfuck_cpp #
  reversed brainfuck  
[noisrev lamron](README.md)  
)dm.README(]normal version[

## grammer ##
  same as brainfuck. but some operators are altered.  

| brainfuck | ppc_kcufniarb |note|
|:--:|:--:|:--:|
|>|!||
|<|~||
|+|+|++ is also defined, so that `+++` is interpreted correctly|
|-|-|-- 〃|
|.|*||
|,|&||
|[|]\|=||
|]|[||

## requirements ##
  this library uses features added in c++17  

## examples ##
helloworld
```c_cpp
#define BRANFUCK_CPP_ENABLE_MACRO
#include "kcufniarb.hpp"
int main() {
    *++++++++++!*-----------!!!*--------*------*+++*--------*++++++++~~~*++++!!_[-~_[-~+++++!_]|=++!_]|=++++!*+++**+++++++*+!!_[-~_[-~+++++!_]|=++!_]|=+++~~--*++!!_[-~_[-~+++++!_]|=++!_]|=+++++++_;
}
```
