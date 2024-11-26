#include <array>
#include <functional>
#include <iostream>
#include <string>

constexpr std::size_t TABLESIZE{10};
constexpr std::hash<std::string> hasher;

class Hashmap
{
public:
  std::string get(std::string key) { return "hey"; }
  void set(std::string key, std::string value)
  {
    const int hash = hasher(key);
    std::cout << static_cast<std::size_t>(-1);
    const std::size_t hashIndex = static_cast<std::size_t>(hash) % TABLESIZE; // TODO 
    m_table.at(hashIndex) = value;
    return;
  }
  void print()
  {
    std::cout << "{" << '\n';
    for (auto value : m_table)
    {
      if (!value.empty())
      {
        std::cout << "   " << value << ":" << "" << '\n';
      }
    }
    std::cout << "}" << '\n';
  }

private:
  std::array<std::string, TABLESIZE> m_table{};
};

int main()
{
  Hashmap myHash{};
  myHash.set("key1", "value1");
  myHash.set("key2", "value2");
  myHash.print();
  return EXIT_SUCCESS;
}