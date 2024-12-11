#include "./hashmap.h"
#include <iostream>
#include "../simple_test.h"

static void test_overwrite_key()
{
    Hashmap myHash{};
    myHash.set("key", "value1");
    myHash.set("key", "value2");
    ASSERT_EQ(myHash.get("key"), "value2");
}

int main()
{
    ADD_TEST("can overwrite keys", test_overwrite_key);
    RUN_ALL_TESTS();

    return EXIT_SUCCESS;
}