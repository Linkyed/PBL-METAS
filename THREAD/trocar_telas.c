#include <stdio.h>
#include <stdint.h>
#include <intelfpgaup/SW.h>
#include "gpu_lib.h"

int main() {
    SW_open();
    int *dados_sw = &valor;

    // TROCANDO A COR DO BACKGROUND COM CADA CHAVE (TEM QUE ALTERAR PARA OS BOTÕES)
    while (1)
    {
        SW_read(dados_sw);
        switch (*dados_sw) {
            case 1: {
                set_background_color(7, 0, 0);
                break;
            }
            case 2: {
                set_background_color(0, 7, 0);
                break;
            }
            case 3: {
                set_background_color(0, 0, 7);
                break;
            }

            default: { 
                break;
            }
        }
    }
    SW_close();
    return 0;

}
