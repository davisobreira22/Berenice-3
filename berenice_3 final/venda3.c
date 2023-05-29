#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "berenice.h"

void realizar_venda(ProdutosC *produtos, int * tmn_produto)
{
    int tmn_produtos = *tmn_produto;
    int i, j, q_item, contador = 0;//quantidade para a venda
    unsigned long cod;
    char menu_estoque, menu_estoque2; // menu de estoque2 aparece na linha 137
    ProdutosC * vendido;//o limite de produtos vendidos é 1000
    float subtotal = 0;
    do
    {

        exibir(produtos, tmn_produto);
        printf("\nDIGITE O CODIGO DO PRODUTO\t     |");

        scanf("%i", &cod);
        getchar();
        printf("DIGITE A QUANTIDADE DO ITEM\t     |");
        scanf("%i", &q_item);
        getchar();
        int posicao;
        for (int i = 0; i < tmn_produtos; i++)
        {
            if (produtos[i].codigo == cod)
            {
                posicao = i;
            }
        }

        if(q_item > 0 && q_item <= produtos[posicao].estoque)
        {
            for (int i = 0; i < tmn_produtos; i++)
            {
                if (produtos[posicao].codigo == cod)
                {
                    produtos[i].estoque -= q_item;
                    produtos[posicao].vendida += q_item;
                    subtotal += produtos[posicao].preco * q_item;
                }
            }

            printf("\nSub-Total da Venda: R$ %.2f\n", subtotal);

            printf("\n'T' PARA VENDER OUTRO PRODUTO\n'S' PARA VER RELATORIO DA VENDA\t     |");

            scanf("%c", &menu_estoque2);
            getchar();

            for(i = 0; i < contador; i++) //contador se revere a quantidade só pra lembrar
            {
                for(j = 0; j < contador; j++)
                {
                    if(vendido[i].preco > vendido[j].preco)
                    {
                        ProdutosC tmp;
                        tmp = vendido[i]; //vendido se torna tmp
                        vendido[i] = vendido[j];
                        vendido[j] = tmp;
                    }
                }
            }

            if(menu_estoque2 == 's' || menu_estoque2 == 'S') //s relatorio de venda
            {
                system("cls");
                for(i = 0; i < contador; i++)
                {

                    if(vendido[i].codigo == 4 || vendido[i].codigo == 5)
                    {
                        printf("%s\t\t\tUNIDADES  |%i\t|%.2f\n", vendido[i].nome, vendido[i].quantidade, vendido[i].preco);
                    }
                    else
                    {
                        printf("          Relatorio de Vendas         \n"); //relatorios dos itens vendidos
                        printf("%s\t\tUNIDADES  |%i\t|%.2f\n", vendido[i].nome, vendido[i].quantidade, vendido[i].preco);

                    }
                }
                forma_pagamento(subtotal); //função implementada: uma função dentro de uma função

                menu_estoque = 1;
            }

            else if(menu_estoque2 == 'T' || menu_estoque2 == 't') //para vender outro produto
            {
                menu_estoque = '\n';
            }
            else
            {
                printf("\nQUANTIDADE INVALIDA!\n");
                printf("'ENTER' PARA TENTAR OUTRA QUANTIDADE |\n");
                printf("'N' PARA VOLTAR AO MENU              |\n");
                scanf("%c", &menu_estoque);
            }
        }
        else
        {
            printf("CODIGO INVALIDO!\n");
            printf("'ENTER' PARA OUTRO CODIGO\t\t|\n");
            printf("'N' PARA VOLTAR AO MENU\t\t\t|\n");
            scanf("%c", &menu_estoque);
        }

    }
    while(menu_estoque == '\n');

}



void forma_pagamento(float sub_total)
{

    int parcelas, opcao_pagamento;
    float valor_total, valor_pago, valor_desconto, valor_acrescimo, troco, valor_recebido,valor_parcela; //variaveis que possuem numeros decimais
    printf("%.2f", sub_total);
    printf("\n Opcoes de pagamento:\n");
    printf("\n 1. A vista com desconto \n");
    printf("\n 2. A prazo \n");
    printf("\n Digite a opcao de pagamento desejada: \n ");
    scanf("%d", &opcao_pagamento);
    getchar();
    if (opcao_pagamento <=0 || opcao_pagamento >= 3)
    {
        printf("\n Opcao de pagamento invalida \n"); // caso a opcao selecionada for menor que 0 ou maior que 3, aparecera no display a seguinte mensagem dita anteriormente
    }

    valor_total = sub_total;

    switch(opcao_pagamento)   // o calculo realizado na opcao avista, calcular o desconto
    {
    case 1: //opcao avista
        if (valor_total > 0 && valor_total <= 50.0 )
        {
            valor_desconto = valor_total * 0.05;// 100/5= 0.05 total de 5% de desconto;
        }
        else if (valor_total > 50 && valor_total< 100.0)
        {
            valor_desconto = valor_total * 0.1; // se for maior que 50 reias ou menor que 100 reais, o desconto sera de 10%
        }
        else
        {
            valor_desconto = valor_total * 0.18; // se for acima de 100 reais, sera 18 % de desconto
        }
        valor_pago = valor_total - valor_desconto; // formula do valor pago

        printf("\n Valor a ser pago: R$ %.2f\n", valor_pago); //mostra no display o valor a ser pago
        printf("\n Digite o valor recebido: \n ");
        scanf("%f", &valor_recebido);
        getchar();
        printf("\n Valor Recebido: %.2f\n", valor_recebido);

        if ( valor_recebido >= valor_pago)  // IF PARA DIZER SE O VALOR DE TROCO ESTA CERTO
        {

            troco = (valor_recebido - valor_pago); //formula do troco

            printf("\n Troco: R$ %.2f \n", troco);

        }

        else   // ELSE PARA CASO O VALOR DADO SEJA MENOR PARA NAO HAVER PREJUIZO
        {

            printf("\n valor invalido \n");
        }


        break;
    case 2: //calculo da opcao a prazo, calculo dos acrescimos
        printf("\n Digite o numero de parcelas (ate 10): \n ");
        scanf("%d", &parcelas);
        getchar();

        if (parcelas <= 3)
        {
            valor_acrescimo = valor_total * 0.05;//se for at� 3 parcelas � para ter um acr�scimo de 5% ou 5/100= 0.05
        }
        else
        {
            valor_acrescimo = valor_total * 0.08;// se for maior que 3 parcelas � para ter um acr�scimo de 8% ou 8/100= 0.08
        }
        if (parcelas <=0 || parcelas >= 11)
        {
            printf("\n Opcao selecionada invalida \n"); // caso o numero de parcelas seja menor ou igual a 0 ou maior e igual 11, opcao sera invalida
            break;
        }

        valor_pago = valor_total + valor_acrescimo; //formula do acrescimo

        printf("Valor a ser pago: R$ %.2f\n", valor_pago);
        valor_parcela= valor_pago / parcelas;
        printf("\n Valor da parcela= %.2f \n",valor_parcela);
        break;
    default:
        exit(0);

    }
}
