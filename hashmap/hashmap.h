#include <string>
#include <array>
#include <vector>
#include <optional>

class Hashmap
{
public:
  Hashmap(std::size_t tableSize) : m_tableSize{tableSize}, m_table{tableSize} {};
  ~Hashmap()
  {
    for (auto &row : m_table)
    {
      delete row;
    }
  };

  std::optional<std::string> get(std::string key);
  void set(std::string key, std::string value);
  void print();

private:
  struct Node
  {
    std::string key{};
    std::string value{};
  };
  const std::size_t m_tableSize{};
  std::vector<std::vector<Node> *> m_table{m_tableSize};
  std::size_t getKeyHashIndex(const std::string &key);
};