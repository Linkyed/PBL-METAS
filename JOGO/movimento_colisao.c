#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "gpu_lib.h"
#include "mouse_move.h"

int main()
{   
    /* Tentar abrir o arquivo do kernel do driver da GPU */
    if (open_gpu_device() == 0)
        return 0;

    create_sprite(0, 15, 100, 100, 2, 1);
    create_sprite(1, 10, 100, 100, 0, 1);
    printf("cordX: %d, cordY: %d", sprites_array[0].pos_x, sprites_array[0].pos_y);
    int is_colliding = collision(&sprites_array[0], &sprites_array[1]);
    printf("\n\nCOLLISION: %d\n ", is_colliding);

    close_gpu_devide(); /* Fecha o arquivo do driver da GPU */

     /* Tentar abrir o arquivo do kernel do driver da GPU */
    if (open_gpu_device() == 0)
        return 0;
    if (open_mouse_device() == 0)
        return 0;

    /* system("clear");
    printf("COMEÇANDO\n");
    while (1) {
        mouse_movement();
        printf("\nCord X: %d, Cord Y: %d, BT_LEF: %d, BT_RIGHT: %d\n", pos_x, pos_y, left, right);
    } */
    set_background_color(0, 0, 0); /* Coloca a cor do background como preto */
    create_sprite(0, 15, 0, 0, 0, 1); /* SPRITE DO JOGADOR */
    create_sprite(1, 10, 100, 100, 1, 1); /* SPRITE DA BOMBA */
    create_sprite(2, 11, 540, 380, 1, 1); /* SPRITE DA BOMBA */
    create_sprite(3, 12, 100, 380, 1, 1); /* SPRITE DA BOMBA */
    create_sprite(4, 13, 540, 100, 1, 1); /* SPRITE DA BOMBA */
    while (1) {
        mouse_movement();
        change_coordinate(&sprites_array[0], pos_x, pos_y, 0);
        if (collision(&sprites_array[0], &sprites_array[1])) {
            printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
        }
        if (collision(&sprites_array[0], &sprites_array[2])) {
            printf("\nCOLIDIU COM A BOMBA NO CANTO INFERIOR DIREITO!\n");
        }
        if (collision(&sprites_array[0], &sprites_array[3])) {
            printf("\nCOLIDIU COM A BOMBA NO CANTO INFERIOR ESQUERDO!\n");
        }
        if (collision(&sprites_array[0], &sprites_array[1])) {
            printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR DIREITO!\n")
        }
    }



    close_gpu_devide(); /* Fecha o arquivo do driver da GPU */
    close_mouse_device();

    return 0;
}