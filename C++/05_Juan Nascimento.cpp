#include <stdio.h>
#include <string.h>


struct Aluno {
    int matricula;
    char nome[50];
    char curso[50];
};

// Trocando os elementos de lugar no array
void trocar(Aluno *a, Aluno *b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

// Função de comparação para ordenar os alunos por nome
int comparar_nomes(const void *a, const void *b) {
    return strcmp(((Aluno *)a)->nome, ((Aluno *)b)->nome);
}

// Ordenando os alunos com bublle sort
void bubbleSort(Aluno array[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(array[j].nome, array[j+1].nome) > 0) {
                trocar(&array[j], &array[j+1]);
            }
        }
    }
}

int main() {
    const char* arquivo = "database_alunos.txt";
    const int MAX_ALUNOS = 100;
    Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;

    // Abrir o arquivo para leitura
    FILE *leituraArquivo = fopen(arquivo, "r");
    if (!leituraArquivo) {
        printf("Não foi possivel ler o arquivo. %s\n", arquivo);
    }

    // Ler os alunos do arquivo e armazená-los no array de alunos
    while (fscanf(leituraArquivo, "%d %[^\n] %[^\n]", &alunos[numAlunos].matricula, alunos[numAlunos].nome, alunos[numAlunos].curso) == 3) {
        numAlunos++;
    }

    fclose(leituraArquivo);

    // Ordenar o array de alunos
    bubbleSort(alunos, numAlunos);

    // Abrir o arquivo para escrita
    FILE *escreveArquivo = fopen(arquivo, "w");
    if (!escreveArquivo) {
        printf("Erro ao abrir o arquivo %s para escrever.\n", arquivo);
    }

    // Escrever os alunos ordenados no arquivo
    for (int i = 0; i < numAlunos; i++) {
        fprintf(escreveArquivo, " %d %s %s \n", alunos[i].matricula, alunos[i].nome, alunos[i].curso);
    }

    fclose(escreveArquivo);

    printf("Alunos ordenados e escritos no %s \n", arquivo);

    return 0;
}
