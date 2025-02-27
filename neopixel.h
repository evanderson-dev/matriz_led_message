#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include "pico/stdlib.h"

#define LED_COUNT 25
#define LED_PIN 7

// Estrutura para um pixel GRB
typedef struct {
    uint8_t G, R, B;
} pixel_t;

typedef pixel_t npLED_t;

// Funções públicas
void npInit(uint pin);
void npSetLED(uint index, uint8_t r, uint8_t g, uint8_t b);
void npClear(void);
void npWrite(void);
int getLedIndex(int row, int col);

#endif