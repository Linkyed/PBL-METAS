#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include "mouse_move.h"


fd = 0;
pos_x = 0;
pos_y = 0;
left = 0;
middle = 0;
right = 0;

int open_mouse_device()
{
    fd = open(MICE_PATH, O_RDWR);

    if (fd < 0)
    {
        perror("Failed to open the device");
        return 0;
    }
    return 1;
}

void close_mouse_device()
{
    close(fd);
}

void mouse_movement()
{
    int bytes = read(fd, data, sizeof(data)); // Abre o arquivo MICE para leitura dos eventos de input que o mouse esta enviando

    left = data[0] & 0x1;   // Lê o 1º LSB e se for igual a 1 significa que o botão esquerdo foi pressionado então left = 1 tambem
    right = data[0] & 0x2;  // Lê o 2º LSB e se for igual a 1 significa que o botão direito foi pressionado então right = 1 tambem
    middle = data[0] & 0x4; // Lê o 4º LSB e se for igual a 1 significa que o botão do meio foi pressionado então middle = 1 tambem

    if (data[1] > 0 && pos_x < 640)
    {
        pos_x += 1;
    }
    else if (data[1] < 0 && pos_x > 0)
    {
        pos_x -= 1;
    }

    if (data[2] > 0 && pos_y > 0)
    {
        pos_y -= 1;
    }
    else if (data[2] < 0 && pos_y < 480)
    {
        pos_y += 1;
    }
}