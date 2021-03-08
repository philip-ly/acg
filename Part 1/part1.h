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

template <class L, class R>
struct SUB {
    static constexpr int eval(int var_variable){
        return L::eval(var_variable) - R::eval(var_variable);
    };
};

template <class L, class R>
struct MUL {
    static constexpr int eval(int var_variable){
        return L::eval(var_variable) * R::eval(var_variable);
    };
};

template <class L, class R>
struct DIV {
    static constexpr int eval(int var_variable){
        int right = R::eval(var_variable);
        if (right == 0){
            throw std::invalid_argument("Divide By Zero");
        }
        return L::eval(var_variable) / right;
    };
};


// Static Evaluation Stuff:
// template <int b, class F>
// struct EVAL;

// template <int b>
// struct EVAL <b, VAR> {
//     enum {RET = b};
// };

// template <int b, int V>
// struct EVAL <b, LIT<V> > {
//     enum {RET = V};
// };

// template <int b , class L, class R>
// struct EVAL <b, ADD<L,R> > {
//    enum { RET = EVAL<b,L>::RET  +  EVAL<b,R>::RET } ;
// };