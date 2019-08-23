/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855
 * Laboratorio 01a */

#include <stdio.h>
#include <math.h>

/* Programa para calcular montante e o numero de lotes q tem q ser vendidos */

int main () {
    int n;
    double C, i, M, M2;
    scanf ("%lf %lf %d %lf", &C, &i, &n, &M);
    
    i = i / 100;
   
    /*Calculo de um Montante M2 dados os valores C, i e n */
    M2 = C * pow((1 + i),n);
    
    /* Calculo do numero de lotes n a partir de M, C e i */
    n = ceil(log(M / C) / log(1 + i));
    
    printf ("Montante = %.2f\n", M2);
    printf ("%d lote(s)\n", n);
    
    return 0;
}