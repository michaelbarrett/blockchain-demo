#include "blockchain.h"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  Blockchain *b = new Blockchain();
  (*b).print();
  
  std::cout << "Press ENTER to continue..." << std::endl;
  std::cin.ignore(1);
}
