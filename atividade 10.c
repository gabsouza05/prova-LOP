#include <stdio.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto produto;

void cadastrarProduto();
void visualizarProduto();
void comprarProduto();

int main() {
    int opcao;
    
    while (1) {
        printf("---- SuperMais ----\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Visualizar produto\n");
        printf("3 - Comprar produto\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        if(opcao == 1) {
            cadastrarProduto();
        } else if (opcao == 2) {
            visualizarProduto();
        } else if (opcao == 3) { 
            comprarProduto();
        } else if (opcao == 0) { 
            printf("Saindo do sistema...\n");
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
    
    return 0;
}

void cadastrarProduto() {
    printf("\nCadastrar produto\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", produto.nome);
    printf("Preço: ");
    scanf("%f", &produto.preco);
    printf("Quantidade: ");
    scanf("%d", &produto.quantidade);
    printf("Produto cadastrado com sucesso!\n");
}

void visualizarProduto() {
    printf("\nInformações do produto\n");
    printf("Nome: %s\n", produto.nome);
    printf("Preço: R$%.2f\n", produto.preco);
    printf("Quantidade: %d\n", produto.quantidade);
}

void comprarProduto() {
    int qtdCompra;
    printf("\nComprar Produto\n");
    printf("Quantos deseja comprar? ");
    scanf("%d", &qtdCompra);
    
    if(qtdCompra <= produto.quantidade) {
        produto.quantidade -= qtdCompra;
        printf("Compra realizada! Estoque restante: %d\n", produto.quantidade);
    } else {
        printf("Estoque insuficiente! Apenas %d disponível.\n", produto.quantidade);
    }
}