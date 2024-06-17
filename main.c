/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>


void instrucao_wbr_sprite (int reg, int offset, int x, int y, int sp) {
    printf("reg: %d, offset: %d, x: %d, y: %d, sp: %d\n", reg, offset, x, y, sp);
}

void instrucao_wbm (int address, int r, int g, int b) {
    printf("address: %d, r: %d, g: %d, b: %d\n", address, r, g, b);
}

void instrucao_wsm (int address, int r, int g, int b) {
    printf("address: %d, r: %d, g: %d, b: %d\n", address, r, g, b);
}

void instrucao_dp(int address, int ref_x, int ref_y, int size, int r, int g, int b, int shape) {
    printf("address: %d, refx: %d, refy: %d, size: %d, r: %d, g: %d, b: %d, shape: %d\n", address, ref_x, ref_y, size, r, g, b, shape);
}

void send(unsigned char *command) {
    switch (command[0]) {
        case 0:  {
            int R = command[1];
            int G = command[2];
            int B = command[3];
            break;
        }
        case 1: {
            int reg = command[1];
            int offset = ((command[2] << 1) & 0x1FE) | ((command[3] >> 7) & 0x01); // 9-bit offset
            int x = ((command[3] << 3) & 0x3F8) | ((command[4] >> 5) & 0x07);     // 10-bit x
            int y = ((command[4] << 5) & 0x3E0) | ((command[5] >> 3) & 0x1F);     // 10-bit y
            int sp = command[6];
            instrucao_wbr_sprite(reg, offset, x, y, sp);
            break;
        }
        case 2: {
            int address = ((command[1] << 4) | (command[2] >> 4)); // 12-bit address
            int r = command[2] & 0x0F;
            int g = command[3];
            int b = command[4];
            instrucao_wbm(address, r, g, b);
            break;
        }
        case 3: {
            int address = (command[1] << 6) | (command[2]); // 14-bit address
            int r = command[3] & 0x07;
            int g = command[4];
            int b = command[5];
            instrucao_wsm(address, r, g, b);
            break;
        }
        case 4: {
            int address = command[1];
            int ref_x = ((command[2] << 1) | command[3] >> 7);
            int ref_y = (((command[3] & 0b1111111) << 2) | command[4] >> 6);
            int size = command[4] & 0b1111;
            int r = command[5] >> 5;
            int g = (command[5] >> 2) & 0b111;
            int b =  command[6] >> 5;
            int shape =  command[6] & 0b1;
            instrucao_dp(address, ref_x, ref_y, size, r, g, b, shape);
            break;
        }
        default: {
            
        }
    }
}



void send_instrucao_wbr_sprite(int reg, int offset, int x, int y, int sp) {
    unsigned char command[7];

    command[0] = 1; // Command for instrucao_wbr_sprite
    command[1] = reg;
    command[2] = (offset >> 1) & 0xFF;
    command[3] = ((offset & 0x01) << 7) | ((x >> 3) & 0x7F);
    command[4] = ((x & 0x07) << 5) | ((y >> 5) & 0x1F);
    command[5] = (y & 0x1F) << 3;
    command[6] = sp;

    send (command);

}

void send_instrucao_wbm(int address, int r, int g, int b) {
    unsigned char command[5];
    //  1111 1111 1111
    command[0] = 2; // Command for instrucao_wsm
    command[1] = (address >> 4); // Higher 8 bits of 14-bit address
    command[2] = ((address) << 4) | (r & 0b0111); // Lower 6 bits of address and 3-bit r
    command[3] = g & 0xFF; // g value
    command[4] = b & 0xFF; // b value
    send (command);
}


void send_instrucao_wsm(int address, int r, int g, int b) {
    unsigned char command[6];
    // 0011 1111 1111 1111
    command[0] = 3; // Command for instrucao_wsm
    command[1] = (address >> 6); // Higher 8 bits of 14-bit address
    command[2] = (address & 0b111111); // Lower 6 bits of address and r
    command[3] = r & 0b111;
    command[4] = g & 0b111; // g value
    command[5] = b & 0b111; // b value

    send(command);
}

void send_instrucao_dp(int address, int ref_x, int ref_y, int size, int r, int g, int b, int shape) {
    unsigned char command[7];
    // 0001 1111 1111
    // 0100 0000 0000
    command[0] = 4; // Command for instrucao_wsm
    command[1] = address; // Higher 8 bits of 14-bit address
    command[2] = ref_x >> 1; // Lower 6 bits of address and r
    command[3] = ((ref_x & 0b01) << 7) | (ref_y >> 2); // Lower 6 bits of address and r
    command[4] = ((ref_y & 0b11) << 6) | (size & 0b1111);
    command[5] = ((r & 0b111)<< 5) | (g & 0b111) << 2; // b value
    command[6] = ((b &0b111) << 5) | shape & 0b1;
    //printf("asd: %d, %d, %d\n", command[2], (command[3] >> 7), ((command[2] << 1) | command[3] >> 7));
    //printf("asd: %d, %d, %d", (command[3] & 0b1111111), (command[4] >> 6), (((command[3] & 0b1111111) << 2) | command[4] >> 6));

    send(command);
}

int main() {

    // Example values
    int reg = 2;
    int offset = 1; // Example offset value (9 bits)
    int x = 1;      // Example x value (10 bits)
    int y = 1;      // Example y value (10 bits)
    int sp = 1;       // Example sp value

    send_instrucao_wbr_sprite(1, reg, offset, x, y, sp);
    send_instrucao_wbm(4096, 7, 7, 7);
    send_instrucao_wsm(16384, 7, 7, 7);
    send_instrucao_dp(1, 511, 511, 15, 7, 7, 7, 1);


    return 0;
}