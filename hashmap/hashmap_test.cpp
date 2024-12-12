#include <iostream>
#include "../simple_test.h"
#include "./hashmap.h"

static void overwrite_key()
{
    Hashmap myHash{1};
    myHash.set("key", "value1");
    myHash.set("key", "value2");
    ASSERT_EQ(myHash.get("key"), "value2");
}

static void keys_share_hash()
{
    Hashmap myHash{1}; // Size of 1 forces keys to share hash
    myHash.set("key1", "value1");
    myHash.set("key2", "value2");
    ASSERT_EQ(myHash.get("key1"), "value1");
    ASSERT_EQ(myHash.get("key2"), "value2");
}


int main()
{
    ADD_TEST("can overwrite keys", overwrite_key);
    ADD_TEST("handles keys that share a hash", keys_share_hash);
    RUN_ALL_TESTS();

    return EXIT_SUCCESS;
}