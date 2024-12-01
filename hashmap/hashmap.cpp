#include <iostream>
#include <string>
#include "./hashmap.h"

constexpr std::hash<std::string> hasher;

Hashmap::Hashmap() {
  //
};

Hashmap::~Hashmap()
{
  for (auto row : m_table)
  {
    delete row;
  }
}
std::string Hashmap::get(std::string key)
{
  const std::size_t hashIndex = getKeyHashIndex(key);
  Node *row = m_table.at(hashIndex);
  if (row == nullptr)
  {
    return "";
  }
  else
  {
    return row->value;
  }
};

void Hashmap::set(std::string key, std::string value)
{
  const std::size_t hashIndex = getKeyHashIndex(key);
  Node *row = m_table.at(hashIndex);
  if (row == nullptr)
  {
    m_table.at(hashIndex) = new Node{key, value};
  }
  else
  {
    m_table.at(hashIndex)->key = key;
    m_table.at(hashIndex)->value = value;
  }
};

void Hashmap::print()
{
  std::cout << "{" << '\n';
  for (auto row : m_table)
  {
    if (row != nullptr)
    {
      std::cout << "   " << row->key << ":" << row->value << '\n';
    }
  }
  std::cout << "}" << '\n';
};

std::size_t Hashmap::getKeyHashIndex(const std::string &key)
{
  const int hash = hasher(key);
  const std::size_t hashIndex = static_cast<std::size_t>(hash) % TABLESIZE;
  return hashIndex;
};

int main()
{
  Hashmap myHash{};
  myHash.set("key1", "value1");
  myHash.set("key2", "value2");
  myHash.set("key2", "value3");
  myHash.print();
  std::cout << myHash.get("key1") << '\n';
  std::cout << myHash.get("not_a_key1") << '\n';

  return EXIT_SUCCESS;
}