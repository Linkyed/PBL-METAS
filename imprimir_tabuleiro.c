#include <stdio.h>

int verificar_vencedor (char matriz[3][3]){
    int i = 0;
    int j = 0;
    char vencedor = ' ';
    
    // Verifica linhas e colunas
    for (i = 0; i < 3; i++) {
        if ((matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) || 
            (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i])) {
            if (matriz[i][0] != ' ')
                vencedor = matriz[i][0];
        }
    }
    
    // Verifica diagonais
    if ((matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) ||
        (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0])) {
        if (matriz[1][1] != ' ')
            vencedor = matriz[1][1];
    }
    return vencedor;
    
}

int main()
{
    // Matriz com o Jogo
    char linhas[3][3] = {{'X', 'X', 'O'}, 
                         {'X', 'O', 'O'}, 
                         {'X', 'O', 'X'}};
                
    // Imprimindo o jogo no consolee
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c", linhas[i][j]);
            if (j != 2)
            {
                printf (" | ");
            }
        }
        if (i != 2){
            printf("\n---------\n");
        }
    }
    
    // Montrando o resultado da partida
    char resultado = verificar_vencedor(linhas);
    printf ("\n\n");
    if (resultado == 'X')
        printf("O jogador 1 é o vencedor!");
    else if (resultado == 'O')
        printf("O jogador 2 é o vencedor!");
    else
        printf("A partida terminou em empate!");
    
    
    

    return 0;
}
