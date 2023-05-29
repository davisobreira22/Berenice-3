#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "berenice.h"

void realizar_venda()
{
    int i, j, q_item, cod, contador = 0; //quantidade para a venda
    char menu_estoque, menu_estoque2;
    produto *produtos = NULL;
    float subtotal = 0;

    FILE *arquivo;
    arquivo = fopen("estoque.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int num_produtos;
    fscanf(arquivo, "%d\n", &num_produtos);

    produtos = malloc(num_produtos * sizeof(produto));

    for (i = 0; i < num_produtos; i++) {
        fscanf(arquivo, "%d\n", &produtos[i].codigo);
        fgets(produtos[i].nome, 100, arquivo);
        strtok(produtos[i].nome, "\n");
        fscanf(arquivo, "%f\n", &produtos[i].preco);
        fscanf(arquivo, "%d\n", &produtos[i].estoque);
    }

    fclose(arquivo);

    do {
        exibir(ProdutosCadastro *produtos);
        printf("\nDIGITE O CODIGO DO PRODUTO\t     |");
        scanf("%i", &cod);
        getchar();

        if (cod > 0 && cod <= num_produtos) {
            printf("DIGITE A QUANTIDADE DO ITEM\t     |");
            scanf("%i", &q_item);
            getchar();

            if (q_item > 0) {
                if (q_item <= produtos[cod - 1].estoque) {
                    contador++;

                    produtos[cod - 1].estoque = produtos[cod - 1].estoque - q_item;

                    vendido[contador - 1] = produtos[cod - 1];

                    vendido[contador - 1].quantidade = q_item;

                    vendido[contador - 1].preco = produtos[cod - 1].preco * q_item;

                    subtotal = subtotal + vendido[contador - 1].preco;

                    printf("\nSub-Total da Venda: R$ %.2f\n", subtotal);

                    printf("\n'T' PARA VENDER OUTRO PRODUTO\n'S' PARA VER RELATORIO DA VENDA\t     |");

                    scanf("%c", &menu_estoque2);
                    getchar();

                    for (i = 0; i < contador; i++) {
                        for (j = 0; j < contador; j++) {
                            if (vendido[i].preco > vendido[j].preco) {
                                Produto tmp;
                                tmp = vendido[i];
                                vendido[i] = vendido[j];
                                vendido[j] = tmp;
                            }
                        }
                    }

                    if (menu_estoque2 == 's' || menu_estoque2 == 'S') {
                        system("cls");
                        for (i = 0; i < contador; i++) {
                            if (vendido[i].cod == 4 || vendido[i].cod == 5) {
                                printf("%s\t\t\tUNIDADES  |%i\t|%.2f\n", vendido[i].nome, vendido[i].quantidade, vendido[i].preco);
                            }
                            else {
                                printf("          Relatorio de Vendas         \n");
                                printf("%s\t\tUNIDADES  |%i\t|%.2f\n", vendido[i].nome, vendido[i].quantidade, vendido[i].preco);
                            }
                        }
                        forma_pagamento(subtotal);
                    }

                    else if (menu_estoque2 == 'T' || menu_estoque2 == 't') {
                        menu_estoque = '\n';
                    }

                    else {
                        menu_estoque = '1';
                    }
                }
                else {
                    printf("\nQUANTIDADE INVALIDA!\n");
                    printf("'ENTER' PARA TENTAR OUTRA QUANTIDADE |\n");
                    printf("'N' PARA VOLTAR AO MENU              |\n");
                    scanf("%c", &menu_estoque);
                }
            }
            else {
                printf("\nQUANTIDADE INVALIDA!\n");
                printf("'ENTER' PARA TENTAR OUTRA QUANTIDADE\t|\n");
                printf("'N' PARA VOLTAR AO MENU\t\t|\n");
                scanf("%c", &menu_estoque);
            }
        }
        else {
            printf("CODIGO INVALIDO!\n");
            printf("'ENTER' PARA OUTRO CODIGO\t\t|\n");
            printf("'N' PARA VOLTAR AO MENU\t\t\t|\n");
            scanf("%c", &menu_estoque);
        }

    } while (menu_estoque == '\n');

    // Salvar as alterações no estoque

    arquivo = fopen("estoque.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%d\n", num_produtos);

    for (i = 0; i < num_produtos; i++) {
        fprintf(arquivo, "%d\n", produtos[i].codigo);
        fprintf(arquivo, "%s\n", produtos[i].nome);
        fprintf(arquivo, "%.2f\n", produtos[i].preco);
        fprintf(arquivo, "%d\n", produtos[i].estoque);
    }

    fclose(arquivo);

    free(produtos);
}
