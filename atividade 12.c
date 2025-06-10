#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
    int idd;
} Pizza;

Pizza pizza[100];
int numPizza = 0;

typedef struct {
    char name[50];
    int id;
} Cliente;

Cliente cliente[100];
int numCliente = 0;

void cadastrarPizza() {
    printf("---- Cadastro de Pizzas ----\n");
    printf("Sabor da pizza: ");
    scanf(" %[^\n]", pizza[numPizza].nome); 
    printf("Preço da pizza: R$");
    scanf("%f", &pizza[numPizza].preco);
    printf("ID da pizza: ");
    scanf("%d", &pizza[numPizza].idd);
    
    printf("Pizza cadastrada com sucesso!\n");
    numPizza++;
}

void cadastrarCliente() {
    printf("---- Cadastro do Cliente ----\n");
    printf("Nome do Cliente: ");
    scanf(" %[^\n]", cliente[numCliente].name); 
    printf("Crie seu ID: ");
    scanf("%d", &cliente[numCliente].id);
    printf("Cliente cadastrado com sucesso!\n");
    numCliente++;
}

void listarPizzas() {
    printf("---- Pizzas cadastradas ----\n");
    for(int i = 0; i < numPizza; i++) {
        printf("Sabor da pizza: %s\n", pizza[i].nome);
        printf("Preço: %.1f\n", pizza[i].preco);
        printf("ID da pizza: %d\n", pizza[i].idd);
        printf("\n--------------------\n");
    }
}

void listarCliente() {
    printf("---- Clientes cadastrados ----\n");
    for(int i = 0; i < numCliente; i++) {
        printf("Nome do cliente: %s\n", cliente[i].name);
        printf("ID: %d\n", cliente[i].id);
        printf("\n-------------------\n");
    }
}

void venderPizza() {
    if(numCliente == 0) {
        printf("Nenhum cliente encontrado. Cadastre um cliente primeiro!\n");
        return;
    }
    if (numPizza == 0) {
        printf("Nenhuma pizza encontrada. Cadastre uma pizza primeiro!\n");
        return;
    }
    
    int clienteID;
    printf("Digite o ID do cliente: ");
    scanf("%d", &clienteID);
    int clienteEncontrado = -1;
    
    for (int i = 0; i < numCliente; i++) {
        if (cliente[i].id == clienteID) {
            clienteEncontrado = i;
            printf("Cliente encontrado\n");
            break;
        }
    }
    
    if (clienteEncontrado == -1) {
        printf("Cliente não cadastrado\n");
        return;
    }

    int pizzaID;
    printf("Digite o ID da pizza que deseja: ");
    scanf("%d", &pizzaID);
    int pizzaEncontrada = -1;

    for (int i = 0; i < numPizza; i++) {
        if (pizza[i].idd == pizzaID) {
            pizzaEncontrada = i;
            printf("Pizza encontrada!\n");
            break;
        }
    }

    if (pizzaEncontrada == -1) {
        printf("Pizza não cadastrada!\n");
        return;
    }

    int quantidade;
    printf("Digite a quantidade desejada \"%s\": ", pizza[pizzaEncontrada].nome);
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
        printf("Quantidade inválida!\n");
        return;
    }

    float total = pizza[pizzaEncontrada].preco * quantidade;
    printf("Total a pagar: R$ %.2f\n", total);
}

int main() {
    int opcao;
    do {
        printf("---- Nostra Pizza ----\n");
        printf("1 - Cadastrar pizza\n");
        printf("2 - Cadastrar cliente\n");
        printf("3 - Listar pizzas\n");
        printf("4 - Listar clientes\n");
        printf("5 - Vender pizza\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: 
                cadastrarPizza();
                break;
            case 2:
                cadastrarCliente();
                break;
            case 3:
                listarPizzas();
                break;
            case 4:
                listarCliente();
                break;
            case 5: 
                venderPizza();
                break;
            case 0: 
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
    
    return 0;
}