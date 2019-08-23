/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855
 * Laboratorio 02a - Coeficiente de Rendimento */

#include <stdio.h>

/* Programa para calculo do CR de alunos da pos-graduacao */

int main() {
    char N;
    int credito, soma1 = 0, soma2 = 0;
    double CR = 1; 
    
    /* Verificando se o aluno cursou alguma disciplina */
    
    scanf ("%c", &N);
    
    if (N == '*') {
        printf ("CR = Indefinido\n");
    } else {
        /* Caso ele tenha feito alguma, segue abaixo o calculo
           do seu CR */
        while (N != '*') {
            scanf ("%d", &credito);
            soma1 += credito; 
            if (N == 'A') {
                soma2 += credito * 4;
            } else if (N == 'B') {
                soma2 += credito * 3;
            } else if (N == 'C') {
                soma2 += credito * 2;
            } else if (N == 'D') {
                soma2 += credito;
            } else if (N == 'E') {
                soma2 += credito * 0;
            }
        
            scanf (" %c", &N);
        }
       
        CR = (double) soma2 / soma1;
        printf ("CR = %.4f\n", CR);
    }    
    
    return 0;
}
        
        