#include <stdio.h>
#include <string.h>

/* Utilizando a biblioteca de strings de C e ponteiros, esse codigo conta quantas vezes o termo "cara"
aparece no vetor de texto*/

int contar(char *texto, char *termo) {
    int cont = 0;
    char *pos = texto;

    while ((pos = strstr(pos, termo)) != NULL) {
        cont++;
        pos += strlen(termo); 
    }

    return cont;
}

int main( ) {
    char texto[] = "cara caramba, cara caraô\n"
                   "cara caramba, cara caraô\n"
                   "cara caramba, cara caraô\n"
                   "cara caramba, cara caraô";

    char termo[ ] = "cara";

    int ocorrencias = contar (texto, termo);

    printf("O termo '%s' aparece %d vezes no texto.\n", termo, ocorrencias);

    return 0;
}

