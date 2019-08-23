/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855 
 * Laboratorio 05a - Necronomicon */

/* Programa para verificar se uma palavra eh subsequencia da outra */

#include <stdio.h>
#define MAX 21
int main() {
    /* palavra1 eh a possivel subsequencia 
     * igual mostra se um caracter eh igual ao outro 
     * e n eh o numero de pares de palavras a serem testadas */
    char palavra1[MAX], palavra2[MAX];
    int n, i, j, k, tam1, tam2, igual;
    
    scanf ("%d ", &n);
    
    for (i = 0; i < n; i++) {
        scanf ("%s ", palavra1);
        scanf ("%s", palavra2);
        
        tam1 = 0;
        tam2 = 0;
        
        /* Calculando os tamanhos das palavras */
        
        while (palavra1[tam1])
            tam1++;
        while (palavra2[tam2])
            tam2++;
        
        /* Percorre as duas palavras verficando se na palavra2 existem todos 
os caracteres da palavra1 na mesma ordem */
        
        k = 0;
        
        for (j = 0; (j < tam1) && (k < tam2); j++) {
            igual = 0;
            for (; (k < tam2) && (!igual); k++) {                
                if (palavra1[j] == palavra2[k]) {
                    igual = 1;
                }
            }
        }            
        
        /* Verifica se foi achada uma subsequencia */
        
        if (j == tam1)
            printf ("Sim\n");
        else 
            printf ("Nao\n");
    }
    
    return 0;
}
            