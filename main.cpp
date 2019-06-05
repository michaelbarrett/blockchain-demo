#include <chrono>
#include <thread>
#include "blockchain.h"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  Blockchain *b = new Blockchain();

  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  (*b).generateNextBlock("alpha");
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  (*b).generateNextBlock("beta");
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  (*b).generateNextBlock("gamma");

  b->print();
  
  std::cout << "Press ENTER to continue..." << std::endl;
  std::cin.ignore(1);
}
