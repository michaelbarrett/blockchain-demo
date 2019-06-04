#include <iostream>
#include <string>

class Block {
 private:
  int index;
  std::string hash;
  std::string prevHash;
  int timeStamp;
  std::string data;

 public:
  Block(int i, std::string h, std::string ph, int ts, std::string d);
  std::string SHA256(std::string data);
  std::string string_to_hex(const std::string& input);
  void print();
};
