#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
uint8_t set_sprite_pixel_color(uint16_t address, uint8_t R, uint8_t G, uint8_t B)
{
    unsigned char command[6];

    command[0] = 3;                    // Command for instrucao_wsm
    command[1] = (address >> 6);       // Higher 8 bits of 14-bit address
    command[2] = (address & 0b111111); // Lower 6 bits of address and r
    command[3] = R & 0b111;
    command[4] = G & 0b111; // g value
    command[5] = B & 0b111; // b value

    printf("adress=%d", (command[1] << 6) | (command[2]));

    return 1;
}

int main() {
    set_sprite_pixel_color(399, 0, 0, 0);
    return 0;
}
