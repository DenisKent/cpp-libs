#include <iostream>
#include "../simple_test.h"
#include "./hashmap.h"

static void overwrite_key()
{
    Hashmap<std::string> myHash{10};
    myHash.set("key", "value1");
    myHash.set("key", "value2");
    ASSERT_EQ(myHash.get("key").value_or(""),"value2");
}

static void keys_share_hash()
{
    Hashmap<std::string> myHash{1}; // Size of 1 forces keys to share hash
    myHash.set("key1", "value1");
    myHash.set("key2", "value2");
    ASSERT_EQ(myHash.get("key1").value_or(""), "value1");
    ASSERT_EQ(myHash.get("key2").value_or(""), "value2");
}

static void hash_types()
{
    Hashmap<int> intHash{1};
    intHash.set("two",2);
    ASSERT_EQ(intHash.get("two"),2);
}


int main()
{
    ADD_TEST("can overwrite keys", overwrite_key);
    ADD_TEST("handles keys that share a hash", keys_share_hash);
    RUN_ALL_TESTS();

    return EXIT_SUCCESS;
}