/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855 
 * Laboratorio 02b - Dólares Élficos */

#include <stdio.h>
/* Programa para calcular o numero minimo de notas
 para Merry e Pippin carregarem */
int main () {
    /* N eh o numero de casas de cambio ]
     * G eh a qtde em gramas de ouro 
     * C eh a taxa de cambio 
     * i eh um indice 
     * e n min eh o numero minimo de notas */
    
    int N, G, C, i, DolElf;
    int base, divisao, notas, nmin = 1000000;
    
    scanf ("%d %d %d", &N, &G, &C);
    
    DolElf = G * C;
    
    for (i = 1; i <= N; i++) {      
        scanf ("%d", &base);
        notas = 0;
        divisao = DolElf;
        while (divisao >= base) {
            notas += divisao % base;
            divisao = divisao / base;
        }
        notas += divisao;
        if (notas < nmin)
            nmin = notas;
        
            
    }
    
    printf ("Numero minimo de notas = %d\n", nmin);
    
    return 0;
}