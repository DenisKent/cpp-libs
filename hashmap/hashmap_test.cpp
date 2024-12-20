#include <iostream>
#include <unordered_map>
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
    intHash.set("one",1);
    ASSERT_EQ(intHash.get("one"),1);
    Hashmap<std::string> stringHash{1};
    stringHash.set("two","two");
    ASSERT_EQ(stringHash.get("two"),"two");
}

static void similar_to_unordered_map()
{
    std::unordered_map<int,int> map{1};
    int map_key = 1;
    map.insert({map_key, 2});
    int result = 0;
    if(map.find(map_key) != map.end()){
        result = map[map_key];
    }
    ASSERT_EQ(result, 2);
}

int main()
{
    ADD_TEST("can overwrite keys", overwrite_key);
    ADD_TEST("handles keys that share a hash", keys_share_hash);
    ADD_TEST("handles multiple hash value types", hash_types);
    ADD_TEST("similar usage to an unordered map", similar_to_unordered_map);
    RUN_ALL_TESTS();

    return EXIT_SUCCESS;
}