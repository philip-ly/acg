#include <stdexcept>

template <int LOWER, int UPPER>
struct BOUNDS{
    enum{
        lower = LOWER,
        upper = UPPER
    };
};

// Min and Max Functions for internal use.
template <int X, int Y>
struct MIN {
    enum{
        result = ((X<Y) ? X: Y)
    };
};

template <int X, int Y>
struct MAX {
    enum{
        result = ((X>Y) ? X: Y)
    };
};

template <class bound>
struct VAR { 
    static constexpr int eval(int var_variable){
        if (var_variable>bound::upper || var_variable<bound::lower){
            throw std::invalid_argument("Variable is outside bounds.");
        }
        return var_variable;
    };
    enum{
        lower = bound::lower,
        upper = bound::upper
    };
};

template <int V>
struct LIT {
    static constexpr int eval(int var_variable){
        return V;
    }
    enum{
        lower = V,
        upper = V
    };
};

template <class L, class R>
struct ADD {
    static constexpr int eval(int var_variable){
        return L::eval(var_variable) + R::eval(var_variable);
    };
    enum{
        lower = L::lower + R::lower,
        upper = L::upper + R::upper
    };
};

template <class L, class R>
struct SUB {
    static constexpr int eval(int var_variable){
        return L::eval(var_variable) - R::eval(var_variable);
    };
    enum{
        lower = L::lower - R::lower,
        upper = L::upper - R::upper
    };
};

template <class L, class R>
struct MUL {
    static constexpr int eval(int var_variable){
        return L::eval(var_variable) * R::eval(var_variable);
    };
    enum{
        lower = MIN<
                    MIN<L::lower*R::lower, L::lower*R::upper>::result,
                    MIN<L::upper*R::lower, L::upper*R::upper>::result
                >::result,
        upper = MAX<
                    MAX<L::lower*R::lower, L::lower*R::upper>::result,
                    MAX<L::upper*R::lower, L::upper*R::upper>::result
                >::result
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
    enum{
        lower = MIN<
                    MIN<L::lower/R::lower, L::lower/R::upper>::result,
                    MIN<L::upper/R::lower, L::upper/R::upper>::result
                >::result,
        upper = MAX<
                    MAX<L::lower/R::lower, L::lower/R::upper>::result,
                    MAX<L::upper/R::lower, L::upper/R::upper>::result
                >::result
    };
};