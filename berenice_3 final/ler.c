#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Berenice.h"

// Função Ler produtos do arquivo
void ler(ProdutosC *produtos, int * tmn_produto)
{
    int tmn_produtos = *tmn_produto;
    // Limpa a tela
    system("cls");

    FILE *arquivo;
    int quantidade_produtos;
    //Produto produtos[100];

    arquivo = fopen("produtos.txt", "r+");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Lê a quantidade de produtos da primeira linha
    fscanf(arquivo, "%d", &quantidade_produtos);
    (*tmn_produto) = quantidade_produtos;

    printf("--------------------------------------------------------\n");
    printf("|                   LISTA DE PRODUTOS                  |\n");
    printf("--------------------------------------------------------\n");
    printf("%-8s %-25s %-8s %-6s %-6s\n", "Código", "Produto", "Valor", "Est.", "Vend.");

    free(produtos);


    produtos = (ProdutosC *) malloc(quantidade_produtos * sizeof(ProdutosC));

    for (int i = 0; i < quantidade_produtos; i++)
    {
        fscanf(arquivo, "%d", &produtos[i].codigo);
        fgetc(arquivo);

        fgets(produtos[i].nome, 25, arquivo);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

        fscanf(arquivo, "%f", &produtos[i].preco);
        fgetc(arquivo);
        fscanf(arquivo, "%d", &produtos[i].estoque);
        fgetc(arquivo);
        fscanf(arquivo, "%d", &produtos[i].vendida);
        fgetc(arquivo);

        if (produtos[i].codigo == 0)
        {
            break;
        }
        else
        {
            printf("%-8d %-25s %-8.2f %-6d %-6d\n",
                   produtos[i].codigo, produtos[i].nome,
                   produtos[i].preco, produtos[i].estoque,
                   produtos[i].vendida);
        }

    }

    fclose(arquivo);

    printf("\nPressione ENTER para continuar");

}
