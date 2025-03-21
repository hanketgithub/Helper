#include <cstdio>
#include <cstdint>


void print_binary(const char *label, uint8_t *data, uint32_t size)
{
  const int bytes_per_line = 16;

  printf("%s, size = %u\n", label, size);

  for (uint32_t offset = 0; offset < size; offset += bytes_per_line) {
    printf("%08x  ", offset);

    int cur_line_bytes = (size - offset < bytes_per_line) ? (size - offset) : bytes_per_line;

    for (int i = 0; i < cur_line_bytes; ++i) {
      printf("%02x ", data[offset + i]);
      if (i == 7) printf(" ");  // extran space after 8 byte
    }

    // add space to align
    for (int i = cur_line_bytes; i < bytes_per_line; ++i) {
      printf("   ");
      if (i == 7) printf(" ");
    }

    // ASCII section
    printf(" |");
    for (int i = 0; i < cur_line_bytes; ++i) {
      unsigned char c = data[offset + i];
      printf("%c", (c >= 32 && c <= 126) ? c : '.');
    }
    printf("|\n");
  }
}
