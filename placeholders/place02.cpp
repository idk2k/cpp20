#include <iostream>

class MyType {
public:
    void assign(const auto& newVal);
};

// that declaration is equivalent to 

// class MyType {
// public:
//     template<typename T>
//     void assign(const T& newVal);
// };


int main() {


    return 0;
}