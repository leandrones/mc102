/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855 
 * Laboratorio 07b - Walk-Bot - Part I */

/* Programa que faz o relatorio de todas as possibilidades de caminho do Walk
   Bot ao longo de um determinado tabuleiro */

#include <stdio.h>
#define MAX 50

int main () {
    /* comandos eh a matriz que representa o tabuleiro 
     * contador que mostra quantas vezes o robo passou naquele local 
     * armadilha, loop e sucesso sao flags 
     * passos e tamloop sao outros contadores */
    char comandos[MAX][MAX];
    int i, j, k, N, M, contador[MAX][MAX];    
    int armadilha, loop, tamloop, sucesso, passos;
    
    /* Leitura de dados */
    scanf ("%d %d", &N, &M);
    
    for (i = 0; i < N; i++)
        scanf ("%s", comandos[i]);
              
    for (k = 0; k < N; k++) {
        /* Inicializaçao da matriz contadora */
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++)
                contador[i][j] = 0;
        /* Inicializaçao de flags, contadores e indices */
        armadilha = 0;
        sucesso = 0;
        loop = 0;
        tamloop = 0;
        passos = 0;
        i = k;
        j = 0;        
        /* Incrementando a primeira coluna */
        contador[i][j]++;        
        /* Executa todos os comandos ate levantar uma flag */
        while ((!armadilha) && (!loop) && (!sucesso)) {
            if (comandos[i][j] == 'R') {
                j++;
                passos++;
                contador[i][j]++;
                /* Testa se o robo saiu do tabuleiro */
                if (j == M)
                    sucesso = 1;
                /* Conta o  tamanho do loop ao seu inicio */
                else if (contador[i][j] == 2) {
                    tamloop++;
                }
                /* Interrompe a contagem do loop */
                else if (contador[i][j] == 3) {
                    loop = 1;
                }
            }
            else if (comandos[i][j] == 'L') {
                j--;
                passos++;
                contador[i][j]++;
                if (contador[i][j] == 2) {
                    tamloop++;
                }
                else if (contador[i][j] == 3)
                    loop = 1;
            }
            else if (comandos[i][j] == 'D') {
                i++;
                passos++;
                contador[i][j]++;
                if (contador[i][j] == 2) {
                    tamloop++;
                }
                else if (contador[i][j] == 3)
                    loop = 1;
            }
            else if (comandos[i][j] == 'U') {
                i--;
                passos++;
                contador[i][j]++;
                if (contador[i][j] == 2) {
                    tamloop++;
                }
                else if (contador[i][j] == 3)
                    loop = 1;
            }
            /* Testa se o robo caiu em uma armadilha */
            else if (comandos[i][j] == 'X')
                armadilha = 1;           
        }
        /* Impressao de resultados para cada linha */
        if (armadilha)
           printf ("Armadilha em (%d,%d) apos %d passo(s)\n", i+1, j+1, passos);
        else if (loop)
           printf ("Loop de tamanho %d\n", tamloop);
        else if (sucesso)
           printf ("Saiu em (%d,%d) apos %d passo(s)\n", i+1, j, passos-1);
    }
    
    return 0;
}

