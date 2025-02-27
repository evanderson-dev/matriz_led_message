#include <stdio.h>
#include <string.h>
#include "neopixel.h"
#include "font.h"

void displayWord(const char* word, int word_length, int offset) {
    npClear();
    for (int i = 0; i < word_length; i++) {
        int letter_index = getFontIndex(word[i]);
        int letter_offset = offset + (i * 6);
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                int display_col = col + letter_offset;
                if (display_col >= 0 && display_col < 5) {
                    int led_index = getLedIndex(row, display_col);
                    if (font[letter_index][row * 5 + col] == 1) {
                        npSetLED(led_index, 255, 0, 0); // Vermelho
                    }
                }
            }
        }
    }
    npWrite();
}

int main() {
    stdio_init_all();
    npInit(LED_PIN);
    npClear();
    npWrite();

    const char* word = "EU TE AMO STHEFANI";
    const char* word2 = "<";
    int word_length = strlen(word);
    int word2_length = strlen(word2);
    int total_width = word_length * 6 - 1;

    while (true) {
        for (int offset = 4; offset >= -total_width; offset--) {
            displayWord(word, word_length, offset);
            sleep_ms(100);
        }

        // Após a frase, pisca o coração 3 vezes no centro
        for (int i = 0; i < 3; i++) {
            // Coração ligado (vermelho)
            displayWord(word2, word2_length, 0); // Offset 0 para centralizar
            sleep_ms(250); // Tempo ligado (250ms)

            // Coração desligado (fundo azul)
            npClear(); // Limpa a matriz, todos os LEDs ficam azuis
            npWrite();
            sleep_ms(250); // Tempo desligado (250ms)
        }
    }
}