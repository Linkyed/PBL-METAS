#include <stdio.h>
#include <stdlib.h>
//SUBSTITUIR PELA DO LINUX
#include <windows.h>

// Verifica se houve um vencedor e qual dos jogadores que foi e tambem verifica se ocorreu um empate
char verificar_vencedor (char matriz[3][3]){
    int i = 0;
    int j = 0;
    char vencedor = ' ';
    
    // Verifica linhas e colunas
    for (i = 0; i < 3; i++) {
        if ((matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2])) {
            vencedor = matriz[i][0];
        }
        if ((matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i])){
             vencedor = matriz[0][i];
        }
    }

    // Verifica diagonais
    if ((matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) || (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0])) {
        vencedor = matriz[1][1];
    }
    return vencedor;
    
}

// Imprimindo o tabuleiro no console
void imprimir_tabuleiro (char matriz[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c", matriz[i][j]);
            if (j != 2)
            {
                printf (" | ");
            }
        }
        if (i != 2){
            printf("\n---------\n");
        }
    }
    printf("\n\n======================================\n");
}

// Retorna o quadrante atual que o jogador esta selecionando
int quadrante_atual(int coordenada_x, int coordenada_y) {
    int tamanho_quadrante = 100; 
    int linhas = 3; 
    int colunas = 3; 
    
    int quadrantes_por_linha = 300 / tamanho_quadrante;
    int quadrantes_na_coluna = (coordenada_y -1) / tamanho_quadrante;
    int quadrantes_na_linha = (coordenada_x -1) / tamanho_quadrante;

    // Calcula o número do quadrante atual
    int quadrante_atual = quadrantes_na_coluna * quadrantes_por_linha + quadrantes_na_linha;

    return quadrante_atual;
}

int realizar_jogada(int *jogador_atual, int quadrante, int coordenada_da_jogada[2], char tabuleiro[3][3], int *rodada){
    int linha_da_jogada = 0;
    int coluna_da_jogada = 0;

    if (quadrante < 3){
        coluna_da_jogada = quadrante;
    } else if (quadrante >= 3 && quadrante < 6){
        linha_da_jogada = 1;
        coluna_da_jogada = quadrante - 3;
    } else if (quadrante >= 6 && quadrante < 9){
        linha_da_jogada = 2;
        coluna_da_jogada = quadrante - 6;
    }

    coordenada_da_jogada[0] = linha_da_jogada;
    coordenada_da_jogada[1] = coluna_da_jogada;

    if (*jogador_atual == 0 && tabuleiro[linha_da_jogada][coluna_da_jogada] != 'O'){
        tabuleiro[linha_da_jogada][coluna_da_jogada] = 'X';
        *jogador_atual = 1;
        *rodada += 1;
        return 1;
    } else if (*jogador_atual == 1 && tabuleiro[linha_da_jogada][coluna_da_jogada] != 'X'){
        tabuleiro[linha_da_jogada][coluna_da_jogada] = 'O';
        *jogador_atual = 0;
        *rodada += 1;
        return 1;
    }
    return 0;
}

void resetar_jogo(int *jogador, int *rodada, int *coordenada_x, int *coordenada_y){
    *jogador = 0;
    *rodada = 0;
    *coordenada_x = 0;
    *coordenada_y = 0;
}

int main()
{
    
    // Matriz com o Jogo
    char tabuleiro[3][3] = {{'0', '1', '2'}, 
                         {'3', '4', '5'}, 
                         {'6', '7', '8'}};
            
    //Coordenadas auxiliares ao qual serão incrementadas até um maximo de 300 cada uma, sendo que o tabuleiro no geral será de 300x300 e cada quadrante possuira 100x100 unidades
    int cordenada_x = 0;
    int cordenada_y = 0;

    int rodada = 0;
    
    //Variavel responsavel por controlar a vez de cada jogador, se for = 0 significa que o jogador atual é o X e se for = 1 significa que o jogador atual é o O
    int jogador_atual = 0;
    int coordenada_da_jogada_matriz[2] = {0, 0};
    char comando;

    while (1){
        //Limpando o console anterior e imprimindo o novo tabuleiro junto de algumas informações para os usuarios
        system("cls");
        imprimir_tabuleiro(tabuleiro);
        int quadrante_selecionado = quadrante_atual(cordenada_x, cordenada_y);
        printf("\nRodada Atual: %d\n", rodada);
        printf("O quadrante que o jogador %d esta selecionando e: %d\n", jogador_atual+1, quadrante_selecionado);
        printf("Se deseja realizar a jogada neste quadrante digite a letra C: ");

        comando = getchar();

        //Será trocado pela logica do mouse
        if ((comando == 'D' || comando == 'd') && cordenada_x < 300) //Mouse se movendo no eixo X para direita
            cordenada_x += 50;
        else if ((comando == 'A' || comando == 'a') && cordenada_x > 0) //Mouse se movendo no eixo X para esquerda
            cordenada_x -= 50;
        else if ((comando == 'S' || comando == 's') && cordenada_y < 300) //Mouse se movendo no eixo Y para baixo
            cordenada_y += 50;
        else if ((comando == 'W' || comando == 'w') && cordenada_y > 0) //Mouse se movendo no eixo Y para cima
            cordenada_y -= 50;
        else if ((comando == 'C' || comando == 'c')){ //Clique do mouse
            int confirmacao = realizar_jogada(&jogador_atual, quadrante_selecionado, coordenada_da_jogada_matriz, tabuleiro, &rodada);
            printf("Linha %d, Coluna %d", coordenada_da_jogada_matriz[0], coordenada_da_jogada_matriz[1]);
            if (confirmacao == 0){
                printf("\nO quadrante ja esta ocupado, tente realizar sua jogada em um quadrante vazio!\n");
            } else {
                printf("\nJogada realizada com sucesso!\n");
            }

            char resultado = verificar_vencedor(tabuleiro);
            if (resultado == 'X'){
                system("cls");
                imprimir_tabuleiro(tabuleiro);
                printf("\nJogador 1 foi o vencedor!");
                resetar_jogo(&jogador_atual, &rodada, &cordenada_x, &cordenada_y);
                break;
            } else if (resultado == 'O'){
                system("cls");
                imprimir_tabuleiro(tabuleiro);
                printf("\nJogador 2 foir o vencedor!");
                resetar_jogo(&jogador_atual, &rodada, &cordenada_x, &cordenada_y);
                break;
            } else if (resultado != 'O' && resultado != 'X' && rodada == 9){
                system("cls");
                imprimir_tabuleiro(tabuleiro);
                printf("\nO jogo terminou em empate!");
                resetar_jogo(&jogador_atual, &rodada, &cordenada_x, &cordenada_y);
                break;
            }

            Sleep(1000);
        }
        
    }

    return 0;
}