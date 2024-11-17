#ifndef FIXUPS_HPP
#define FIXUPS_HPP
// Macro to convert input to string
#define toString(input) #input
// Comparision Funciton
#define FUNCTION(name, operation)          \
    int name(const int& a, const int& b) { \
        return (a operation b) ? a : b;    \
    }
#define INF 10000

// #define GET_MACRO(_1, _2, _3, NAME, ...) NAME
// #define Variable(...) GET_MACRO(__VA_ARGS__, Variable3, Variable2)(__VA_ARGS__)

// #define Variable2(type, name)
// #define Variable3(type, name, ...) type name = __VA_ARGS__
#define Variable(type, name, ...) __VA_OPT__(type name = __VA_ARGS__);

#define SOME_MACRO 42

#define DEBUG(message) log(__LINE__, __FILE__, message)
#define foreach(v, i) for (size_t i = 0; i < v.size(); ++i)
// for (size_t i = 0; i < V.size(); ++i)

// Undefine Variable macro to avoid redefinition errors
#endif // FIXUPS_HPP