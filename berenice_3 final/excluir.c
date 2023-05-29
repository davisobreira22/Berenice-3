#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "berenice.h"

ProdutosC* excluir(ProdutosC* produtos, int * tmn_produto)
{
    int codigo;
    int tmn_produtos = *tmn_produto;
    exibir(produtos, tmn_produto);

    printf("Digite o código do produto a ser excluído: ");
    scanf("%d", &codigo);

    int i = 0;
    int qtd_produto_restantes = 0;

    for (i=0; i< tmn_produtos; i++)
    {
        if (produtos[i].codigo == codigo)
        {
            char confirmacao[10];
            printf("Produto encontrado:\n");
            printf("Código: %d\n", produtos[i].codigo);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Deseja realmente excluir o produto? (S/N): ");
            scanf("%c", confirmacao);
            getchar();

            if (strcmp(confirmacao,'S') == 0 || strcmp(confirmacao, 's') == 0)
            {
                qtd_produto_restantes = tmn_produtos - 1 - i;
                for (int j = 0; j < qtd_produto_restantes; j++)
                {
                    produtos[i] = produtos[i + 1];
                    printf("Produto excluido com sucesso!");
                }
            }

        }
    }

    return produtos;
}
/*if (produtos[i].codigo == 0)
{
    printf("Produto não encontrado.\n");
}

//return produtos;
}
*/
