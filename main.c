/******************************************************************************

Junção da Parte 1 (Cadastro e Exibição) com a Parte 2 (Buscar e Alterar Produto)

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#define MAX 10 // Altere aqui se quiser cadastrar mais produtos

struct produto {
    int codigo;
    char nome[50];
    char marca[50];
    float valor;
};

int main() {
    struct produto listaProdutos[MAX];
    int posAtual = 0;
    int op = -1;
    int codProduto = 0;
    int posAchei = -1;

    while (op != 0) {
        printf("\n--- MENU ---");
        printf("\n1 - Cadastrar Produto");
        printf("\n2 - Exibir Produtos");
        printf("\n3 - Pesquisar por Código");
        printf("\n4 - Alterar o Valor de um Produto");
        printf("\n0 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                if (posAtual < MAX) {
                    printf("\nInforme o código do produto: ");
                    scanf("%d", &listaProdutos[posAtual].codigo);
                    getchar();

                    printf("Informe o nome: ");
                    fgets(listaProdutos[posAtual].nome, 50, stdin);
                    listaProdutos[posAtual].nome[strcspn(listaProdutos[posAtual].nome, "\n")] = '\0';

                    printf("Informe a marca: ");
                    fgets(listaProdutos[posAtual].marca, 50, stdin);
                    listaProdutos[posAtual].marca[strcspn(listaProdutos[posAtual].marca, "\n")] = '\0';

                    printf("Informe o valor: ");
                    scanf("%f", &listaProdutos[posAtual].valor);

                    posAtual++;
                } else {
                    printf("\nMemória cheia!");
                }
                break;

            case 2:
                printf("\n--- Produtos Cadastrados ---\n");
                for (int i = 0; i < posAtual; i++) {
                    printf("%d - %s - %s - R$ %.2f\n", 
                        listaProdutos[i].codigo, 
                        listaProdutos[i].nome, 
                        listaProdutos[i].marca, 
                        listaProdutos[i].valor);
                }
                break;

            case 3:
                posAchei = -1;
                printf("\nInforme o código para buscar: ");
                scanf("%d", &codProduto);
                for (int i = 0; i < posAtual; i++) {
                    if (listaProdutos[i].codigo == codProduto) {
                        posAchei = i;
                        printf("Encontrado: %d - %s - %s - R$ %.2f\n", 
                            listaProdutos[i].codigo, 
                            listaProdutos[i].nome, 
                            listaProdutos[i].marca, 
                            listaProdutos[i].valor);
                        break;
                    }
                }
                if (posAchei == -1) {
                    printf("\nProduto não encontrado.");
                }
                break;

            case 4:
                posAchei = -1;
                printf("\nInforme o código do produto a alterar: ");
                scanf("%d", &codProduto);
                for (int i = 0; i < posAtual; i++) {
                    if (listaProdutos[i].codigo == codProduto) {
                        posAchei = i;
                        printf("Novo valor: ");
                        scanf("%f", &listaProdutos[i].valor);
                        printf("Valor atualizado com sucesso!\n");
                        break;
                    }
                }
                if (posAchei == -1) {
                    printf("\nProduto não encontrado.");
                }
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpção inválida!");
                break;
        }
    }

    return 0;
}