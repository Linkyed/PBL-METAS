
/**
 * \file            main.c
 * \brief           Programa que quando compilado será executado para formar um desenho no monitor usando a GPU
 */

/*
 * Copyright (c) year FirstName LASTNAME
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of library_name.
 *
 * Author:          FirstName LASTNAME <optional_email@example.com>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "GPU/gpu_lib.h"
#include "JOGO/mouse_move.h"
#include "GPU/screens/draw_screens.h"
#include "GPU/sprites/draw_sprites.h"


int create_sprite(int array_position, int reg, int x, int y, int offset, int step_x, int step_y, int direction, int sp) {
    sprites_array[array_position].data_register = reg;
    sprites_array[array_position].pos_x = x;
    sprites_array[array_position].pos_y = y;
    sprites_array[array_position].enable = sp;
    sprites_array[array_position].offset = offset;
    sprites_array[array_position].step_x = step_x;
    sprites_array[array_position].step_y = step_y;
    sprites_array[array_position].direction = direction;
    sprites_array[array_position].collision = 0;

    return 1;
    
}

int no_repeat_random (int last) {
    int random_num = rand() % 32;
    while (last == random_num) {
        random_num = rand() % 32;
    }
    return random_num;
}

void spaw_enemy (int difficult) {
    int i = 0;
    int j = 0;

    srand(time(NULL));

    int random_column = 0;
    int random_line = 0;
    // 0 = DIREITA, 1 = ESQUERDA, 2 = BAIXO, 3 = CIMA

    if (difficult == 0) {
        random_column = rand() % 31;
        random_line = rand() % 23;
        create_sprite(31, 31, random_column*20, random_line*20, 2, 5, 5, 0, 1);
        random_column = no_repeat_random(random_column);
        random_line = no_repeat_random(random_line);
        create_sprite(30, 30, random_column*20, random_line*20, 2, 5, 5, 2, 1);
    }
    else if (difficult == 1) {
        
    }

    else if (difficult == 2) {

    }

}

int main() {

    uint8_t game_state = 0;
    uint8_t start = 0;
    uint8_t contador = 0;

    draw_bomb();
    draw_coin();
    draw_player();
    draw_enemy();

    clear_background_blocks();
    clear_poligonos();
    clear_sprites();


    while (1) {
        if (game_state == 0) {
            draw_pause_screen();
        }
        else if (game_state == 1) {
            if (start == 0) {
                clear_background_blocks();
                clear_poligonos();
                clear_sprites();
                spaw_enemy(0);
                start = 1;
            }
            if (contador = 10000){
                static_movement(&sprites_array[31], 1);
                static_movement(&sprites_array[30], 1);
                contador = 0;
            }
            contador++;
        }
    }

    for (int i = 0; i<32; i++) {
        if (sprites_array[i].enable == 1){
            printf("POSX=%d, POSY=%d\n", sprites_array[i].pos_x, sprites_array[i].pos_y);
        }
    }


    return 0;
}
