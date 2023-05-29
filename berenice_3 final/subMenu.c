#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



#include "berenice.h"

ProdutosC *subMenuProduto(ProdutosC *produtos, int *tmn_produtos)
{

    int opMenuP;
    char menu;

    do
    {
        system("cls");
        printf("----------------------------------------------------------|\n");
        printf("+                       Produtos                          |\n");
        printf("----------------------------------------------------------|\n");
        printf("          |==========|  |==========|  |==========|        |\n");
        printf("          |  EXIBIR  |  |CADASTRAR |  |ATUALIZAR |        |\n");
        printf("          |  ( 1 )   |  |  ( 2 )   |  |  ( 3 )   |        |\n");
        printf("          |==========|  |==========|  |==========|        |\n\n");
        printf("          |==========|  |==========|  |==========|        |\n");
        printf("          | EXCLUIR  |  |  SALVAR  |  |   LER    |        |\n");
        printf("          |  ( 4 )   |  |  ( 5 )   |  |  ( 6 )   |        |\n");
        printf("          |==========|  |==========|  |==========|        |\n\n");
        printf("                        |==========|                      |\n");
        printf("                        |  VOLTAR  |                      |\n");
        printf("                        |  ( 7 )   |                      |\n");
        printf("                        |==========|                      |\n\n");
        printf("Selecione uma opção                                       |");
        scanf("%i", &opMenuP);
        getchar();

        if(opMenuP > 0 && opMenuP < 8)
        {

            switch(opMenuP)
            {
            case 1:
                exibir(produtos, *tmn_produtos);
                scanf("%c", &menu);
                break;
            case 2:
                produtos = cadastrar(produtos, *tmn_produtos);
                scanf("%c", &menu);
                break;
            case 3:
                produtos = atualizar(produtos, *tmn_produtos);
                scanf("%c", &menu);
                break;
            case 4:
                produtos = excluir(produtos, *tmn_produtos);
                scanf("%c", &menu);
                break;
            case 5:
                salvar(produtos, *tmn_produtos);
                printf("Produtos salvos com sucesso");
                scanf("%c", &menu);
                break;
            case 6:
                ler(produtos, *tmn_produtos);
                scanf("%c", &menu);
                break;
            case 7:
                menu = 1;
                break;

            }
        }
        else
        {
            printf("\nOPÇÃO INVÁLIDA!\t\t\t\n");
            printf("PRESSIONE ENTER PARA VOLTAR AO MENU   |"); //reinicia o loop ou sai do programa
            scanf("%c", &menu);
        }
    }
    while(menu == '\n');


    return produtos;
}

ProdutosC*subMenuVendas(ProdutosC *produtos, int *tmn_produtos)
{

    int opMenuV;
    char menu;

    do
    {


        printf("--------------------------------------------------------\n");
        printf("+                       Produtos                       +\n");
        printf("--------------------------------------------------------\n");
        printf("Realizar Venda                                        |1\n");
        printf("Relatório de Venda                                    |2\n");
        printf("Voltar                                                |3\n");
        printf("--------------------------------------------------------\n");
        printf("Selecione uma opção                                   |");
        scanf("%i", &opMenuV);
        getchar();
        system("cls");


        switch(opMenuV)
        {
        case 1:

            realizar_venda(produtos, *tmn_produtos);
            scanf("%c", &opMenuV);

            break;
        case 2:
            //exibirRelatorio();
            printf("Relatório de Venda - Em construção");

            break;
        case 3:
        default:
            printf("\nOPÇÃO INVÁLIDA!\n");
            printf("PRESSIONE ENTER PARA VOLTAR AO MENU   |");
            scanf("%c", &menu);
            break;

        }
    }
    while(menu == '\0');

    return produtos;
}
