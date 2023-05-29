#ifndef BERENICE_H_INCLUDED
#define BERENICE_H_INCLUDED

typedef struct
{
    unsigned long int codigo;
    char nome[25];
    float preco;
    int estoque;
    int vendida;
    int quantidade;
    int acrescentar;

} ProdutosC;

extern int tmn_produtos;

ProdutosC *subMenuProduto(ProdutosC *, int *tmn_produtos);
ProdutosC *subMenuVendas(ProdutosC *, int *tmn_produtos);


void exibir(ProdutosC*, int * tmn_produtos); //exibir os produtos
ProdutosC *cadastrar(ProdutosC * produtos, int *tmn_produto); //funcao cadastro
ProdutosC *excluir(ProdutosC *produtos, int *tmn_produto); // funcao excluir
void salvar(ProdutosC * produtos, int *tmn_produto); //funcao salvar
void ler(ProdutosC * produtos, int * tmn_produto); //funcao ler
void realizar_venda(ProdutosC * produtos, int *tmn_produto); //realizar a venda
void forma_pagamento(float sub_total); //forma de pagamento
ProdutosC *atualizar(ProdutosC *produtos, int *tmn_produto);

#endif // BERENICE_H_INCLUDED
