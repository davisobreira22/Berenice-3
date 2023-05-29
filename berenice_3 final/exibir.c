#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "berenice.h"

void exibir(ProdutosC *produtos, int * tmn_produtos)
{

    if(produtos == NULL)
    {
        printf("Nenhum produto cadastrado!");
    }

    else
    {
        system("cls");
        printf("--------------------------------------------------------\n");
        printf("+                       Produtos                       +\n");
        printf("--------------------------------------------------------\n");
        printf("%-8s %-25s %-8s %-6s %-6s\n", "Código", "Produto", "Valor", "Est.", "Vend.");


        for (int i = 0; i < *tmn_produtos; i++)
        {
            printf("%-8lu %-25s %-8.2f %-6d %-6d\n",
                   produtos[i].codigo,
                   produtos[i].nome,
                   produtos[i].preco,
                   produtos[i].estoque,
                   produtos[i].vendida);
        }
    }

    return;
}
