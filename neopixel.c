#include "neopixel.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2818b.pio.h"

npLED_t leds[LED_COUNT];
static PIO np_pio;
static uint sm;

void npInit(uint pin) {
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;
    sm = pio_claim_unused_sm(np_pio, false);
    if (sm < 0) {
        np_pio = pio1;
        sm = pio_claim_unused_sm(np_pio, true);
    }
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);
    npClear();
}

void npSetLED(uint index, uint8_t r, uint8_t g, uint8_t b) {
    if (index < LED_COUNT) {
        leds[index].R = r;
        leds[index].G = g;
        leds[index].B = b;
    }
}

void npClear(void) {
    for (uint i = 0; i < LED_COUNT; ++i)
        npSetLED(i, 0, 0, 255); // Azul por padrão
}

void npWrite(void) {
    for (uint i = 0; i < LED_COUNT; ++i) {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100);
}

int getLedIndex(int row, int col) {
    int base[] = {4, 5, 14, 15, 24};
    if (row % 2 == 0) { // Linhas pares: direita para esquerda
        return base[row] - col;
    } else { // Linhas ímpares: esquerda para direita
        return base[row] + col;
    }
}