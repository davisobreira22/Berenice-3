#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "berenice.h"

ProdutosC *cadastrar(ProdutosC *produtos, int * tmn_produto)
{

    int i, quant = 0, posicao_atual = 0, pos_livre = 0;
    char cad;

    int tmn_produtos = *tmn_produto; //valor do endereco de memoria que esta senddo apontada

    do
    {
        printf("Quantidade de produtos a cadastrar: ");
        scanf("%i", &quant);
        getchar();

        if(quant <=0)
        {
            printf("Entrada inválida! Tente novamente\n");
        }

    }
    while(quant <= 0);

    int tamanho_atual = quant + tmn_produtos;
    (*tmn_produto) = tamanho_atual; //atualiza o valor da variavel que o ponteiro esta apontando
    produtos = (ProdutosC *) realloc(produtos, (quant+ tmn_produtos)*sizeof(ProdutosC)); //reorganiza para caber mais
    for(i = 0; i < quant; i++)  //loop para cadastrar os produtos individualmente
    {
        printf("Produto %d: \n", i + 1);

//solicitação das informações
        do
        {
            printf("Código: \n");
            scanf("%i", &produtos[tmn_produtos + i].codigo); //percorre o tmn_produtos
            getchar(); // Limpar o buffer de entrada

            if (produtos[tmn_produtos + i].codigo <= 0)
            {
                printf("Entrada inválida. Digite um valor inteiro.\n");
            }

        }
        while(produtos[tmn_produtos + i].codigo <= 0);

        do
        {
            printf("Nome: \n");
            gets(produtos[tmn_produtos + i].nome);

            if(strlen(produtos[tmn_produtos + i].nome) > 25 || strlen(produtos[tmn_produtos + i].nome) == 0)
            {
                printf("Entrada inválida! Tente novamente \n");
            }
        }
        while(strlen(produtos[tmn_produtos + i].nome) > 25 || strlen(produtos[tmn_produtos + i].nome) == 0);

        do
        {
            printf("Valor: \n");
            scanf("%f", &produtos[tmn_produtos + i].preco);
            getchar();

            if(produtos[tmn_produtos + i].preco <= 0)
            {
                printf("Entrada inválida! Tente novamente \n");
            }
        }
        while(produtos[tmn_produtos + i].preco <= 0);

        do
        {
            printf("Estoque: \n");
            scanf("%i", &produtos[tmn_produtos + i].estoque);
            getchar();

            if(produtos[tmn_produtos + i].estoque <= 0)
            {
                printf("Entrada inválida! Tente novamente \n");
            }
        }
        while(produtos[tmn_produtos + i].estoque <= 0);

        produtos[tmn_produtos + i].vendida = 0;
//
    }


    printf("Produto cadastrado com sucesso! Aperte enter para voltar ao menu");
    scanf("%c", &cad);

    return produtos;

}
