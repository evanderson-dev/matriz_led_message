#ifndef FONT_H
#define FONT_H

#include <stdint.h>

// Total de caracteres (26 letras + 10 números + 1 espaço = 37)
#define FONT_CHAR_COUNT 38

// Mapa de bits para cada caractere (5x5)
extern const uint8_t font[FONT_CHAR_COUNT][25];

// Função para obter o índice de um caractere no array font
int getFontIndex(char c);

#endif