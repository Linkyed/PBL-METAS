#ifndef DISPLAY_CONTROLER_H
#define DISPLAY_CONTROLER_H

#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#define LW_BRIDGE_BASE 0xFF200000
#define LW_BRIDGE_SPAN 0x00005000
#define HEX5_BASE 0x10
#define HEX4_BASE 0x20
#define HEX3_BASE 0x30
#define HEX2_BASE 0x40
#define HEX1_BASE 0x50
#define HEX0_BASE 0x60

extern volatile int *HEX0_BASE_ptr, *HEX1_BASE_ptr, *HEX2_BASE_ptr, *HEX3_BASE_ptr, *HEX4_BASE_ptr, *HEX5_BASE_ptr;
extern int fd = -1;
extern void *LW_virtual;

int numbers(int c) {
    switch (c) {
        case 1: return 0b11111001;
        case 2: return 0b10100100;
        case 3: return 0b10110000;
        case 4: return 0b10011001;
        case 5: return 0b10010010;
        case 6: return 0b10000010;
        case 7: return 0b11111000;
        case 8: return 0b10000000;
        case 9: return 0b10010000;
    }
}

int open_display_device();

void write_number_display(int display_digit, int number);

void close_display_device();

#endif // DRAW_SCREEN_H
