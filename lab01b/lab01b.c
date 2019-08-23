/* Nome: Leandro Nascimento Gonçalves de Araujo
 * RA: 171855
 * Laboratorio 01b */

#include <stdio.h>

/* Programa para calcular Tarifa de Agua */

int main () {
    /* Ca eh o consumo atual do mes e Cm eh o consumo medio do ano anterior */
    int Ca, Cm;
    double Vo, Vf;
    
    scanf("%d %d", &Cm, &Ca);
    
    /* Calculo do Valor original (Vo) */
    
    if (Ca <= 10) {
        Vo = 17.34;
    } else if ((Ca > 10) && (Ca<= 20)) {
        Vo = 17.34 + (Ca - 10) * 2.41;
    } else if ((Ca > 20) && (Ca <= 50)) {
        Vo = 17.34 + 10 * 2.41 + (Ca - 30) * 3.7;
    } else {
        Vo = 17.34 + 10 * 2.41 + 30 * 3.7 + (Ca - 50) * 4.43;
    }
    
    /* Calculo do Valor final (Vf), caso haja reducao ou aumento do consumo em 
relacao a media do ano anterior */
    
    if ((Ca <= 0.9 * Cm) && (Ca > 0.85 * Cm)) {
        Vf = 0.9 * Vo;
    } else if ((Ca <= 0.85 * Cm) && (Ca > 0.8 * Cm)) {
        Vf = 0.8 * Vo;
    } else if (Ca <= 0.8 * Cm) { 
        Vf = 0.7 * Vo;
    } else if ((Ca > Cm) && (Ca < 1.2 * Cm)) {
        Vf = 1.2 * Vo;
    } else if (Ca >= 1.2 * Cm) {
        Vf = 2 * Vo;
    } else {
        Vf = Vo;
    }
    
    printf ("Valor original = %.2f\n", Vo);
    printf ("Valor final = %.2f\n", Vf);
    
    return 0;
}
    