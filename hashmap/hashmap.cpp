#include <iostream>
#include <string>
#include <optional>
#include "./hashmap.h"

constexpr std::hash<std::string> hasher;

/**
 * When we get, we must be aware of three states:
 * 1. nullptr
 * 2. Vector with value in it
 * 3. Vector without value in it
 */
std::optional<std::string> Hashmap::get(std::string key)
{
  const std::size_t hashIndex = getKeyHashIndex(key);
  std::vector<Node> *row = m_table.at(hashIndex);
  if (row == nullptr)
  {
    return std::nullopt;
  }

  for (auto &node : *row)
  {
    if (node.key == key)
    {
      return node.value;
    }
  }
  return std::nullopt;
};

/**
 * When we set, we have three scenarios:
 * 1. There is not a vector in place
 * 2. There is a vector in place and the key exists
 * 3. There is a vector in place and the key does not exist
 */
void Hashmap::set(std::string key, std::string value)
{
  const std::size_t hashIndex = getKeyHashIndex(key);
  std::vector<Node> *row = m_table.at(hashIndex);
  if (row == nullptr)
  {
    m_table.at(hashIndex) = new std::vector{Node{key, value}};
  }
  else
  {
    for (auto &node : *row)
    {
      if (node.key == key)
      {
        node.value = value;
        return;
      }
    }
    m_table.at(hashIndex)->push_back(Node{key, value});
  }
};

void Hashmap::print()
{
  std::cout << "{" << '\n';
  for (auto row : m_table)
  {
    if (row != nullptr)
    {
      for (auto const &node : *row)
      {
        std::cout << "   " << node.key << ":" << node.value << '\n';
      }
    }
  }
  std::cout << "}" << '\n';
};

std::size_t Hashmap::getKeyHashIndex(const std::string &key)
{
  const int hash = hasher(key);
  const std::size_t hashIndex = static_cast<std::size_t>(hash) % m_tableSize;
  return hashIndex;
};
