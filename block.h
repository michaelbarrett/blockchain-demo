#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "constants.h"

class Block {
 private:
  int index;
  std::string hash;
  std::string prevHash;
  unsigned long long int timeStamp;
  std::string data;

 public:
  Block(int i, std::string h, std::string ph, int ts, std::string d);
  Block();
  void generateNextBlock(std::string blockData);
  std::string print();

  friend class Blockchain;
};
