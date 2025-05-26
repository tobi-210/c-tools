#pragma once
#include <stdint.h>

void say_hello();

int32_t readtext(const char *text, int32_t *count);

int32_t add(int32_t a, int32_t b);

int32_t subtract(int32_t a, int32_t b);

int32_t multiply(int32_t a, int32_t b);

float divide(float a, float b);

void clear_terminal();

int random_number();