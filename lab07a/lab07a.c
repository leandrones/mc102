/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855 
 * Laboratorio 07a - Cargo-Bot - Part II */

#include <stdio.h>
#define MAX_POSICOES 10
#define MAX_CAIXAS 10
#define MAX_PROGRAMAS 9
#define MAX_COMANDOS 60
#define MAX_EXECUCOES 60

int main () {
    char caixas[MAX_CAIXAS][MAX_POSICOES];
    char programas[MAX_PROGRAMAS][MAX_COMANDOS];
    char execucao[MAX_EXECUCOES];
    int i, j, sem_asterisco;
    int X, Y, P, C, E;
    
    scanf ("%d %d %d %d %d", &X, &Y, &P, &C, &E);
    
    for (i = 0; i < Y; i++)
        for (j = 0; j < X; j++) 
            scanf (" %c", &caixas[i][j]);
        
    for (i = 0; i < E; i++)
        scanf (" %c", &execucao[i]);
    
    for (i = 0; i < P; i++) {
        sem_asterisco = 1;
        for (j = 0; (j < C) && (sem_asterisco); j++) {
            scanf (" %c", &programas[i][j]); 
            if (programas[i][j] == '*')
                sem_asterisco = 0;
        }
    }
    
    
    for (i = 0; i < E; i++) {
        intprograma = execucao[i] - '0';
        executaprog (execucao[intprograma - 1]
        
    

    for (i = 0; i < Y; i++) {
        for (j = 0; j < X; j++)
           printf ("%c", caixas[i][j]);
        printf ("\n");
    }
   
    return 0;
}


void executaprog (int numprograma) {
    execucao
    