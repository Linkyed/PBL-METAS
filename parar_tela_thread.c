#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "gpu_lib.h"
#include <intelfpgaup/SW.h>

int control = 1;
// Function to be executed by the first thread
void* move_sprites(void* arg) {
    int x = 0;
    while (control) {
        set_sprite(1, x, 50, 6, 1); /* Nave superior */
        x += 5;
        if (x == 620) {
            x = 0;
        }
    }
    return NULL;
}

// Function to be executed by the second thread
void* verifica_chaves(void* arg) {
    SW_open();
    int valor = 0;
    int *dados_sw = &valor;
    while (1) {
        SW_read(dados_sw);
        switch (*dados_sw) {
            case 1: {
                control = 0;
                break;
            }
            case 2: {
                printf("Caso 2")
                break;
            }
            case 3: {
                printf("\n\nSAINDO DO PROGRAMA\n\n")
                return 0;
            }

            default: { 
                break;
            }
        }
    }
    SW_close();
    return NULL;
}


int main() {
    pthread_t thread1, thread2;

    // Create the first thread
    if (pthread_create(&thread1, NULL, move_sprites, NULL) != 0) {
        perror("Failed to create thread1");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, verifica_chaves, NULL) != 0) {
        perror("Failed to create thread2");
        return 1;
    }

    // Wait for the threads to finish (they won't in this case, as they run indefinitely)
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
