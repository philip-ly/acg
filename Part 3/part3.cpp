#include <iostream>
#include "part3.h"

int main(int argc, const char * argv[]) {
    typedef ADD<VAR<BOUNDS<10,10>,0>,MUL<SUB<VAR<BOUNDS<10,10>,0>,LIT<2>>,SUB<VAR<BOUNDS<10,10>,0>,LIT<3>>>> FORMULA;
    // printf("Hi");
    typedef ADD<VAR<BOUNDS<5,10>,1>,VAR<BOUNDS<5,10>,0>> shorttest;

    int x = shorttest::lower;
    int vals [] = {8,6};
    
    printf("Lower: %d\nUpper: %d \n", shorttest::lower , shorttest::upper);
    printf("Answer: %d\n", (shorttest::eval(vals)));
    //typedef ADD<LIT<10>,LIT<10>>
    // printf("Static %d", (EVAL<10,FORMULA>::RET));
};