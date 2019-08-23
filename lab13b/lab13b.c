/* Laboratorio 13b - Quadtree   
 * Autor: Leandro Nascimento Gonçalves de Araujo 171855 
 * Email: ra171855@students.ic.unicamp.br
 */

/* Programa que calcula o numero de regioes homogeneas em uma quadtree de uma 
   imagem em preto e branco */
#include <stdio.h>
#include <stdlib.h>

/* Funcao que aloca dinamicamente uma matriz */
int ** aloca_matriz(int linhas, int colunas) {
    int i, **matriz;
    
    matriz = malloc(linhas * sizeof(int *));
    
    for (i = 0; i < linhas; i++)
        matriz[i] = malloc(colunas * sizeof(int));
    
    return matriz;
}

/* Funcao que desaloca uma matriz alocada dinamicamente */
void desaloca_matriz(int **matriz, int linhas) {
    int i;
    
    for (i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);
    
}

/*Funcao recursiva que calcula o numero de regioes */
int calcRegioes (int **img, int k, int l, int n) {
    int i, j;
    int regioes = 0;
    int temZero = 0, temUm = 0;
    
    /* Verifica se a matriz eh homogenea ou nao */
    for (i = k; (i < n+k) && ((!temUm) || (!temZero)); i++) {
        for (j = l; (j < n+l) && ((!temUm) || (!temZero)); j++) {
            if (img[i][j] == 0)
                temZero = 1;
            else if (img[i][j] == 1)
                temUm = 1;
        }
    }
    
    /* Divide a matriz em quatro segmentos se ela for homogenea */
    if ((temUm) && (temZero)) {
        regioes += calcRegioes(img, k, l, n/2);
        regioes += calcRegioes(img, k, l+n/2, n/2);
        regioes += calcRegioes(img, k+n/2, l, n/2);
        regioes += calcRegioes(img, k+n/2, l+n/2, n/2);
    }
    /* caso base */
    else
        return 1;
    
    return regioes;    
}

int main() {
    int **img;
    /*n = numero de linhas e colunas da matriz imagem quadrada */
    int n;
    /* regioes = contador do numero de regioes */
    int regioes;
    /* i, j sao indices auxiliares */
    int i , j;
    
    scanf ("%d", &n);
    
    img = aloca_matriz(n, n);
    
    /* Le a matriz */
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++)
            scanf("%d", &img[i][j]);
        
    /* Calculo do numero de regioes */    
    regioes = calcRegioes(img, 0, 0, n);
    
    desaloca_matriz (img, n);    
    
    /*Impressao de resultado */
    printf ("Numero de regioes = %d\n", regioes);
    
    return 0;     
}