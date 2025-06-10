#include <stdio.h>

typedef struct {
    int ano;
    int quantidade;
    float preco;
} CD;

int main() {
    CD cd;
    int vendas, quantidadeVendida;
    float total;
    
    printf("---- Loja Som & Arte ----\n");
    printf("Ano de lançamento: ");
    scanf("%d", &cd.ano);
    printf("Quantidade em estoque: ");
    scanf("%d", &cd.quantidade);
    printf("Preço do CD: R$");
    scanf("%f", &cd.preco);
    
    printf("Deseja realizar uma venda? (1 para 'Sim' ou 0 para 'Não': ");
    scanf("%d", &quantidadeVendida);
    
    if (vendas == 1) {
        printf("Quantos CDs deseja vender?: ");
        scanf("%d", &quantidadeVendida);
        if (quantidadeVendida <= 0) {
        printf("Erro: A quantidadevendida deve ser maior que zero!\n");
    } else if (quantidadeVendida <= cd.quantidade) {
        cd.quantidade -= quantidadeVendida;
        total = quantidadeVendida * cd.preco; 
        printf("Venda realizada com sucesso!\n");
        printf("Total da compra: R$ %.2f\n", total);
        printf("Estoque restante %d unidade\n", cd.quantidade);
    } else {
        printf("Erro: Estoque insuficiente! Temos apenas %d unidade(s).\n", cd.quantidade);
    }
}
    printf("\nConsulta de disponibilidade\n");
    printf("Ano do CD: %d\n", cd.ano);
    printf("Quantidade disponível: %d unidades\n", cd.quantidade);
    printf("Preço: R$ %.2f\n", cd.preco);
    
    return 0;
}