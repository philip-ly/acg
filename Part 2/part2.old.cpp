#include <iostream>
#include "part2.h"
#include <stdexcept>

struct VAR { 
  static constexpr int eval(int var_variable){
    return var_variable;
  };  
};

template <int V>
struct LIT {
  static constexpr int eval(int var_variable){
    return V;
  };
};

template <class L, class R>
struct ADD {
    static constexpr int eval(int var_variable){
        return L::eval(var_variable) + R::eval(var_variable);
    };
};


template<int LOWER, int UPPER>
struct BOUNDS;


// template <int var_variable, class bounds, class F>
// struct EVAL;

// //VARIABLE
// template <int var_variable, class bounds >
// struct EVAL <var_variable, bounds, VAR> {
//     enum {RET = bounds};
// };

// //LITERAL
// template <int var_variable, class bounds, int V>
// struct EVAL <var_variable, bounds, LIT<V> > {
//     enum {RET = 0};
// };

// template <int var_variable, class bounds, class L, class R>
// struct EVAL <var_variable, bounds, ADD<L,R> > {
//   //  enum { RET = EVAL<b,L>::RET  +  EVAL<b,R>::RET } ;
//    enum { RET = 0 } ;
// };




// int main(int argc, const char * argv[]) {
//     //typedef ADD<VAR,MUL<SUB<VAR,LIT<2>>,SUB<VAR,LIT<3>>>> FORMULA;
//     typedef ADD<LIT<10>,LIT<5>> FORMULA;
//     printf("Hi");
//     //printf("Answer: %d\n", (DIV<LIT<10>,LIT<1>>::eval(10)));
//     //printf("Static %d", (EVAL<10,BOUNDS<10,10>,FORMULA>::RET));
// }
