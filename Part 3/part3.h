#include <stdexcept>

template <int LOWER, int UPPER>
struct BOUNDS{
    enum{
        lower = LOWER,
        upper = UPPER
    };
};

template <class bound, int id>
struct VAR { 
    static constexpr int eval(int var_variable[]){
        if (var_variable[id]>bound::upper || var_variable[id]<bound::lower){
            throw std::invalid_argument("Variable is outside bounds.");
        }
        return var_variable[id];
    };
    enum{
        lower = bound::lower,
        upper = bound::upper
    };
};

template <int V>
struct LIT {
    static constexpr int eval(int var_variable[]){
        return V;
    }
    enum{
        lower = V,
        upper = V
    };
};

template <class L, class R>
struct ADD {
    static constexpr int eval(int var_variable[]){
      return L::eval(var_variable) + R::eval(var_variable);
    };
    enum{
      lower = L::lower + R::lower,
      upper = L::upper + R::upper
    };
};

template <class L, class R>
struct SUB {
    static constexpr int eval(int var_variable[]){
        return L::eval(var_variable) - R::eval(var_variable);
    };
    enum{
      lower = L::lower - R::lower,
      upper = L::upper - R::upper
    };
};

template <class L, class R>
struct MUL {
    static constexpr int eval(int var_variable[]){
        return L::eval(var_variable) * R::eval(var_variable);
    };
    enum{
      lower = L::lower * R::lower,
      upper = L::upper * R::upper
    };
};

template <class L, class R>
struct DIV {
    static constexpr int eval(int var_variable[]){
        int right = R::eval(var_variable);
        if (right == 0){
            throw std::invalid_argument("Divide By Zero");
        }
        return L::eval(var_variable) / right;
    };
    enum{
        lower = L::lower / R::upper,
        upper = L::upper / R::lower
    };
};