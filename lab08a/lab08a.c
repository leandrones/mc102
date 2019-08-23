/* Laboratorio 08a - BigCalc
 * Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855 
 */

/* Programa que calcula soma, subtracao e multiplicacao de numeros com muitos
algarismos, armazenando cada um destes em uma posiçao de um vetor */
/* Este programa sempre executa as suas operacoes a partir do fim do vetor que
contem as entradas e o resultado */
#include <stdio.h>
#include <stdlib.h>

/* realiza a adicao n1+n2, armazenando o resultado em result */
void add(int *n1, int tam_n1, int *n2, int tam_n2, int *result) { 
    int i, soma;    
    /* Zerando vetor result */
    for (i = 0;i <= tam_n1; i++)
        result[i] = 0;
    
    /* Faz a soma, percorrendo o menor numero a partir do ultimo algarismo */
    for (i = 0; i < tam_n2; i++) {
        soma = n1[tam_n1-1-i] + n2[tam_n2-1-i];
        result[tam_n1 - i] += soma % 10; /* Ultimo elemento do vetor */
        result[tam_n1-1-i] += soma / 10;/* Elemento antecessor a ele */
    }

    /* Copia, caso necessario, os algarismos restantes do maior numero 
     * Ela começa a partir do ultimo valor de i alterado pelo for acima */
    while (i < tam_n1) {
        result[tam_n1 - i] += n1[tam_n1-1-i];
        i++;
    }    
    
    /* Exclui o possivel zero do vetor resultado para a correta impressao */
    i = 0;
    if (result[i] == 0)
        i++;
    
    /* Impressao do resultado final */
    for (; i <= tam_n1; i++)
        printf ("%d", result[i]);
    printf ("\n");
}

/* realiza a subtracao n1-n2, com n1>=n2, armazenando o resultado em result */
void substract(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
    int i, sub;
    
    /* Zerando vetor result */
    for (i = 0;i < tam_n1; i++)
        result[i] = 0;
    
  /* Faz a subtracao, percorrendo o menor numero a partir do ultimo algarismo*/
    for (i = 0; i < tam_n2; i++) {
        sub = n1[tam_n1 - 1 - i] - n2[tam_n2 - 1 - i];
        if (sub < 0) {
            sub += 10;/* Se negativo, some 10 e o corrija para positivo */
            n1[tam_n1 - 2 - i]--;/* Decrementa o elemento antecessor */
        }
        result[tam_n1 - 1 - i] = sub;
    }
    
  /* Se necessario, continua decrementando e corrigindo os outros algarismos */
    while (i < tam_n1) {
        if (n1[tam_n1 - 1 - i] < 0) {
            result[tam_n1 - 1 - i] = n1[tam_n1 - 1 - i] + 10;
            n1[tam_n1 - 2 - i]--;
        } else
            result[tam_n1 - 1 - i] = n1[tam_n1 - 1 - i];
        i++;
    }  
    
    /* Exclui os possiveis zeros do vetor resultado para a correta impressao */
    i = 0;
    while ((i < tam_n1 - 1) && (result[i] == 0))
        i++;
    
    /* Impressao do resultado final */
    for (; i < tam_n1; i++)
        printf ("%d", result[i]);
    printf ("\n");
}

/* realiza a multiplicacao n1*n2, armazenando o resultado em result */
void multiply(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
    int i, j, prod, aux;
    int tam_prod = tam_n1 + tam_n2;
    
    /* Zerando vetor result */
    for (i = 0; i < tam_prod; i++) 
        result[i] = 0;
    
   /* Faz o produto, percorrendo o menor numero a partir do ultimo algarismo*/
    for (i = 0; i < tam_n2; i++) {
        for (j = 0; j < tam_n1; j++) {
            prod = n2[tam_n2-1-i] * n1[tam_n1 - 1 - j];
            result[tam_prod-1-i-j] += prod % 10;                
            result[tam_prod-2-i-j] += prod / 10;
        }
    }
    
    /* Deixa os numeros com mais de um algarismo com apenas um */
    for (i = 0; i < tam_prod - 1; i++) {
        aux = result[tam_prod-1-i];
        result[tam_prod-1-i] = result[tam_prod-1-i] % 10;
        result[tam_prod-2-i] += aux / 10;/* Soma-se as dezenas ao antecessor */
    }        
    
    /* Exclui o possivel zero do vetor resultado para a correta impressao */
    i = 0;
    while ((i < tam_prod - 1) && (result[i] == 0))
        i++;
    
    /* Impressao do resultado final */
    for (; i < tam_prod; i++)
        printf ("%d", result[i]);
    printf ("\n");
}

int main() {  
    /* digA e digB sao os numeros de digitos de cada vetor 
     * numA e numB sao as strings de entrada 
     * num1 e num2 sao os vetores de inteiros equivalentes as strings */
    int i, digA, digB;
    char convert, operacao;
    int *numA, *numB, *resultado;   
    
    /* Leitura da linha 1 da entrada */
    scanf ("%d %d %c", &digA, &digB, &operacao);
    
    /* Alocaçao das variaveis */
    numA = malloc (digA * sizeof (int));
    numB = malloc (digB * sizeof (int));
       
        
    /* Conversao de char para inteiros */
    for (i = 0; i < digA; i++) {
        scanf (" %c", &convert);
        numA[i] = convert - '0';
    }
    
    for (i = 0; i < digB; i++) {
        scanf (" %c", &convert);
        numB[i] = convert - '0';
    }
    
    /* Executa a operacao solicitada , chamando a respectica funçao */
    if (operacao == 'A') {            
        /* Alocaçao do tamanho maximo possivel para o resultado */
        resultado = malloc ((digA + 1) * sizeof(int)); 
        add (numA, digA, numB, digB, resultado);
    }    
    else if (operacao == 'S') {
        /* Alocaçao do tamanho maximo possivel para o resultado */
        resultado = malloc (digA * sizeof(int));
        substract (numA, digA, numB, digB, resultado);
    }
    else if (operacao == 'M') {
        /* Alocaçao do tamanho maximo possivel para o resultado */
        resultado = malloc ((digA + digB) * sizeof(int));
        multiply (numA, digA, numB, digB, resultado);
    }  
    
    free(resultado);
    free(numA);
    free(numB);
    
    return 0;
}