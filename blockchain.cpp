#include "blockchain.h"

Blockchain::Blockchain() {
  Block *genesisBlock = new Block(
				  0, "816534932c2b7154836da6afc367695e6337db8a921823784c14378abed4f7d7", "", 1465154705, "my genesis block!!" );
  chain.push_back(*genesisBlock);
}

std::string Blockchain::string_to_hex(const std::string& input) {
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

std::string Blockchain::SHA256(std::string data) {
  CryptoPP::byte const* pbData = (CryptoPP::byte*)data.data();
  unsigned int nDataLen = data.length();
  CryptoPP::byte abDigest[CryptoPP::SHA256::DIGESTSIZE];
  CryptoPP::SHA256().CalculateDigest(abDigest, pbData, nDataLen);
  return std::string((char*)abDigest, CryptoPP::SHA256::DIGESTSIZE);
}

std::string Blockchain::calculateHash(int i, std::string ph, int ts, std::string d) {
  (void)i;
  (void)ph;
  (void)ts;
  (void)d; //TODO: Formula
  return SHA256("abc");
}

void Blockchain::print() {
  //TODO: Print chain array
  std::cout << "Blockchain Array" << std::endl;
  std::cout << "Genesis Block: " << (*chain[0]).print() << std::endl;
}
