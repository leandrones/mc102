/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855 
 * Laboratorio 06a - Raio Sugestor */

/* Programa que calcula a quantidade máxima de pessoas atingidas pelo raio
 * sugestor */

#include <stdio.h>
#define MAX 50

int main () {
    /* m eh o numero de linhas, n o de colunas da matriz 
     * r eh o alcance do raio 
     * d eh o numero de linhas do quadrado de açao do raio 
     * a e b sao indices auxiliares que ajudam a percorrer os quarteiroes 
     * soma eh o numero de pessoas atingidas */
    int quarteirao[MAX][MAX];
    int n, m, r, i, j, k, l, a, b, d;
    int soma, maiorsoma = 0;
    
    scanf ("%d %d %d", &m, &n, &r);
    
    /* Cálculo de d */
    d = 2 * r + 1;
    
    /* Leitura do numero de pessoas em cada quarteirao */
    
    for (i = 0; i < m; i++) 
        for (j = 0; j < n; j++) 
            scanf ("%d", &quarteirao[i][j]);
        
        /* Percorrendo todos os quarteiroes da matriz de d em d linhas e colunas
         * para que se determine a regiao mais favorável para a colocação do 
         * raio */
        
        for (i = 0, a = d; i < m - (d - 1); i++, a++) {
            for (j = 0, b = d; j < n - (d - 1); j++, b++) {
                soma = 0;
                for (k = j; k < b; k++){
                    for (l = i; l < a; l++) {
                        soma += quarteirao[l][k];
                    }
                }
                if (soma >= maiorsoma)
                    maiorsoma = soma;
            }
        }
        
        /* Imprimindo o resultado encontrado */
        
        printf ("%d\n", maiorsoma);
        
        return 0;
        
}