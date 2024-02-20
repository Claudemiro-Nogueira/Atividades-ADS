#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam = 12;

typedef struct
{
    int codigo;
    char descricao[255];
    float preco;
} Produto;

Produto *bubluSort(Produto p[tam])
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (p[j].codigo < p[i].codigo)
            {
                Produto aux = p[j];
                p[j] = p[i];
                p[i] = aux;
            }
        }
    }
    return p;
}

void listarProduto(Produto p)
{
    printf("Código: %d\n", p.codigo);
    printf("Descrição: %s\n", p.descricao);
    printf("Preço: %f\n", p.preco);
}

void cadastrar(Produto f[tam])
{
    printf("Cadastre os Produtos -----------------\n");
    for (int i = 0; i < tam; i++)
    {
        char descricao[255];
        float preco;
        int codigo;
        printf("Codigo: ");
        scanf(" %d", &codigo);
        printf("Descricao: ");
        scanf(" %s", descricao);
        printf("preco: ");
        scanf(" %f", &preco);
        f[i].codigo = codigo;
        f[i].preco = preco;
        strcpy(f[i].descricao, descricao);
    }
}


void buscaBinaria(Produto p[], int chave){
    int ini = 0, fim = tam-1, cont = 0;
    int meio;
    do{
        meio = (ini+fim)/2;
        if(chave>p[meio].codigo){
            ini = meio+1;
        }else if(chave<p[meio].codigo){
            fim = meio-1;
        }

        cont++;
    } while(chave != p[meio].codigo && ini <= fim);

    if(chave == p[meio].codigo){
        printf("Encontrado na posição %d\n", meio);
        printf("Total de comparações: %d\n",cont);
    } else{
        printf("-1");
    }

}


int main(int argc, char const *argv[])
{
    Produto p[tam];
    int codigoProduto, cont = 0;
    cadastrar(p);
    printf("\n\n-----------------------------------\n\n");
    bubluSort(p);
    for (int i = 0; i < tam; i++)
    {
        listarProduto(p[i]);
    }

    printf("Qual codigo do produto deseja buscar: ");
    scanf("%d", &codigoProduto);
    // Busca sequencial
    for (int i = 0; i < tam; i++)
    {
        if (codigoProduto == p[i].codigo)
        {
            cont++;

            listarProduto(p[i]);
        
        }
        else
        {
            cont++;
        }
    }

    printf("Quantidade de comparações: %d\n", cont);


    buscaBinaria(p, codigoProduto);



    return 0;
}
