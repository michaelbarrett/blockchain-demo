#include "blockchain.h"

Blockchain::Blockchain() {
  Block *genesisBlock = new Block(
				  0, "816534932c2b7154836da6afc367695e6337db8a921823784c14378abed4f7d7", "", std::time(nullptr), "my genesis block" );
  chain.push_back(*genesisBlock);
}

std::string Blockchain::string_to_hex(const std::string& input) const {
  static const char* const lut = "0123456789ABCDEF";
  size_t len = input.length();
  std::string output;
  output.reserve(2 * len);
  for (size_t i = 0; i < len; ++i) {
    const unsigned char c = input[i];
    output.push_back(lut[c >> 4]);
    output.push_back(lut[c & 15]);
  }
  return output;
}

std::string Blockchain::SHA256(std::string data) const {
  CryptoPP::byte const* pbData = (CryptoPP::byte*)data.data();
  unsigned int nDataLen = data.length();
  CryptoPP::byte abDigest[CryptoPP::SHA256::DIGESTSIZE];
  CryptoPP::SHA256().CalculateDigest(abDigest, pbData, nDataLen);
  return std::string((char*)abDigest, CryptoPP::SHA256::DIGESTSIZE);
}

//calculates hash
std::string Blockchain::calculateHash(int i, std::string ph, int ts, std::string d) const {
  std::stringstream ss;
  ss << i << ph << ts << d;
  std::string s = ss.str();
  return string_to_hex(SHA256(s));
}

//generates the next block with specified blockData and puts it into the chain
//with calculated hash
void Blockchain::generateNextBlock(std::string blockData) {
  Block *previousBlock = &(chain.back());
  int nextIndex = previousBlock->index + 1;
  int nextTimeStamp = std::time(nullptr);
  std::string nextHash = calculateHash(nextIndex, previousBlock->hash, nextTimeStamp, blockData);
  Block *nb = new Block(nextIndex, nextHash, previousBlock->hash, nextTimeStamp, blockData);
  chain.push_back(*nb);
}

//checks if new block is valid
bool Blockchain::isValidNewBlock(Block newBlock, Block prevBlock) const {
  if (newBlock.index - 1 != prevBlock.index) {
    std::cout << "block index invalid" << std::endl;
    return false;
  }
  else if (newBlock.prevHash != prevBlock.hash) {
    std::cout << "block prevHash invalid" << std::endl;
    return false;
  }
  else if (newBlock.hash != calculateHash(newBlock.index, newBlock.prevHash,
					  newBlock.timeStamp, newBlock.data)) {
    std::cout << "block hash recalculated to be invalid" << std::endl;
    return false;
  }
  return true;
}

/*Validates a whole chain. First, we check that the mysteryChain genesis block matches this genesisBlock. Then, we validate every consecutive block*/
bool Blockchain::isValidChain(std::vector<Block> mysteryChain) {
  //if genesis is not valid
  if ((mysteryChain[0].print) != (chain[0].print)) {
    return false;
  }
  for (int i = 1; i < mysteryChain.size(); i++) {
    if (!isValidNewBlock(mysteryChain[i], mysteryChain[i-1))) {
      return false;
    }
  }
  return true;
}

//if a longer chain is received from the node, we replace the current chain
void Blockchain::replaceChain(std::vector<Block> newChain) {
  if (isValidChain(newChain) && (newChain.size() > chain.size())) {
    std::cout << "Received blockchain is valid. Replacing current blockchain with received."
	      << std::endl;
    chain = newChain;
  }
}

/*const replaceChain = (newBlocks: Block[]) => {
    if (isValidChain(newBlocks) && newBlocks.length > getBlockchain().length) {
        console.log('Received blockchain is valid. Replacing current blockchain with received blockchain');
        blockchain = newBlocks;
        broadcastLatest();
    } else {
        console.log('Received blockchain invalid');
    }
    };*/

void Blockchain::print() const {
  //TODO: Print chain array
  std::cout << "Blockchain Array" << std::endl;
  for (std::vector<Block>::const_iterator it = chain.begin(); it != chain.end(); it++) {
    std::cout << (*it).print();
  }
  std::cout << "Blocks 1 & 0 Valid?" << std::endl;
  std::cout << isValidNewBlock(chain[1], chain[0]) << std::endl;
}
