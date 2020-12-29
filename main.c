#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "Usage: <integer>\n");
    exit(1);
  }

  int validBits[4] = {8, 16, 32, 64};
  int input = 0;
  char *inputStr = (char *)malloc(sizeof(char) * strlen(argv[1]));
  int output = 0;

  sscanf(argv[1], "%d", &input);
  sprintf(inputStr, "%d", input);

  if (strcmp(inputStr, argv[1]) != 0) {
    fprintf(stderr, "Input changed during int2string convertion!\n");
    fprintf(stderr, "Input was probably not an integer.");
    exit(1);
  }

  for (int x = 0; x < 4; x++) {
    if (validBits[x] == 8) {
      output = (uint8_t)input;
    } else if (validBits[x] == 16) {
      output = (uint16_t)input;
    } else if (validBits[x] == 32) {
      output = (uint32_t)input;
    } else if (validBits[x] == 64) {
      output = (uint64_t)input;
    }

    printf("The %dbit value of %d is: %d\n", validBits[x], input, output);
  }
}
