#include <iostream>
#include <compare>

/*

1. strong:
 - std::strong_ordering::equal
    (also available as std::strong_ordering::equivalent)
 - std::strong_ordering::greater
 - std::strong_ordering::less

2. weak:
- std::weak_ordering::equivalent
- std::weak_ordering::greater
- std::weak_ordering::less

3. partial:
- std::partial_ordering::equivalent
- std::partial_ordering::greater
- std::partial_ordering::less
- std::partial_ordering::unordered

*/

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

    std::cout << (0 < v1 <=> v2) << std::endl;
    return 0;
}