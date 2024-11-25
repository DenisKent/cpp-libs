#include <functional>
#include <iostream>
#include <string>

const int TABLESIZE = 10;
const std::hash<std::string> hasher;

int main() {
  // std::cout << "Hello world";
  // std::cout << __cplusplus;
  std::string s{"hello world"};
  const int hash = hasher(s);
  const int hashIndex = hash % TABLESIZE;
  std::cout << hashIndex;
  return EXIT_SUCCESS;
}