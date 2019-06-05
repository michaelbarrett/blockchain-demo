#include <string>
#include <sstream>
#include "block.h"

Block::Block(int i, std::string h, std::string ph, int ts, std::string d) :
  index(i), hash(h), prevHash(ph), timeStamp(ts), data(d) {
  //set up hash
}

//make a default block for initializing the array
Block::Block() : index(-1), hash("<hash>"), prevHash("<prevhash>"),
		 timeStamp(-1), data("<data>") {}

std::string Block::print() {
  std::stringstream ss;
  ss << "Block " << index << ", hash = " << hash << ", prevHash = " << prevHash
     << ", timeStamp = " << timeStamp << ", data = " << data << std::endl;
  std::string s = ss.str();
  return s;
}
