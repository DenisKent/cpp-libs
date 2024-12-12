#ifndef SIMPLE_TEST_H
#define SIMPLE_TEST_H

#include <iostream>
#include <string>
#include <functional>
#include <vector>

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
                std::cerr << red << "[FAIL] " << name << "\n" << e.what() << "\n";
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

#define ASSERT_TRUE(condition) \
    if (!(condition))          \
    throw std::runtime_error("Assertion failed: " #condition)

#define ASSERT_EQ(actual, expected) \
    if ((expected) != (actual))     \
    throw std::runtime_error("Assertion failed: " #expected " == " #actual "\nRecieved: " + static_cast<std::string>(expected) + " == " + static_cast<std::string>(actual))

#define ADD_TEST(name, func) \
    SimpleTest::add_test(name, func)

#define RUN_ALL_TESTS() \
    SimpleTest::run_all()

#endif // SIMPLE_TEST_H