/* Laboratorio 10a -Tag Cloud  
 * Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855 
 */

/* Programa que determina quais serao as palavras de um texto que terao 
 * destaque em uma tag cloud */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Funçao que retorna o indice do maior elemento */
int indiceMaior(int vet[], int n, int inicio) {
    int k, max = inicio;
    
    for (k = inicio + 1; k < n; k++)
        if (vet[max] < vet[k])
            max = k;
        
    return max;
}

/* Funçao que ordena o vetor contador e suas palavras de forma decrescente */
void OrdemDecresc (int vet[], char **string, int n, int tam) {
    int i, k, max, numaux, flag = 1;
    char *aux;
    
    /* Alocando string auxiliar */
    aux = malloc (tam * sizeof (char));
    
    /* Ordenando o vetor */
    for (i = 0; i < n - 1; i++) {
        max = indiceMaior (vet, n, i);
        numaux = vet[max]; /* Troca de variaveis */
        vet[max] = vet[i];
        vet[i] = numaux;
        strcpy (aux, string[max]);
        strcpy (string[max], string[i]);
        strcpy (string[i], aux);
    }    
        
    /* Poe em ordem alfabetica palavras com mesma frequencia */
    for (k = n -1; (k >= 0) && (flag); k--) {
        flag = 0;        
        for (i = 0; i < k; i++) {
            if (vet[i] == vet[i+1]) {
                if (strcmp (string[i], string[i+1]) > 0) {
                    strcpy (aux, string[i+1]);
                    strcpy (string[i+1], string[i]);
                    strcpy (string[i], aux);
                    flag = 1;
                }
            }
        }
    }
    
    /* Desaloca string auxiliar */
    free (aux);
}

int main () {
    /* Vetor de strings e string temporaria */
    char **palavras, *temp;    
    /* Vetor que conta as frequencias das palavras */
    int *contador;
    /* D eh o numero maximo de palavras distintas no texto 
     * F eh o numero minimo de frequencia da palavra para ser impressa 
     * L eh o tamanho minimo da palavra para ela ser impressa 
     * M eh o tamanho maximo da palavra no texto */
    int D, F, L, M;
    /* i, j e igual sao indices 
     * tam eh o tamanho da string */
    int i, j, tam, flag, igual;
        
    /* Leitura de dados */
    scanf ("%d %d %d %d", &D, &F, &L, &M);
   
    /* Alocaçao dinamica de vetores */
    palavras = malloc (D * sizeof (char*));
    
    for (i = 0; i < D; i++) 
        palavras[i] = malloc (M * sizeof (char));
    
    temp = malloc (M * sizeof (char));
    
    contador = malloc (D * sizeof (int));
    
    /* Inicializaçao do contador */
    for (i = 0; i < D; i++) 
        contador[i] = 1;
    
    /* Leitura da primeira palavra */
    scanf ("%s", palavras[0]);
    
    /* Bloco principal que determina as palavras para a tag cloud */
    j = 1;
    do {
        scanf ("%s", temp);
        tam = strlen (temp);
        flag = 1;
        /* Verifica se a palavra tem o tamanho ideal */
        if ((tam >= L) && (tam <= M)) {
            for (i = 0; (i < j) && (flag); i++) {
                if (strcmp (palavras[i], temp) == 0) { 
                    flag = 0;           
                    igual = i;
                }
            }
            /* Se eh uma nova palavra, copia para o vetor de string */
            if (flag) {              
                strcpy (palavras[j], temp);
                j++;               
            }
            /* Caso contrario, soma no contador da palavra repetida */
            else 
                contador[igual] += 1;            
        }        
    } while ((temp[0] != '*') && (j < D));    
    
    /* Ordena o vetor contador */
    OrdemDecresc (contador, palavras, j, M);
    
    /* Impressao de resultados */
    for (i = 0; i < j; i++) {
        if (contador[i] >= F)
            printf ("%s %d\n", palavras[i], contador[i]);
    }
    
    /* Desalocaçao de memoria */
    for (i = 0; i < D; i++) 
        free (palavras[i]);
    free (palavras);
    
    free (temp);
    free (contador);
    
    return 0;
}

