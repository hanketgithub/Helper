#include <iostream>
#include <cstdint>

#include "helper.h"

using namespace std;

uint8_t InfoFrame[] = {
  0x82, 0x02, 0x0D, 0xE4
};

int main(int argc, char *argv[]) {

  print_binary("AVI InfoFrame", InfoFrame, sizeof(InfoFrame));

  return 0;
}
