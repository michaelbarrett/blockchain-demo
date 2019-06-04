#include "block.h"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  Block *b = new Block(0, "1", "2", 3, "4");
  b->print();
  
  std::cout << "Press ENTER to continue..." << std::endl;
  std::cin.ignore(1);
}
