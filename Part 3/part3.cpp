#include <iostream>
#include "part3.h"

//This version of part 3 uses a pointer in eval to count the current position in the variable array.
//An alternative in "Part 3 Alternative" allows the specification of 
int main(int argc, const char * argv[]) {
    typedef ADD<VAR<BOUNDS<1,10>>,MUL<SUB<VAR<BOUNDS<1,10>>,LIT<2>>,SUB<VAR<BOUNDS<1,10>>,LIT<3>>>> FORMULA;
    typedef DIV<VAR<BOUNDS<5,10>>,VAR<BOUNDS<0,10>>> shorttest;

    int x = shorttest::lower;
    int vals [] = {8,6};
    const int numberOfInputs = 2;
    int inputs [numberOfInputs][3] = {
        {8,6,5},
        {5,3,5}
    };
    int outputs [numberOfInputs];

    for (int i=0 ; i<numberOfInputs; ++i){
        // A pointer to an int is used to keep track of the position in the array for each variable.
        int x = 0;
        outputs[i] = FORMULA::eval(inputs[i], &x); 
        printf("Answer: Input %d = %d \n", i, outputs[i]);
        // printf("Lower Bound: %d = %d ", i, outputs[i]);
        // printf("Upper Bound: %d = %d", i, outputs[i]);
    };

};