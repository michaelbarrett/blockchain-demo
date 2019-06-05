#include <iostream>
#include <vector>
#include "constants.h"
#include "block.h"

class Blockchain {
 private:
  std::vector<Block> chain;
 public:
  Blockchain();
  std::string SHA256(std::string data);
  std::string string_to_hex(const std::string& input);
  std::string calculateHash(int i, std::string ph, int ts, std::string d);
  void print();
};
