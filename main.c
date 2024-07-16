#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "gpu_lib.h"
#include <stdlib.h>
#include <fcntl.h>       
#include <sys/mman.h>
#include "draw_screens.h"
#include "draw_sprites.h" 
#include "mouse_move.h"
#include <pthread.h>
#include "botoes.h"
#include "display_controler.h"


    uint8_t game_state = 1;
    uint8_t start = 0;
    uint32_t contador = 0;

int coin_collumn = 0;
int coin_line = 0;


int no_repeat_random (int last, int line) {
    int random_num = last;
    while (last == random_num) {
        if (line == 1) {
            random_num = rand() % 23;
        }
        else {
            random_num = rand() % 31;
        }
    }
    return random_num;
}

int no_repeat_random_and_coin (int last, int line) {
    int random_num = last;
    while (last == random_num || last == coin_collumn) {
        if (line == 1) {
            random_num = rand() % 23;
        }
        else {
            random_num = rand() % 31 ;
        }
    }
    return random_num;
}

void spawn_bomb(int difficult) {
    srand(time(NULL));
    int bomb_collumn = 0;
    int bomb_line = 0;
    bomb_collumn = no_repeat_random_and_coin(coin_collumn, 0);
    bomb_line == no_repeat_random_and_coin(coin_line, 1);
    create_sprite(3, 3, bomb_collumn*20, bomb_line*20, 2, 0, 0, 0, 1);
    
    bomb_collumn = no_repeat_random_and_coin(coin_collumn, 0);
    bomb_line == no_repeat_random_and_coin(coin_line, 1);
    create_sprite(4, 4, bomb_collumn*20, bomb_line*20, 2, 0, 0, 0, 1);

    if (difficult == 4) {
        bomb_collumn = no_repeat_random_and_coin(coin_collumn, 0);
        bomb_line == no_repeat_random_and_coin(coin_line, 1);
        create_sprite(5, 5, bomb_collumn*20, bomb_line*20, 2, 0, 0, 0, 1);
        
        bomb_collumn = no_repeat_random_and_coin(coin_collumn, 0);
        bomb_line == no_repeat_random_and_coin(coin_line, 1);
        create_sprite(6, 6, bomb_collumn*20, bomb_line*20, 2, 0, 0, 0, 1);
    }
}

void spawn_coin() {
    srand(time(NULL));

    coin_collumn = no_repeat_random(coin_collumn, 0);
    coin_line = no_repeat_random(coin_line, 1);
    printf("X=%d, Y=%d\n", coin_collumn, coin_line);
    create_sprite(2, 2, coin_collumn*20, coin_line*20, 3/*A DEFINIR OFFSET*/, 0, 0, 0, 1);
}

