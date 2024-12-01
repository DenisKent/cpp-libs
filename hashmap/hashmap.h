#include <string>
#include <array>

class Hashmap
{
public:
  Hashmap();
  ~Hashmap();

  std::string get(std::string key);
  void set(std::string key, std::string value);
  void print();

private:
  struct Node
  {
    std::string key{};
    std::string value{};
  };
  static constexpr std::size_t TABLESIZE{10};
  std::array<Node *, TABLESIZE> m_table{};
  std::size_t getKeyHashIndex(const std::string &key);
};