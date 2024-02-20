#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam = 2;

typedef struct
{
    char nome[30];
    float nota1, nota2, media;
} Aluno;

void cadastrar(Aluno a[tam])
{
    printf("Cadastre os Alunos -----------------\n");
    for (int i = 0; i < tam; i++)
    {
        char nome[30];
        float nota1, nota2, media;

        printf("Nome: ");
        scanf(" %s", &nome);
        printf("Nota 1: ");
        scanf(" %f", &nota1);
        printf("Nota 2: ");
        scanf(" %f", &nota2);

        media = (nota1 * 2 + nota2 * 3) / 5;

        a[i].nota1 = nota1;
        a[i].nota2 = nota2;
        a[i].media = media;
        strcpy(a[i].nome, nome);
    }
}

void listarAluno(Aluno a)
{
    printf("Nome: %s\n", a.nome);
    printf("Nota 1: %f\n", a.nota1);
    printf("Nota 2: %f\n", a.nota2);
}

Aluno *bubluSort(Aluno a[tam])
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (a[j].media < a[i].media)
            {
                Aluno aux = a[j];
                a[j] = a[i];
                a[i] = aux;
            }
        }
    }
    return a;
}

Aluno *bubluSortNota1(Aluno a[tam])
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (a[j].nota1 < a[i].nota1)
            {
                Aluno aux = a[j];
                a[j] = a[i];
                a[i] = aux;
            }
        }
    }
    return a;
}

void ordenar(Aluno a[tam])
{
    int x, y, r;
    Aluno aux;
    for (int x = 0; x < tam; x++)
    {
        for (int y = x + 1; y < tam; y++)
        {
            r = strcmp(a[x].nome, a[y].nome);
            if (r > 0)
            {
                aux = a[x];
                a[x] = a[y];
                a[y] = aux;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Aluno a[tam];

    cadastrar(a);

    printf("\n-----Ordenado pela Media-------\n");
    bubluSort(a);
    for (int i = 0; i < tam; i++)
    {
        listarAluno(a[i]);
    }
    printf("\n-----Ordenado pela Nota 1------\n");
    bubluSortNota1(a);
    for (int i = 0; i < tam; i++)
    {
        listarAluno(a[i]);
    }

    printf("\n--------Ordenado pela Ordem Alfabetica------\n");

    ordenar(a);
    for (int i = 0; i < tam; i++)
    {
        listarAluno(a[i]);
    }

    printf("\n---------------------------\n");
    for (int i = 0; i < tam; i++)
    {
        listarAluno(a[i]);
    }

    return 0;
}
