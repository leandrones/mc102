/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855 
 * Laboratorio 04a - Cargo-Bot - Part I */

#include <stdio.h>
#define MAX 10

/*Programa para mostrar qual foi o resultado do rearranjo de caixas feito pelo
robô */

int main () {
    
    /* A variavel caixa mostra se o robô está segurando ou nao uma caixa 
     * O vetorX armazena quantidade de caixas em cada posiçao e 
     * acidente verifica se ocorreu ou nao um acidente */
    
    int vetorX[MAX], nX, nY, i, caixa = 0, acidente = 0;
    char comando;
    
    scanf ("%d %d", &nX, &nY);
    
    for (i = 0; i < nX; i++)
        scanf ("%d", &vetorX[i]);
    
    /* Comando de repetiçao que lê todos os comandos e executa o que cada
comando pede */
    
    i = 0;
    do {
        scanf ("%c", &comando);
        if (comando == 'D') {
            
            /* Verifica se há caixas na coluna e se há uma caixa no robô */
            
            if ((caixa == 0) && (vetorX[i] > 0)){
                vetorX[i]--;
                caixa = 1;
            } else if ((caixa == 1) && (vetorX[i] < nY)) {
                vetorX[i]++;
                caixa = 0;
            }
        } else if (comando == 'R') {
            
            /* Verifica se o robô está no intervalo do vetorX */
            
            if ((i >= 0) && (i < nX - 1)) {
                i++;
                
                /* Verifica se a caixa do robô esbarrou em outra empilhada */
                
                if ((vetorX[i] == nY) && (caixa == 1)) {
                    printf ("Um acidente ocorreu\n");  
                    acidente = 1;
                }
            }          
        } else if (comando == 'L') {
            
            /* Verifica se o robô está no intervalo do vetorX */
            
            if ((i > 0) && (i < nX)) {
                i--;
                
                /* Verifica se a caixa do robô esbarrou em outra empilhada */
                
                if ((vetorX[i] == nY) && (caixa == 1)) {
                    printf ("Um acidente ocorreu\n");
                    acidente = 1;
                }
            }
        }
    } while ((comando != '*') && (!acidente));
    
    /* Se nao ocorreu acidente, imprimimos a nova quantidade de caixas em cada
coluna */
    
    if (!acidente) {       
        for (i = 0; i < nX - 1; i++)
            printf ("%d ", vetorX[i]);       
        printf ("%d\n", vetorX[i]);
    }
    
    return 0;
}