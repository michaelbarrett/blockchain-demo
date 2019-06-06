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
  std::string SHA256(std::string data) const;
  std::string string_to_hex(const std::string& input) const;
  std::string calculateHash(int i, std::string ph, int ts, std::string d) const;
  void generateNextBlock(std::string blockData);
  bool isValidNewBlock(Block newBlock, Block prevBlock) const;
  bool isValidBlockStructure(Block b) const;
  void print() const;
};
