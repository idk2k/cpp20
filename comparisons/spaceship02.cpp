#include <iostream>
#include <compare>

class Value
{
private:
    long id;

public:
    constexpr Value(long i) noexcept
        : id{i}
    {
    }

    bool operator==(const Value &rhs) const
    {
        return id == rhs.id;
    }

    // Return type is: strong orderings, or weak ordering, or partial ordering;
    auto operator<=>(const Value &rhs) const
    {
        return id <=> rhs.id;
    }
};

int main()
{
    std::cout << "hello world!" << std::endl;
    Value v1{5}, v2{9};
    std::cout << (0 > v1 <=> v2) << std::endl;
    return 0;
}