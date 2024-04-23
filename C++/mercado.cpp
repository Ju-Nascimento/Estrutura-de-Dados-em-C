#include <stdio.h>
#include <string.h>

#define Produtos_Max 10

/* Esse codigo faz uma gestão simples de um estoque de supermercado
utilizando structs*/

struct Produto {
    char nome[50];
    char segmento[15];
    char unidade[4];
    int quantidade;
    int quantVendida;
    float valorVendido;
    float precoVenda;
    float precoCompra;
};

void registrarProduto(struct Produto *produto) {
    printf("Nome do produto: ");
    scanf("%s", produto->nome);

    printf("Digite o tipo do produto: Limpeza, Alimento, Bebida, Higiene: ");
    scanf("%s", produto->segmento);

    printf("Digite o valor da compra: ");
    scanf("%f", &produto->precoCompra);

    printf("Digite o valor da venda: ");
    scanf("%f", &produto->precoVenda);

    printf("Unidade: KG, G, ML, Un.: ");
    scanf("%s", produto->unidade);

    printf("Quantidade no estoque: ");
    scanf("%d", &produto->quantidade);
}

void relatorio(struct Produto produto) {
    printf("Nome: %s \n", produto.nome);
    printf("Tipo: %s \n", produto.segmento);
    printf("Preço de compra: R$ %.2f\n", produto.precoCompra);
    printf("Preço de venda: R$ %.2f \n", produto.precoVenda);
    printf("Unidade: %s\n", produto.unidade);
    printf("Quantidade em estoque: %d %s\n", produto.quantidade, produto.unidade);
    printf("-----------------------------\n");
}

int main() { 
	
    Produto produtos[Produtos_Max];
    int indProdutos = 0;

    printf("Digite os dados de %d itens: \n", Produtos_Max);

    int continuar;

    do {
        printf("\nProduto %d: \n", indProdutos + 1);
        registrarProduto(&produtos[indProdutos]);
        indProdutos++;

        printf("Deseja cadastrar outro produto? (1 - sim, 2 - nao): ");
		scanf("%d", &continuar);

    }while (continuar == 1);

    printf("\nRelatorio do Estoque:\n");
    for (int i = 0; i < indProdutos; i++) {
        relatorio(produtos[i]);
    }

    return 0;
}

