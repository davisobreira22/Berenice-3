#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "berenice.h"

void salvar(ProdutosC *produtos, int *tmn_produto)
{

    if(produtos == NULL)
    {
        printf("Nenhum produto cadastrado!");
    }
    else
    {
        int tmn_produtos = *tmn_produto;
        // definindo o arquivo como "arquivo"
        FILE *arquivo;

        // Salvar os dados no arquivo
        arquivo = fopen("produtos.txt", "w");

        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        fprintf(arquivo, "%d\n", tmn_produtos);

        for (int i = 0; i < tmn_produtos; i++)
        {

            fprintf(arquivo, "%lu\n%s\n%.2f\n%d\n%d\n",
                    produtos[i].codigo,
                    produtos[i].nome,
                    produtos[i].preco,
                    produtos[i].estoque,
                    produtos[i].vendida);
        }
        fclose(arquivo);
    }
}
