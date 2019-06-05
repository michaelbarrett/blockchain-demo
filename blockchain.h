#include <iostream>
#include <vector>
#include "block.h"
#include "cryptopp/sha.h"
#include "cryptopp/filters.h"
#include "cryptopp/base64.h"
#include "cryptopp/cryptlib.h"
#include "cryptopp/hex.h"

class Blockchain {
 private:
  std::vector<Block> chain;
 public:
  Blockchain();
  std::string SHA256(std::string data);
  std::string string_to_hex(const std::string& input);
  std::string calculateHash(int i, std::string ph, int ts, std::string d);
  void generateNextBlock(std::string blockData);
  void print() const;
};
