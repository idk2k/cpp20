#include <iostream>
#include <vector>
#include <algorithm>

bool lessByNameFunc(const auto& c1, const auto& c2) {
    return c1.length() < c2.length();
}

// parameters can be a parameter pack
void foo(auto... args);

// and this is equivalent to
template<typename... Types>
void foo(Types... args);

int main() {
    std::vector<std::string> persons{"123", "123"};
    // need to specify types of parameters
    std::sort(persons.begin(), persons.end(), lessByNameFunc<std::string, std::string>);
    
    // but with lambda there is no need
    auto lmbdLessByNameFunc = [](const auto& c1, const auto& c2) {
        return c1.length() < c2.length();
    };
    std::sort(persons.begin(), persons.end(), lmbdLessByNameFunc);
    // OK
    

    // ---- to pass type for lambda is pass type to its operator()

    auto test = [](const auto& ca) {
        std::cout << ca;
    };

    test.operator()<int>(5);
    
    // last note: using decltype(auto) is not allowed!
    return 0;
}