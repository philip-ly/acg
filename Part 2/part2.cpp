#include <iostream>
#include "part2.h"

int main(int argc, const char * argv[]) {
    typedef ADD<VAR<BOUNDS<10,10>>,MUL<SUB<VAR<BOUNDS<10,10>>,LIT<2>>,SUB<VAR<BOUNDS<10,10>>,LIT<3>>>> FORMULA;
    // printf("Hi");
    typedef ADD<LIT<10>,VAR<BOUNDS<5,10>>> shorttest;

    int x = shorttest::lower;
    
    printf("Lower: %d\nUpper: %d \n", shorttest::lower , shorttest::upper);
    printf("Answer: %d\n", (shorttest::eval(8)));
    //typedef ADD<LIT<10>,LIT<10>>
    // printf("Static %d", (EVAL<10,FORMULA>::RET));
};