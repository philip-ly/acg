#include <iostream>
#include "part2.h"

int main(int argc, const char * argv[]) {
    typedef 
    ADD<
        VAR<BOUNDS<-5,10>>,
        MUL<
            SUB<
                VAR<BOUNDS<-5,10>>,
                LIT<2>>,
            SUB<
                VAR<BOUNDS<-5,10>>,
                LIT<3>
                >
            >
        >
    FORMULA;
    typedef ADD<LIT<10>,VAR<BOUNDS<-1,10>>> shorttest;
    typedef DIV<LIT<10>,VAR<BOUNDS<-1,10>>> shorttest2;

    int x = shorttest::lower;
    
    printf("Lower: %d\nUpper: %d \n", shorttest2::lower , shorttest2::upper);
    printf("Answer: %d\n", (shorttest2::eval(1)));
    //static_assert(FORMULA::eval(0) == 6);
};