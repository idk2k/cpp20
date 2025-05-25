#include <iostream>

class Value
{
private:
    long id;

public:
    constexpr Value(long i) noexcept
        : id{i}
    {
    }

    // equality operators
    [[nodiscard]] friend constexpr bool operator==(const Value &lhs, const Value &rhs) noexcept
    {
        return lhs.id == rhs.id;
    }

    // [[nodiscard]] friend constexpr bool operator!=(const Value &lhs, const Value &rhs) noexcept
    // {
    //     return !(lhs == rhs);
    // }

    // relational operators
    [[nodiscard]] friend constexpr bool operator<(const Value &lhs, const Value &rhs) noexcept
    {
        return lhs.id < rhs.id;
    }

    [[nodiscard]] friend constexpr bool operator<=(const Value &lhs, const Value &rhs) noexcept
    {
        return !(rhs < lhs);
    }
    [[nodiscard]] friend constexpr bool operator>(const Value &lhs, const Value &rhs) noexcept
    {
        return rhs < lhs;
    }

    [[nodiscard]] friend constexpr bool operator>=(const Value &lhs, const Value &rhs) noexcept
    {
        return !(lhs < rhs);
    }
};

int main()
{
    std::cout << "hello world!" << std::endl;
    Value v1{5}, v2{9};
    std::cout << "v1 < v2: " << (v1 < v2) << std::endl;
    std::cout << "v1 > v2: " << (v1 > v2) << std::endl;
    std::cout << "v1 == v2: " << (v1 == v2) << std::endl;
    std::cout << "v1 != v2: " << (v1 != v2) << std::endl;
    return 0;
} 