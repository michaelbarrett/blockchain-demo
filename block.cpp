#include "block.h"
#include "cryptopp/sha.h"
#include "cryptopp/filters.h"
#include "cryptopp/base64.h"
#include "cryptopp/cryptlib.h"
#include "cryptopp/hex.h"

Block::Block(int i, std::string h, std::string ph, int ts, std::string d) :
  index(i), hash(h), prevHash(ph), timeStamp(ts), data(d) {}

std::string Block::string_to_hex(const std::string& input) {
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

std::string Block::SHA256(std::string data) {
  CryptoPP::byte const* pbData = (CryptoPP::byte*)data.data();
  unsigned int nDataLen = data.length();
  CryptoPP::byte abDigest[CryptoPP::SHA256::DIGESTSIZE];
  CryptoPP::SHA256().CalculateDigest(abDigest, pbData, nDataLen);
  return std::string((char*)abDigest, CryptoPP::SHA256::DIGESTSIZE);
}

void Block::print() {
  std::cout << "Block " << index << ", hash = " << hash << ", prevHash = " << prevHash <<
    ", timeStamp = " << timeStamp << ", data = " << data << std::endl;
  std::cout << string_to_hex(SHA256("abc")) << std::endl;
}
