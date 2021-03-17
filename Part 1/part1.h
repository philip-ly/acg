#include <stdexcept>
//Variable
struct VAR { 
  static constexpr int eval(int var_variable){
    return var_variable;
  };  
};

//Literal Integer, V
template <int V>
struct LIT {
  static constexpr int eval(int var_variable){
    return V;
  };
};

//Addition L + R
template <class L, class R>
struct ADD {
    static constexpr int eval(int var_variable){
        return L::eval(var_variable) + R::eval(var_variable);
    };
};

//Subtraction L - R
template <class L, class R>
struct SUB {
    static constexpr int eval(int var_variable){
        return L::eval(var_variable) - R::eval(var_variable);
    };
};

//Multiplication L * R
template <class L, class R>
struct MUL {
    static constexpr int eval(int var_variable){
        return L::eval(var_variable) * R::eval(var_variable);
    };
};

//Division L / R, division by 0 throws error.
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