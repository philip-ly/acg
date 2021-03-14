#include <iostream>
#include "part3.h"

int main(int argc, const char * argv[]) {
    typedef ADD<VAR<BOUNDS<1,10>,0>,MUL<SUB<VAR<BOUNDS<1,10>,0>,LIT<2>>,SUB<VAR<BOUNDS<1,10>,0>,LIT<3>>>> FORMULA;
    // printf("Hi");
    typedef ADD<VAR<BOUNDS<5,10>,1>,VAR<BOUNDS<5,10>,0>> shorttest;

    int x = shorttest::lower;
    int vals [] = {8,6};
    const int numberOfInputs = 2;
    int inputs [numberOfInputs][3] = {
        {8,6,5},
        {5,3,5}
    };
    int outputs [numberOfInputs];

    for (int i=0 ; i<numberOfInputs; ++i){
        outputs[i] = FORMULA::eval(inputs[i]);
        printf("Answer: Input %d = %d \n", i, outputs[i]);
        // printf("Lower Bound: %d = %d ", i, outputs[i]);
        // printf("Upper Bound: %d = %d", i, outputs[i]);
    };
    
    // printf("Lower: %d\nUpper: %d \n", shorttest::lower , shorttest::upper);
    // printf("Answer: %d\n", (shorttest::eval(vals)));
    //typedef ADD<LIT<10>,LIT<10>>
    // printf("Static %d", (EVAL<10,FORMULA>::RET));
};