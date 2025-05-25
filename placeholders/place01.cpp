#include <iostream>
#include <vector>

void printColl(const auto& coll) {
    for(const auto& elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

template<typename T>
void equivalentPrintColl(const T& coll) {
    for(const auto& elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main() {
    // auto printColl = [](const auto& coll) {
    //     for(const auto& elem : coll) {
    //         std::cout << elem << ' ';
    //     }
    //     std::cout << '\n';
    // };
    
    std::vector coll{1, 2, 3, 4, 5};

    printColl(coll);
    printColl(std::string{"hello"});
    equivalentPrintColl(std::vector{5,6,7});

    return 0;
}