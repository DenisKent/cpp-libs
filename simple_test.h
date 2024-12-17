#ifndef SIMPLE_TEST_H
#define SIMPLE_TEST_H

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <sstream>
#include <optional>

const std::string red{"\033[31m"};
const std::string green{"\033[32m"};
const std::string blue{"\033[34m"};

class SimpleTest
{
public:
    using TestFunc = std::function<void()>;

    static void add_test(const std::string &name, TestFunc func)
    {
        get_tests().push_back({name, func});
    }

    static void run_all()
    {
        int passed = 0;
        int failed = 0;

        for (const auto &[name, func] : get_tests())
        {
            try
            {
                func();
                std::cout << green << "[PASS] " << name << "\n";
                passed++;
            }
            catch (const std::exception &e)
            {
                std::cerr << red << "[FAIL] " << name << "\n"
                          << e.what() << "\n";
                failed++;
            }
            catch (...)
            {
                std::cerr << red << "[FAIL] " << name << ": Unknown error\n";
                failed++;
            }
        }

        std::cout << blue << "\nTests run: " << (passed + failed) << ", Passed: " << passed << ", Failed: " << failed << "\n";
    }

private:
    using Test = std::pair<std::string, TestFunc>;

    static std::vector<Test> &get_tests()
    {
        static std::vector<Test> tests;
        return tests;
    }
};

// Helper to check if a type has operator<<
template <typename T, typename = void>
struct has_ostream_operator : std::false_type {};

template <typename T>
struct has_ostream_operator<T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T>())>>
    : std::true_type {};

template <typename T>
std::string to_string_helper(const T &value)
{
    if constexpr (std::is_arithmetic_v<T>)
    {
        return std::to_string(value); // For numeric types
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        return value; // For std::string
    }
    else if constexpr (has_ostream_operator<T>::value)
    {
        std::ostringstream oss;
        oss << value; // For types that can be streamed to ostream
        return oss.str();
    }
    else if constexpr (std::is_same_v<T, std::nullopt_t>)
    {
        return "nullopt"; // Handle std::nullopt specifically
    }
    else
    {
        return "[Unsupported Type]"; // Fallback for unsupported types
    }
}

#define ASSERT_TRUE(condition) \
    if (!(condition))          \
    throw std::runtime_error("Assertion failed: " #condition)

#define ASSERT_EQ(actual, expected) \
    if ((expected) != (actual))     \
    throw std::runtime_error("Assertion failed: " #expected " == " #actual "\nRecieved: " + to_string_helper(expected) + " == " + to_string_helper(actual))

#define ADD_TEST(name, func) \
    SimpleTest::add_test(name, func)

#define RUN_ALL_TESTS() \
    SimpleTest::run_all()

#endif // SIMPLE_TEST_H