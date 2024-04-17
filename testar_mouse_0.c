#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
    int fd, bytes;
    unsigned char data[3];

    const char *pDevice = "/dev/input/mice";

    // Open Mouse
    fd = open(pDevice, O_RDWR);
    if(fd == -1)
    {
        printf("ERROR Opening %s\n", pDevice);
        return -1;
    }

    int left, middle, right;
    int cord_X = 0;
    int cord_Y = 0;
    signed char x, y;
    while(1)
    {
        // Read Mouse     
        bytes = read(fd, data, sizeof(data)); // Abre o arquivo MICE para leitura dos eventos de input que o mouse esta enviando

        if(bytes > 0)
        {
            left = data[0] & 0x1; // Lê o 1º LSB e se for igual a 1 significa que o botão esquerdo foi pressionado então left = 1 tambem
            right = data[0] & 0x2; // Lê o 2º LSB e se for igual a 1 significa que o botão direito foi pressionado então right = 1 tambem
            middle = data[0] & 0x4;// Lê o 4º LSB e se for igual a 1 significa que o botão do meio foi pressionado então middle = 1 tambem

            x = data[1]; // Lê o segundo pack que é responsavel por indicar a movimentação do mouse no eixo X
            y = data[2]; // Lê o terceiro pack que é responsavel por indicar a movimentação do mouse no eixo Y
            //printf("x=%d, y=%d, btn_esqueda=%d, btn_meio=%d, btn_direito=%d\n", x, y, left, middle, right);
            if ( (cord_X+1 < 300 && cord_X-1 > 0)){
                 if (x > 0){
                        cord_X += 1;}
                 if (x < 0){
                        cord_X -= 1;}
            }

            printf("Coordenada X: %d\n", cord_X);
            system("clear");
        }   
    }
    return 0; 
}