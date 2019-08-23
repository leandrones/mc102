/* Laboratorio 13a - Hanabi  
 * Autor: Leandro Nascimento Gonçalves de Araujo 171855 
 * Email: ra171855@students.ic.unicamp.br
 */

/* Programa que calcula a maior altura da arvore de queima */

#include <stdio.h>


/* Funcao recursiva que calcula essa altura */
int height (int m) {
    int i, n;
    int altura, maxaltura = 1;    
    
    /* Caso base */
    if (m == 0)
        return maxaltura;
    else {
        for (i = 0; i < m; i++) { /* Chama a recursao m vezes */
            scanf ("%d", &n);            
                altura = height(n) + 1;
                if (altura > maxaltura)
                    maxaltura = altura;             
        }
    }

    return maxaltura;
}

int main() {
    /* n eh o numero de ramificacoes de uma bomba */
    int n;
    int altura;    
        
    /* Leitura da primeira bomba */
    scanf ("%d", &n);
    
    altura = height(n);
    
    /* Impressao do resultado */
    printf ("%d\n", altura);
    
    return 0;
}


