
#include <stdio.h>
#include <unistd.h>
#include "gpu_lib.h"

int main()
{   
    if (open_gpu_device() == 0)
        return 0;

    set_background_color(0, 0, 0);

// ======================================================== DESENHA TODOS OS POLIGONOS DA TELA ========================================================
    printf("Pressione 'N' para começar o desenho: ");


    while (1) {
        ch = getchar();

        if (ch == 'N') {
            break;
        }

        while (getchar() != '\n');
        
        printf("Pressione 'N' para começar o desenho: ");
    }

    usleep(300 * 1000); 
    set_poligono(6, 400, 300, 9, 0, 0, 5, 0); // PAREDE DA CASA
    usleep(300 * 1000); 
    set_poligono(5, 400, 200, 10, 5, 0, 0, 1); // TELHADO DA CASA
    usleep(300 * 1000); 
    set_poligono(2, 380, 310, 1, 4, 2, 0, 0); // JANELA DA CASA
    usleep(300 * 1000); 
    set_poligono(1, 420, 335, 2, 4, 2, 0, 0); // PRIMEIRA PARTE DA PORTA DA CASA
    usleep(300 * 1000); 
    set_poligono(0, 420, 305, 2, 4, 2, 0, 0); // SEGUNDA PARTE DA PORTA DA CASA
    usleep(300 * 1000); 
    set_poligono(14, 500, 100, 4, 7, 7, 7, 0); // LUA


// ======================================================== DESENHA O CHÃO DO DESENHO  ========================================================
    printf("Pressione 'N' para desenhar o chão: ");

    while (1) {
        ch = getchar();

        if (ch == 'N') {
            break;
        }

        while (getchar() != '\n');
        
        printf("Pressione 'N' para desenhar o chão: ");
    }

    fill_background_blocks(35);

// ======================================================== DESENHA AS ESTRELAS NO CEU  ========================================================
    printf("Pressione 'N' para desenhar as estrelas: ");

    while (1) {
        ch = getchar();

        if (ch == 'N') {
            break;
        }

        while (getchar() != '\n');
        
        printf("Pressione 'N' para desenhar as estrelas: ");
    }

    set_background_block(10, 10, 7, 5, 0);
    usleep(250 * 1000);
    set_background_block(25, 13, 7, 5, 0);
    usleep(250 * 1000);
    set_background_block(34, 11, 7, 5, 0);
    usleep(250 * 1000);
    set_background_block(15, 15, 7, 5, 0);
    usleep(250 * 1000);
    set_background_block(46, 12, 7, 5, 0);
    usleep(250 * 1000);
    set_background_block(40, 10, 7, 5, 0);
    usleep(250 * 1000);
    set_background_block(33, 16, 7, 5, 0);
    usleep(250 * 1000);
    set_background_block(70, 13, 7, 5, 0);
    usleep(250 * 1000);
    set_background_block(8, 15, 7, 5, 0);
    usleep(250 * 1000);
    set_background_block(75, 9, 7, 5, 0);
    usleep(250 * 1000);
    set_background_block(78, 15, 7, 5, 0);

// ======================================================== DESENHA OS SPRITES NA TELA  ========================================================
    printf("Pressione 'N' para desenhar os sprites: ");

    while (1) {
        ch = getchar();

        if (ch == 'N') {
            break;
        }

        while (getchar() != '\n');
        
        printf("Pressione 'N' para desenhar os sprites: ");
    }

    set_sprite(1, 0, 50,6 , 1); // NAVE
    set_sprite(4, 620, 100, 8, 1); // NAVE
    set_sprite(2, 200, 330, 4 , 1); // FLOR
    set_sprite(3, 250, 330, 4 , 1); // FLOR

// ======================================================== ANIMAÇÃO DAS NAVES NA TELA ========================================================
    printf("Pressione 'N' para começar a animação das naves: ");

    while (1) {
        ch = getchar();

        if (ch == 'N') {
            break;
        }

        while (getchar() != '\n');
        
        printf("Pressione 'N' para começar a animação das naves: ");
    }

    int x = 0;
    int x2 = 620;

    while (1){
       x += 10;
       x2 -= 10;
       set_sprite(1, x, 50, 6, 1);
       set_sprite(4, x2, 100, 8, 1); 
        
       if (x == 620){
	 x = 0;
         x2 = 620;
       }
       usleep(300 * 1000); 
    }

    close__gpu_devide();


    return 0;
}