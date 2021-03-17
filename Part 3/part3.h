#include <stdexcept>

//Bounds
//Lower bound must be less than upper bound.
template <int LOWER, int UPPER>
struct BOUNDS{
    static_assert(LOWER<=UPPER);
    enum{
        lower = LOWER,
        upper = UPPER
    };
};

//Min of two ints
template <int X, int Y>
struct MIN {
    enum{
        result = ((X<Y) ? X: Y)
    };
};

//Max of two ints
template <int X, int Y>
struct MAX {
    enum{
        result = ((X>Y) ? X: Y)
    };
};

//IF X is 0, return value Y, else return value X.
template <int X, int Y>
struct IFZERO {
    enum{
        result = ((X==0) ? Y: X)
    };
};

//Variable, with bounds.
template <class bound>
struct VAR { 
    static constexpr int eval(int var_variable[], int *counter){
        if (var_variable[*counter]>bound::upper || var_variable[*counter]<bound::lower){
            throw std::invalid_argument("Variable is outside bounds.");
        }
        return var_variable[*counter++];
    };
    enum{
        lower = bound::lower,
        upper = bound::upper
    };
};

//Literal Integer
template <int V>
struct LIT {
    static constexpr int eval(int var_variable[], int *counter){
        return V;
    }
    enum{
        lower = V,
        upper = V
    };
};

//Addition
template <class L, class R>
struct ADD {
    static constexpr int eval(int var_variable[], int *counter){
      return L::eval(var_variable, counter) + R::eval(var_variable, counter);
    };
    enum{
      lower = L::lower + R::lower,
      upper = L::upper + R::upper
    };
};

//Subtraction
template <class L, class R>
struct SUB {
    static constexpr int eval(int var_variable[], int *counter){
        return L::eval(var_variable, counter) - R::eval(var_variable, counter);
    };
    enum{
      lower = L::lower - R::lower,
      upper = L::upper - R::upper
    };
};

//Multiplication
//Calculates all combinations and takes the minumum/maximum.
template <class L, class R>
struct MUL {
    static constexpr int eval(int var_variable[], int *counter){
        return L::eval(var_variable, counter) * R::eval(var_variable, counter);
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

//Division
//If a bound crosses 0, 0 is ignored.
//If a bound is 0, the integer value that excludes 0 is taken. I.e [0,10] -> [1,10], [-10,0] -> [-10,-1]
//If both bounds are 0, an error is shown.
//Otherwise, tries all combinations, taking the min/max for lower and upper bounds respectively.
template <class L, class R>
struct DIV {
    static_assert((R::lower != 0 || R::upper !=0), "The bounds of a division cannot both be 0.");
    static constexpr int eval(int var_variable[], int *counter){
        int right = R::eval(var_variable, counter);
        if (right == 0){
            throw std::invalid_argument("Divide By Zero");
        }
        return L::eval(var_variable) / right;
    };
    enum{
        lower = MIN<
                    MIN<L::lower/IFZERO<R::lower,1>::result, L::lower/IFZERO<R::upper,-1>::result>::result,
                    MIN<L::upper/IFZERO<R::lower,1>::result, L::upper/IFZERO<R::upper,-1>::result>::result
                >::result,
        upper = MAX<
                    MAX<L::lower/IFZERO<R::lower,1>::result, L::lower/IFZERO<R::upper,-1>::result>::result,
                    MAX<L::upper/IFZERO<R::lower,1>::result, L::upper/IFZERO<R::upper,-1>::result>::result
                >::result
    };
};