#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <intelfpgaup/SW.h>
#include <stdint.h>

int main(int argc, char** argv)
{
    int8_t valor;

    SW_open();

    while (((valor >> 0) & 1) != 1){
        SW_read(valor);
    }
    printf("\n\n=========================SAIO DO PROGRAMA=========================\n\n")
}