#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "gpu_lib.h"

int main()
{   
    /* Tentar abrir o arquivo do kernel do driver da GPU */
    if (open_gpu_device() == 0)
        return 0;

    create_sprite(0, 0, 0, 0, 0, 1);
    create_sprite(1, 1, 40, 40, 0, 1);
    int is_colliding = collision(sprites_array[0], sprites_array[1]);
    printf("COLLISION: %d", is_colliding)

    close_gpu_devide(); /* Fecha o arquivo do driver da GPU */

    return 0;
}
