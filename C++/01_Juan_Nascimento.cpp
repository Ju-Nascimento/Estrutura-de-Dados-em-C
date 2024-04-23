#include <stdio.h>

/* Este código desenha um quadrado na tela utilizando o caractere '#'. 
 O usuário digita a dimensão do quadrado, e o programa preenche uma matriz com o caractere '#' 
 e imprime na tela, criando a imagem do quadrado */

int main( ) {
    char matrix[100][100];
    int tamanho;

    printf("Digite a dimensao do quadrado: ");
    scanf("%d", &tamanho);

    
    for (int i = 0; i < tamanho; i++) {
        for (int x = 0; x < tamanho; x++) {
            matrix[i][x] = '#'; 
        }
    }

    for (int i = 0; i < tamanho; i++) {
        for (int x = 0; x < tamanho; x++) {
            printf("%c ", matrix[i][x]);
        }
        printf("\n");
    }

    return 0;
}