void spaw_enemy(int difficult) {

    srand(time(NULL));

    int random_column = 0;
    int random_line = 0;
    // 0 = DIREITA, 1 = ESQUERDA, 2 = BAIXO, 3 = CIMA

    if (difficult == 0) {
        random_column = rand() % 31;
        random_line = rand() % 23;
        printf("X=%d, Y=%d\n", random_column, random_line);
        create_sprite(31, 31, random_column*20, random_line*20, 1, 1, 5, 0, 1);
        random_column = no_repeat_random(random_column, 0);
        random_line = no_repeat_random(random_line, 1);
        printf("X=%d, Y=%d\n", random_column, random_line);
        create_sprite(30, 30, random_column*20, random_line*20, 1, 5, 1, 2, 1);
    }
    else if (difficult == 1) {
        random_column = rand() % 31;
        random_line = rand() % 23;
        //printf("X=%d, Y=%d\n", random_column*19, random_line*19);
        create_sprite(31, 31, random_column*20, random_line*20, 1, 2, 2, 0, 1);
        random_column = no_repeat_random(random_column, 0);
        random_line = no_repeat_random(random_line, 1);
        //printf("X=%d, Y=%d\n", random_column*19, random_line*19);
        create_sprite(30, 30, random_column*20, random_line*20, 1, 2, 2, 2, 1);
        random_column = no_repeat_random(random_column, 0);
        random_line = no_repeat_random(random_line, 1);
        //printf("X=%d, Y=%d\n", random_column*19, random_line*19);
        create_sprite(29, 29, random_column*20, random_line*20, 1, 2, 2, 1, 1);
        random_column = no_repeat_random(random_column, 0);
        random_line = no_repeat_random(random_line, 1   );
        //printf("X=%d, Y=%d\n", random_column*19, random_line*19);
        create_sprite(28, 28, random_column*20, random_line*20, 1, 2, 2, 3, 1);
    }

    else if (difficult == 2) {
        random_column = rand() % 31;
        random_line = rand() % 23;
        //printf("X=%d, Y=%d\n", random_column*19, random_line*19);
        create_sprite(31, 31, random_column*20, random_line*20, 1, 2, 2, 0, 1);
        random_column = no_repeat_random(random_column, 0);
        random_line = no_repeat_random(random_line, 1);
        //printf("X=%d, Y=%d\n", random_column*19, random_line*19);
        create_sprite(30, 30, random_column*20, random_line*20, 1, 2, 2, 2, 1);
        random_column = no_repeat_random(random_column, 0);
        random_line = no_repeat_random(random_line, 1);
        //printf("X=%d, Y=%d\n", random_column*19, random_line*19);
        create_sprite(29, 29, random_column*20, random_line*20, 1, 2, 2, 1, 1);
        random_column = no_repeat_random(random_column, 0);
        random_line = no_repeat_random(random_line, 1   );
        //printf("X=%d, Y=%d\n", random_column*19, random_line*19);
        create_sprite(28, 28, random_column*20, random_line*20, 1, 2, 2, 3, 1);
        random_column = no_repeat_random(random_column, 0);
        random_line = no_repeat_random(random_line, 1);
        //printf("X=%d, Y=%d\n", random_column*19, random_line*19);
        create_sprite(27, 27, random_column*20, random_line*20, 1, 2, 2, 0, 1);
        random_column = no_repeat_random(random_column, 0);
        random_line = no_repeat_random(random_line, 1   );
        //printf("X=%d, Y=%d\n", random_column*19, random_line*19);
        create_sprite(26, 26, random_column*20, random_line*20, 1, 2, 2, 2  , 1);
    }

}

