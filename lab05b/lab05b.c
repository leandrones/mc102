/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855 
 * Laboratorio 05b - Distância de Tchonsky */

#include <stdio.h>
#define MAX 100

/* Programa para calcular a Distância de Tchonsky entre duas palavras */

int main() {
    /* C eh o numero de letras comuns entre as duas palavras 
     * igual mostra se dois caracteres são iguais 
     * e D eh a Distância de Tchonsky */
    char stringA[MAX + 1], stringB[MAX + 1];
    int i, j, tamA = 0, tamB = 0, D, C = 0, igual;
    
    scanf ("%s ", stringA);
    scanf ("%s", stringB);
    
    /* Determinação do tamanho das palavras */
    
    while (stringA[tamA])
        tamA++;
    
    while (stringB[tamB])
        tamB++;
    
    /* Verifica se há letras maiúsculas nas palavras */
    
    for (i = 0; i < tamA; i++) 
        if ((stringA[i] >= 'A') && (stringA[i] <= 'Z'))
            stringA[i] += 32; /* Transforma em minusculo (ASC II) */
            
            
    for (i = 0; i < tamB; i++) 
        if ((stringB[i] >= 'A') && (stringB[i] <= 'Z'))
            stringB[i] += 32; /* Transforma em minusculo (ASC II) */ 
            
    /* Verifica se há uma letra da stringA igual à da stringB e calcula o 
    número de letras em comum */    
    
    for (i = 0; i < tamA; i++) {
        igual = 0;
        for (j = 0; (j < tamB)  && (!igual); j++) {
            if (stringA[i] == stringB[j]) {
                stringB[j] = 0; /* Essa letra não será contada de novo */
                igual = 1;
                C++;
            }
        }
    }
    
    D = (tamA + tamB) - (2 * C);
    
    printf ("Distancia de Tchonsky = %d\n", D);
    
    return 0;
}
    
    
    
  