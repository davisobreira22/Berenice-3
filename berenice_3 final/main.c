#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "berenice.h"

int tmn_produtos=0;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese"); //  permite a inser��o de acentos e caract�res especiais em portugu�s
    ProdutosC *produtos; //ponteiro para a struct
    produtos = NULL;
    int opMenu; // op��o do menu principal
    char menu;// opcao que reinicia o loop do menu ou sai do programa
    int tmn = 0; // ponteiro de int que mostra o tamanho dos produtos
    int* tmn_produtos = &tmn; // ponteiro de int que mostra o tamanho dos produtos
    int* tmn_vendas = 20;
    do
    {

        // Limpa a tela
        system("cls");
        //printf("%i", sizeof(produtos));
        printf("--------------------------------------------------------\n");
        printf("                   PADARIA DA BERENICE                  | \n");
        printf("--------------------------------------------------------\n");
        printf("-> Produtos                 )))                        1|\n");
        printf("                           (((                         *| \n");
        printf("-> Vendas                +-----+                       2|\n");
        printf("                         |     |]                      *|\n");
        printf("-> Sair                  `-----'                       3|\n");
        printf("--------------------------------------------------------\n");
        printf("Selecione uma op��o                                   ");
        scanf("%i", &opMenu);
        getchar();

        if(opMenu > 0 && opMenu < 4)  // verifica se o c�digo digitado est� dentro do intervalo [1,3]
        {

            switch(opMenu)
            {
            case 1:
                produtos = subMenuProduto(produtos, &tmn_produtos);
                menu = '\n'; // reinicia o loop quando o programa retorna da fun��o
                break;

            case 2:
                produtos = subMenuVendas(produtos, &tmn_produtos);
                menu = '\n'; // reinicia o loop quando o programa retorna da fun��o
                break;

            case 3:
                menu = 1;
                break;
            }
        }

        else
        {
            //caso a opcao selecionada pelo usu�rio n�o estiver dentro do intervalo [1,4]
            printf("\nOP��O INV�LIDA!\t\t\t\n");
            printf("PRESSIONE ENTER PARA VOLTAR AO MENU                   |"); //reinicia o loop ou sai do programa
            scanf("%c", &menu);
        }
    }
    while(menu == '\n');  // enquanto o usu�rio pressionar enter o menu inicial ser� exibido para que ele tente um novo c�digo

    free(produtos);

    return 0;
}
