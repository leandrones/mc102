#include <stdio.h>
#include <string.h>

/* Programa que extrai os tweets do usuario em uma pagina html */
#define MAX_FILENAME 25
#define MAX_ENTITY 10

/* Funcao que converte uma entidade no caractere correspondente,
   supondo que o caractere '&' foi previamente lido no arquivo de
   entrada (arqin). Se a entidade eh diferente de aspas simples ou
   aspas dupla, a funcao simplesmente o ignora, caso contrario ela
   imprime o caractere correspondente no arquivo de saida (arqout). */
void converte_entidade(FILE *arqin, FILE *arqout) {
    char c, entidade[MAX_ENTITY];
    int i = 0;
    
    /* armazena o codigo da entidade ate encontrar o caractere ';' */
    c = fgetc(arqin);
    while (c != ';') {
        printf ("%c\n", c);
        entidade[i++] = c;
        c = fgetc(arqin);
    }
    entidade[i] = '\0';
    
    /* se a entidade corresponde ao caractere aspas simples ou aspas duplas,
       imprime o caractere no arquivo de saida */
    if (!strcmp(entidade, "#39"))
        fprintf(arqout, "\'");
    else if(!strcmp(entidade, "quot"))
        fprintf(arqout, "\"");
}

/* Funcao principal que encontra os tweets e os impime no arquivo de saida */
void extrai_tweets (char *nomearqin, char *nomearqout) {
    /* arqin e arqout sao ponteiros dos arquivos de entrada e saida */
    FILE *arqin, *arqout;
    /* aux e menorq sao auxiliares de leitura */
    char aux, menorq;    
    /* key eh a string necessaria para saber se eh um tweet do usuario */
    char key[47] = " class=\"ProfileTweet-text js-tweet-text u-dir\"";
    /* string auxiliar que eh comparada com a key */
    char straux[47];
    /* fim eh uma flag que determina se acabou o tweet */
    int fim;
        
    /* Abrindo os arquivos */
    arqin = fopen(nomearqin, "r");
    arqout = fopen(nomearqout, "w");
    
    while (fscanf(arqin, "%c", &aux) != EOF) {
        if (aux == '<') {
            fscanf(arqin, "%c", &aux);
            if (aux == 'p') {
                printf ("Entrei no 1 if\n");     
                fgets (straux, 47, arqin);
                /***for (i = 0; i < 47; i++) {
                    fscanf(arqin, "%c", &aux);
                    straux[i] = aux;
                } 
                straux[i] = '\0';*/
                if (strcmp(straux, key) == 0) {
                    printf ("Entrei no 2 if %d\n", j);
                    j++;
                    fim = 0;
                    do {
                        fscanf(arqin, "%c", &aux);
                    } while (aux != '>');
                    while (fim == 0) {                    
                        do {
                            fscanf(arqin, "%c", &aux); 
                            if (aux == '&') {
                                printf ("Entrei no aux %c\n", aux);
                                converte_entidade(arqin, arqout);
                            }
                            else if ((aux != '>') && (aux != '<')) {
                                fprintf (arqout, "%c", aux);         
                                printf ("%c", aux);
                            }
                        } while ((aux != '>') && (aux != '<'));
                        do {
                            menorq = aux;
                            if (menorq== '<') {
                                fscanf(arqin, "%c", &aux);
                                if (aux == '/') {
                                    fscanf(arqin, "%c", &aux);
                                    if (aux == 'p') {                        
                                        fim = 1;
                                        fprintf (arqout, "\n");
                                        printf ("Dei enter\n");
                                    }
                                }
                            }
                            fscanf(arqin, "%c", &aux);
                        } while (aux != '>');
                    }
                }
            }
        }        
    }
    
    fclose(arqin);
    fclose(arqout);
}

                
    
    

int main(int argc, char *argv[]) {  
    char nomearqin[MAX_FILENAME], nomearqout[MAX_FILENAME];
    
    /* Copia os nomes do arquivo de entrada e de saida nas variaveis */
    strcpy(nomearqin, argv[1]);
    strcpy(nomearqout, argv[2]);
 
    extrai_tweets(nomearqin, nomearqout);

    return 0;   
}