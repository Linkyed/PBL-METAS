/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// codigo para compilar -> gcc -o main exemplo_main.c gpu_lib.c
#include <stdio.h>
#include "gpu_lib.h"

int main()
{   
    if (open_gpu_device() == 0)
        return 0;

    set_background_color(7, 7, 7); // COR BRANCA NO BACKGROUND
    set_background_block(0, 0, 7, 0, 0); // BLOCO 8x8 NA POSIÇÃO 0x0 DA TELA (CANTO SUPERIOR ESQUERDO)
    set_sprite(1, 100, 100, 0, 1); // CRIA SPRITE NA POSIÇÃO 100x100 DA TELA
    set_poligono(0, 50, 50, 1, 0, 7, 0, 0); // CRIA QUADRADO NA POSIÇÃO 50x50 
    

    close__gpu_devide();


    return 0;
}
