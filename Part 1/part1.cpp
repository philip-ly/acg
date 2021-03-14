#include <iostream>
#include "part1.h"

int main(int argc, const char * argv[]) {
    typedef ADD<VAR,MUL<SUB<VAR,LIT<2>>,SUB<VAR,LIT<3>>>> FORMULA;
    typedef DIV<LIT<10>,LIT<0>> FORMULA2;
    static_assert(DIV<LIT<10>,LIT<2>>::eval(10)==5);
    printf("Answer: %d\n", (DIV<LIT<10>,LIT<2>>::eval(10)));
}
