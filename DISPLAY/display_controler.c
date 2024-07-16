#include "display_controler.h"

volatile int *HEX0_BASE_ptr, *HEX1_BASE_ptr, *HEX2_BASE_ptr, *HEX3_BASE_ptr, *HEX4_BASE_ptr, *HEX5_BASE_ptr;
int fd = -1;
void *LW_virtual;

int numbers(int c) {

}

int open_display_device() {
     if ((fd = open("/dev/mem", (O_RDWR | O_SYNC))) == -1) {
        printf("ERRO: não foi possível abrir \"/dev/mem\"...\n");
        return 0;
    }
    LW_virtual = mmap(NULL, LW_BRIDGE_SPAN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, LW_BRIDGE_BASE);
    if (LW_virtual == MAP_FAILED) {
        printf("ERRO: mmap() falhou...\n");
        close(fd);
        return 0;
    }

    HEX0_BASE_ptr = (volatile int *)(LW_virtual + HEX0_BASE);
    HEX1_BASE_ptr = (volatile int *)(LW_virtual + HEX1_BASE);
    HEX2_BASE_ptr = (volatile int *)(LW_virtual + HEX2_BASE);
    HEX3_BASE_ptr = (volatile int *)(LW_virtual + HEX3_BASE);
    HEX4_BASE_ptr = (volatile int *)(LW_virtual + HEX4_BASE);
    HEX5_BASE_ptr = (volatile int *)(LW_virtual + HEX5_BASE);

    return 1;
}

void write_number_display(int display_digit, int number) {
    
    if (display_digit == 0) {
        *HEX0_BASE_ptr = numbers(number);
    } else if (display_digit == 1) {
        *HEX1_BASE_ptr = numbers(number);
    } else if (display_digit == 2) {
        *HEX2_BASE_ptr = numbers(number);
    } else if (display_digit == 3) {
        *HEX3_BASE_ptr = numbers(number);
    } else if (display_digit == 4) {
        *HEX4_BASE_ptr = numbers(number);
    } else if (display_digit == 5) {
        *HEX5_BASE_ptr = numbers(number);
    } 

}

void close_display_device() {
    munmap(LW_virtual, LW_BRIDGE_SPAN);
    close(fd);
}
