#define NUM_PRODUTOS 4

void exibirMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Adicionar ao Estoque\n");
    printf("2. Vender Meias\n");
    printf("3. Relatorio de Meias em Estoque\n");
    printf("4. Relatorio de Vendas do Dia\n");
    printf("5. Sair\n");
}

void adicionarEstoque(int estoque[][3], int indice) {
    int quantidadeAdicionar, custoPorUnidade, valorVendaPorUnidade;

    printf("Informe a quantidade a adicionar ao estoque: ");
    scanf("%d", &quantidadeAdicionar);
    printf("Informe o valor de custo por unidade do produto: ");
    scanf("%d", &custoPorUnidade);
    printf("Informe o valor de venda por unidade do produto: ");
    scanf("%d", &valorVendaPorUnidade);

    estoque[indice][0] += quantidadeAdicionar;
    estoque[indice][1] = custoPorUnidade;
    estoque[indice][2] = valorVendaPorUnidade;

    printf("Produto adicionado ao estoque com sucesso!\n");
}

void venderMeias(int estoque[][3], int indice, int vendas[][2]) {
    int quantidadeVendida;

    printf("Informe a quantidade de meias a ser vendida: ");
    scanf("%d", &quantidadeVendida);

    if (quantidadeVendida > 0 && quantidadeVendida <= estoque[indice][0]) {
        estoque[indice][0] -= quantidadeVendida;
        int lucro = quantidadeVendida * (estoque[indice][2] - estoque[indice][1]);

        printf("Venda realizada com sucesso. Lucro obtido: R$ %d\n", lucro);
        vendas[indice][0] += quantidadeVendida;
        vendas[indice][1] += lucro;
    } else {
        printf("Quantidade inválida ou insuficiente em estoque.\n");
    }
}

void relatorioEstoque(int estoque[][3]) {
    printf("\n===== RELATÓRIO DE ESTOQUE =====\n");
    printf("%-30s%-15s%-15s%-15s\n", "Tipo de Produto", "Quantidade", "Preco Venda", "Custo Unidade");

    const char* tipos[] = {"Meias Listradas Infantis", "Meias Lisas Infantis", "Meias Lisas Adulto", "Meias Listradas Adulto"};
    for (int i = 0; i < NUM_PRODUTOS; ++i) {
        printf("%-30s%-15d%-15d%-15d\n", tipos[i], estoque[i][0], estoque[i][2], estoque[i][1]);
    }
}

void relatorioVendas(int vendas[][2]) {
    printf("\n===== RELATÓRIO DE VENDAS DO DIA =====\n");
    printf("%-30s%-20s%-20s\n", "Tipo de Produto", "Quantidade Vendida", "Lucro Obtido");

    const char* tipos[] = {"Meias Listradas Infantis", "Meias Lisas Infantis", "Meias Lisas Adulto", "Meias Listradas Adulto"};
    for (int i = 0; i < NUM_PRODUTOS; ++i) {
        printf("%-30s%-20d%-20d\n", tipos[i], vendas[i][0], vendas[i][1]);
    }
}

int main() {
    int estoque[NUM_PRODUTOS][3] = {0};
    int vendas[NUM_PRODUTOS][2] = {0};
    int opcao, indiceProduto;

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nInforme o produto para adicionar ao estoque:\n");
                printf("0 = Listradas Infantil\n1 = Lisas Infantil\n2 = Lisas Adulto\n3 = Listrada Adulto\n(0 a %d): ", NUM_PRODUTOS - 1);
                scanf("%d", &indiceProduto);
                if (indiceProduto >= 0 && indiceProduto < NUM_PRODUTOS) {
                    adicionarEstoque(estoque, indiceProduto);
                } else {
                    printf("Índice de produto inválido.\n");
                }
                break;

            case 2:
                printf("\nInforme o produto para venda:\n");
                printf("0 = Listradas Infantil\n1 = Lisas Infantil\n2 = Lisas Adulto\n3 = Listrada Adulto\n(0 a %d): ", NUM_PRODUTOS - 1);
                scanf("%d", &indiceProduto);
                if (indiceProduto >= 0 && indiceProduto < NUM_PRODUTOS) {
                    venderMeias(estoque, indiceProduto, vendas);
                } else {
                    printf("Índice de produto inválido.\n");
                }
                break;

            case 3:
                relatorioEstoque(estoque);
                break;

            case 4:
                relatorioVendas(vendas);
                break;

            case 5:
                printf("Saindo do programa. Até mais!\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
