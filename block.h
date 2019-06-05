#include <iostream>
#include <string>
#include "constants.h"

class Block {
 private:
  int index;
  std::string hash;
  std::string prevHash;
  int timeStamp;
  std::string data;

 public:
  Block(int i, std::string h, std::string ph, int ts, std::string d);
  Block();
  void print();
};
