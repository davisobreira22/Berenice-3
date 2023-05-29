#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "berenice.h"

ProdutosC *atualizar(ProdutosC *produtos, int *tmn_produto)
{

    int tmn_produtos = *tmn_produto; // ponteiro de int que mostra o tamanho dos produtos
    int i, op = 0, novo_estoque =0;
    unsigned long codigo;
    float novo_preco = 0;
    char atualizar[10];

    if(produtos == NULL)
    {
        printf("Nenhum produto cadastrado!");
    }
    else
    {

        do
        {
            exibir(produtos, tmn_produto);
            printf("Digite o código do produto: ");
            scanf("%lu", &codigo);
            getchar();

            int posicao = -1;
            for (int i = 0; i < tmn_produtos; i++)
            {
                if (produtos[i].codigo == codigo)
                {
                    posicao = i;
                }
            }

            if (posicao != -1)
            {
                for(i = 0; i < produtos->quantidade; i++)
                {
                    if(produtos[i].codigo == codigo)
                    {
                        break;
                    }
                }

                printf("%-8lu %-25s %-8.2f %-6d\n", //esses numeros no printf sao para dar espaço, pura estetica
                       produtos[i].codigo,
                       produtos[i].nome,
                       produtos[i].preco,
                       produtos[i].estoque);

                do
                {
                    printf("Se desejas atualizar o PREÇO digite (1) ou o ESTOQUE digite (2): ");
                    scanf("%i", &op);
                    getchar();
                    if(op == 1)
                    {
                        printf("Digite novo preço do produtos: ");
                        scanf("%f", &novo_preco);
                        getchar();

                        if(novo_preco > 0)
                        {

                            printf("%-8lu %-25s %-8.2f %-6d\n",
                                   produtos[i].codigo,
                                   produtos[i].nome,
                                   produtos[i].preco,
                                   produtos[i].estoque);

                            produtos[i].preco = novo_preco;

                            printf("%-8lu %-25s %-8.2f %-6d\n",
                                   produtos[i].codigo,
                                   produtos[i].nome,
                                   produtos[i].preco,
                                   produtos[i].estoque);

                            printf("\nPreço Unitário do(a) '%s' foi atualizado com sucesso!", produtos[i].nome);

                        }
                        else
                        {
                            printf("Valor inválido! Tente novamente");
                            op = 0;
                        }
                    }
                    else if(op == 2)
                    {
                        printf("Digite o novo estoque: ");
                        scanf("%i", &novo_estoque);
                        getchar();

                        if(novo_estoque >= 0)
                        {
                            printf("%-8lu %-25s %-8.2f %-6d\n",
                                   produtos[i].codigo,
                                   produtos[i].nome,
                                   produtos[i].preco,
                                   produtos[i].estoque);

                            produtos[i].estoque = novo_estoque;

                            printf("%-8lu %-25s %-8.2f %-6d\n",
                                   produtos[i].codigo,
                                   produtos[i].nome,
                                   produtos[i].preco,
                                   produtos[i].estoque);

                            printf("\n Estoque do(a) '%s' foi atualizado com sucesso!", produtos[i].nome);
                        }
                        else
                        {
                            printf("Valor inválido! Tente novamente");
                            op = 0;
                        }

                    }
                    else
                    {
                        printf("Valor inválido! Tente novamente");
                    }
                    printf("\nDeseja atualizar mais produtos? ( S/N ) ");
                    scanf("%c", &atualizar);
                }
                while(op < 1 || op > 2);
            }
            else
            {
                printf("Valor inválido! Tente novamente");
            }
        }
        while(strcmp(atualizar, "s") == 0 || strcmp(atualizar, "S") == 0);

    }

    return produtos;
}
