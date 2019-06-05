#include <string>
#include "block.h"

Block::Block(int i, std::string h, std::string ph, int ts, std::string d) :
  index(i), hash(h), prevHash(ph), timeStamp(ts), data(d) {
  //set up hash
}

//make a default block for initializing the array
Block::Block() : index(-1), hash("<hash>"), prevHash("<prevhash>"),
		 timeStamp(-1), data("<data>") {}

std::string Block::print() {
  std::string s = "";
  s.append("Block ");
  /*    ("Block ") + std::string(index) + std::string(", hash = ")
    + hash + std::string(", prevHash = ") + prevHash
    + std::string(", timeStamp = ") + std::string(timeStamp)
    + std::string(", data = ") + data + std::endl;*/
  return s;
}
