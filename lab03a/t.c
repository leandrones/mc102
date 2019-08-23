/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855 
 * Laboratorio 03b - O Enigma dos Guardiões Quânticos */

#include <stdio.h>
#define MAX 100

int main () {
    int N, i, j, min, max, guardiao[MAX], interv, maior = 0;
        
    scanf ("%d", &N);
    
    for (i = 0; i < N; i++)
        guardiao[i] = 0;
    
    for (i = 0; i < N; i++) {
        scanf ("%d %d", &min, &max);
        interv = max - min;
        for (j = 0; j <= interv; j++) {
            guardiao[min]++;
            min++;
        }            
    }
    
    for (i = 0; i < N; i++) {
        if (guardiao[i] == i) {
            maior = i;
        }
    }
    
    printf ("Numero de guardioes sinceros = %d\n", maior);
    
    return 0;
}