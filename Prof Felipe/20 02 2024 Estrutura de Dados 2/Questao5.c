#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam = 3;
int a = 0;
int verifica(int n[tam])
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (n[i] == n[j])
            {
                a = 1;
            }
            else
            {
                a = 0;
            }
        }
    }
}

void cadastrar(int n[tam])
{
    printf("\nCadastre os numeros -----------------\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d Numero: ", i + 1);
        scanf(" %d", &n[i]);
    }
}

void listarNumeros(int n[])
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d\n", n[i]);
    }
}

void bubluSort(int n[tam])
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (n[j] < n[i])
            {
                int aux = n[j];
                n[j] = n[i];
                n[i] = aux;
            }
        }
    }
}

void sequencial(int numeros[tam], int n)
{
    for (int i = 0; i < tam; i++)
    {
        if (numeros[i] == n)
        {
            if (i % 2 == 0)
                printf("\nNumero do usuario esta em uma posição par %d\n", i);
            else
            {
                printf("\nNumero do usuario esta em uma posicao impar %d\n", i);
            }
        }
    }
}

void buscaBinaria(int n[tam], int chave)
{
    int ini = 0, fim = tam - 1, cont = 0;
    int meio;
    do
    {
        meio = (ini + fim) / 2;
        if (chave > n[meio])
        {
            ini = meio + 1;
        }
        else if (chave < n[meio])
        {
            fim = meio - 1;
        }

        cont++;
    } while (chave != n[meio] && ini <= fim);

    if (chave == n[meio])
    {
        printf("Numero Encontrado");
        sequencial(n, n[meio]);
    }
    else
    {
        printf("-1");
    }
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        int numeros[tam], numeroUsuario;
        cadastrar(numeros);
        verifica(numeros);
        if (a)
        {
            printf("\nNão é permitido numeros repetidos");
        }
        else
        {
            listarNumeros(numeros);

            printf("Informe um numero: ");
            scanf("%d", &numeroUsuario);

            // Busca sequencial
            printf("\n--------Busca Sequencial-------\n");
            for (int i = 0; i < tam; i++)
            {
                if (numeros[i] == numeroUsuario)
                {
                    if (i % 2 == 0)
                        printf("\nNumero do usuario esta em uma posição par %d\n", i);
                    else
                    {
                        printf("\nNumero do usuario esta em uma posicao impar %d\n", i);
                    }
                }
            }

            bubluSort(numeros);
            listarNumeros(numeros);
            printf("\n--------Busca Binaria--------\n");
            buscaBinaria(numeros, numeroUsuario);
            listarNumeros(numeros);

            break;
        }
    }

    return 0;
}
