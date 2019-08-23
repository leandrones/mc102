/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855 
 * Laboratorio 03a - Admirável Mundo Novo */

#include <stdio.h>
/* Programa para determinar o numero total de nascimentos das criancas e a 
quantidade bruta e porcentual de nascimentos em cada casta */
int main () {
    char crianca;
    int casta[9];
    int n, c, i, j, total = 0;
    double perc;
    
    /* Leitura do numero de lotes de criancas (n) e do numero de castas (c)*/
    
    scanf ("%d %d ", &n, &c);
    
    /* Inicializando vetor */
    
    for (i = 0; i < c; i++)
        casta[i] = 0; 
    
    /* Leitura para identificaçao das criancas e calculo do total e da qtde 
bruta de nascimentos*/
        
    scanf ("%c", &crianca);
    
    total++;
    
    for (j = 0; j < c; j++) {
        if (j + 1 == crianca - '0')
            casta[j]++;
    }
    
    for (i = 0; i < n; i++) {        
        do { 
            scanf ("%c", &crianca);            
            for (j = 0; j < c; j++) {
                if (j + 1 == crianca - '0') {
                    casta[j]++;
                    total++;
                }
            }
        } while (crianca != '\n');
    }
    
    /* Calculo do percentual das castas e impressao dos dados */
    
    printf ("Total: %d individuos\n", total);
    
    for (i = 0; i < c; i++) {        
        printf ("Total da casta %d: %d\n", i + 1, casta[i]);
    }
    
    for (i = 0; i < c; i++) {
        perc = (double) 100 * casta[i] / total;
        printf ("Percentual da casta %d: %.2f\n", i + 1, perc);
    }
    
    return 0;
}
    
 