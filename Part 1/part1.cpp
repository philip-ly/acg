#include <iostream>
#include "part1.h"

int main(int argc, const char * argv[]) {
    typedef ADD<VAR,MUL<SUB<VAR,LIT<2>>,SUB<VAR,LIT<3>>>> FORMULA;
    printf("Hi");
    printf("Answer: %d\n", (DIV<LIT<10>,LIT<1>>::eval(10)));
    // printf("Static %d", (EVAL<10,FORMULA>::RET));
}