void* loop_principal (void* arg) {
    int difficulty = 0;
    int difficulty_completed = 1;
    int score = 0;
    int spawn_coin_ver = 0;

    while (botao0) { /* BOTAO MAIS A DIREITA INICIA */
        read_botoes();
        set_background_color(7, 7, 7);
        //draw_start_screen(); /* TEM QUE CRIAR*/
        
    }

    set_background_color(0, 0, 0);

    game_state = 1;

    while (1) {
        read_botoes();
        if (botao0 == 0) { /* BOTAO MAIS A DIREITA RESETA */
            game_state = 3;
        } else if (botao1) { /* SEGUNDO BOTAO MAIS A DIREITA PAUSA */
            game_state = 0;
        } else if (botao2) { /* CONTINUA O JOGO EM CASO DE PAUSE*/
            game_state = 1;
        }
        if (game_state == 0) { /* JOGO PAUSADO */
            
            draw_pause_screen();
        }
        else if (game_state == 1) { /* FASE ROLANDO */
            if (start == 0) {
                spaw_enemy(difficulty);
                if (difficulty >= 3) {
                    spawn_bomb(difficulty);
                }
                start = 1;
                spawn_coin();
            }
            while (difficulty_completed) {
                read_botoes();
                if (botao0 == 0 || botao1 == 0) {
                    clear_poligonos();
                    clear_sprites();
                    break;
                }
                if (difficulty == 0) {
                    if (collision(&sprites_array[1], &sprites_array[31])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[30])) {
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[2])) {
                        score += 1;
                        printf("PEGOU A MOEDA!\n");
                        spawn_coin();
                        if (score == 5) {
                            difficulty_completed = 0;
                            difficulty = 1;
                            game_state = 2;
                            break;
                        }
                    }
                    if (contador == 20000){
                        static_movement(&sprites_array[31], 1);
                        static_movement(&sprites_array[30], 1);
                        contador = 0;
                    }
                    contador += 1;
                } else if (difficulty == 1) {
                    if (collision(&sprites_array[1], &sprites_array[31])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[30])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[29])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[28])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[2])) {
                        score += 1;
                        printf("PEGOU A MOEDA!\n");
                        spawn_coin();
                        if (score == 10) {
                            difficulty_completed = 0;
                            difficulty = 2;
                            game_state = 2;
                            break;
                        }
                    }
                    if (contador == 20000){
                        static_movement(&sprites_array[31], 1);
                        static_movement(&sprites_array[30], 1);
                        static_movement(&sprites_array[29], 1);
                        static_movement(&sprites_array[28], 1);
                        contador = 0;
                    }
                    contador += 1;
                } else if (difficulty == 2) {
                    if (collision(&sprites_array[1], &sprites_array[31])) {
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[30])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[29])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[28])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[27])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[26])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[2])) {
                        score += 1;
                        printf("PEGOU A MOEDA!\n");
                        spawn_coin();
                        if (score == 15) {
                            difficulty_completed = 0;
                            difficulty = 3;
                            game_state = 2;
                            break;
                        }
                    }
                    if (contador == 20000){
                        static_movement(&sprites_array[31], 1);
                        static_movement(&sprites_array[30], 1);
                        static_movement(&sprites_array[29], 1);
                        static_movement(&sprites_array[28], 1);
                        static_movement(&sprites_array[27], 1);
                        static_movement(&sprites_array[26], 1);
                        contador = 0;
                    }
                    contador += 1;
                } else if (difficulty == 3) {
                    if (collision(&sprites_array[1], &sprites_array[31])) {
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[30])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[29])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[28])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[27])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[26])) {
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                        //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                    }
                    if (collision(&sprites_array[1], &sprites_array[3])) { /* COLISAO COM BOMBA */
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO COM BOMBA: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                        //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                    }
                    if (collision(&sprites_array[1], &sprites_array[4])) { /* COLISAO COM BOMBA */
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO COM BOMBA: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                        //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                    }
                    if (collision(&sprites_array[1], &sprites_array[2])) { /* COLISAO COM COIN */
                        score += 1;
                        printf("PEGOU A MOEDA!\n");
                        spawn_coin();
                        if (score == 15) {
                            difficulty_completed = 0;
                            difficulty = 3;
                            game_state = 2;
                            break;
                        }
                    }
                    if (contador == 20000){
                        static_movement(&sprites_array[31], 1);
                        static_movement(&sprites_array[30], 1);
                        static_movement(&sprites_array[29], 1);
                        static_movement(&sprites_array[28], 1);
                        static_movement(&sprites_array[27], 1);
                        static_movement(&sprites_array[26], 1);
                        contador = 0;
                    }
                    contador += 1;
                } else if (difficulty == 4) {
                    if (collision(&sprites_array[1], &sprites_array[31])) {
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[30])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[29])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[28])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[27])) {
                game_state = 0;
                usleep(500000);
                printf("COLISÃO: %d\n", sprites_array[1].collision);
                clear_poligonos();
                clear_sprites();
                draw_game_over_screen();
                break;
                //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                }
                    if (collision(&sprites_array[1], &sprites_array[26])) {
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                        //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                    }
                    if (collision(&sprites_array[1], &sprites_array[3])) { /* COLISAO COM BOMBA */
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO COM BOMBA: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                        //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                    }
                    if (collision(&sprites_array[1], &sprites_array[4])) { /* COLISAO COM BOMBA */
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO COM BOMBA: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                        //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                    }
                    if (collision(&sprites_array[1], &sprites_array[5])) { /* COLISAO COM BOMBA */
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO COM BOMBA: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                        //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                    }
                    if (collision(&sprites_array[1], &sprites_array[6])) { /* COLISAO COM BOMBA */
                        game_state = 0;
                        usleep(500000);
                        printf("COLISÃO COM BOMBA: %d\n", sprites_array[1].collision);
                        clear_poligonos();
                        clear_sprites();
                        draw_game_over_screen();
                        break;
                        //printf("\nCOLIDIU COM A BOMBA NO CANTO SUPERIOR ESQUERDO!\n");
                    }
                    if (collision(&sprites_array[1], &sprites_array[2])) { /* COLISAO COM COIN */
                        score += 1;
                        printf("PEGOU A MOEDA!\n");
                        spawn_coin();
                        if (score == 15) {
                            difficulty_completed = 0;
                            difficulty = 3;
                            game_state = 2;
                            break;
                        }
                    }
                    if (contador == 20000){
                        static_movement(&sprites_array[31], 1);
                        static_movement(&sprites_array[30], 1);
                        static_movement(&sprites_array[29], 1);
                        static_movement(&sprites_array[28], 1);
                        static_movement(&sprites_array[27], 1);
                        static_movement(&sprites_array[26], 1);
                        contador = 0;
                    }
                    contador += 1;
                }
            }
        } else if (game_state == 2) { /*FASE COMPLETA*/
            usleep(500000);
            clear_all();
            if(difficulty == 0){
                draw_fase_screen(1);
            } else if(difficulty == 1){
                draw_fase_screen(2);
            } else if(difficulty == 2){
                draw_fase_screen(3);
            }
            usleep(2000000);
            game_state = 1;
            difficulty_completed = 1;
            start = 0;
            difficulty += 1;
        } else if (game_state == 3) { /* JOGO REINICIADO */
            score = 0;
            clear_all();
            int i = 0;
            for(i; i < 31; i++) {
                sprites_array[i].collision = 0;
                sprites_array[i].enable = 0;
                sprites_array[i].pos_x = 0;
                sprites_array[i].pos_y = 0;
            }
            draw_restart_screen();
            usleep(2000000);
            difficulty = 0;
            difficulty_completed = 1;
        }
    }
    return NULL;
}

