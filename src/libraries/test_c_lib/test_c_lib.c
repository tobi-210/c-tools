#include "include/test_c_lib.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h> 

void say_hello() {
  printf("Say ");
  printf("hello!\n");
}

int32_t countchar(const char *text, int32_t *count) {
  int32_t i = 0;
  int32_t chars = 0;
  while (text[i] != '\0') {
    if (text[i] != ' ') { // Count only non space characters
      chars++;
    }
    i++;
  }

  *count = chars - 1; // Subtract 1 so that the newline character is not counted

  return *count;

}

  int32_t countwords(const char *text, int32_t *count) {

    int32_t i = 0;
    int32_t space = 0;
    while(text[i] != '\0') {
      if(text[i] == ' ') {

        space++;
        
      }

      i++;
    }

  *count = space + 1;

  return *count;
  }


int32_t add(int32_t a, int32_t b) {
  return a + b;
}

int32_t subtract(int32_t a, int32_t b) {
  return a - b;
}
int32_t multiply(int32_t a, int32_t b) {
  return a * b;
}

float divide(float a, float b) {
  return a / b;
}

void clear_terminal() {
  // clear terminal, only works on posix compatible terms
  sleep(3);
  printf("\e[1;1H\e[2J");
}

int random_number() {
    // Seed nur einmal initialisieren (am besten im main, nicht hier)
    return (rand() % 100) + 1;  // ergibt Zahl zwischen 1 und 100
}