void* player_movement(void* arg) {
    while (1) {
        if (game_state != 1) {
            set_sprite(1, 0, 0, 0, 0);
        } else {
            set_sprite(1, 0, 0, 0, 1);
        }
        //printf("\nX = %d , Y = %d\n", pos_x, pos_y);
        mouse_movement();
        change_coordinate(&sprites_array[1], pos_x, pos_y, 0);
        printf("\n");
    }
    usleep(500000);
    set_sprite(1, 0, 0, 0, 0);
    return NULL;
}

int main() {



    if (open_gpu_device() == 0)
        return 0;
    if (open_mouse_device() == 0){
        return 0;
    }
    if (open_botoes_device() == 0){
        return 0;
    }
    if (open_display_device() == 0){
        return 0;
    }
    open_botoes_device();
    open_display_device();


    draw_player();
    draw_enemy();
    draw_coin();
    draw_bomb();

    clear_background_blocks();
    clear_poligonos();
    clear_sprites();

    set_background_color(0, 0, 0);

    create_sprite(1, 1, 0, 0, 0, 0, 0, 0, 0);  /* PLAYER */ 

    pthread_t thread1, thread2;

    // Create the first thread
    if (pthread_create(&thread1, NULL, loop_principal, NULL) != 0) {
        perror("Failed to create thread1");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, player_movement, NULL) != 0) {
        perror("Failed to create thread2");
        return 1;
    }

            // Wait for the threads to finish (they won't in this case, as they run indefinitely)
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    
    /*  
    for (int i = 0; i<32; i++) {
        if (sprites_array[i].enable == 1){
            printf("POSX=%d, POSY=%d\n", sprites_array[i].pos_x, sprites_array[i].pos_y);
        }
    } */




    close_gpu_devide();
    close_mouse_device();
    close_botoes_devide();
    close_display_device();

    return 0;
}