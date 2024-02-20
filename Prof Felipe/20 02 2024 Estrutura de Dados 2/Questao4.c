#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam = 2;

typedef struct
{
    char nome[255];
    float nota1,nota2;
} Aluno;

void cadastrar(Aluno a[tam])
{
    printf("Cadastre os Alunos -----------------\n");
    for (int i = 0; i < tam; i++)
    {
        char nome[255];
        float nota1,nota2;
       
        printf("Nome: ");
        scanf(" %s", &nome);
        printf("Nota 1: ");
        scanf(" %f", &nota1);
        printf("Nota 2: ");
        scanf(" %f", &nota2);

        a[i].nota1 = nota1;
        a[i].nota2 = nota2;
        strcpy(a[i].nome, nome);
    }
}

void listarAluno(Aluno a)
{
    printf("Nome: %s\n", a.nome);
    printf("Nota 1: %f\n", a.nota1);
    printf("Nota 2: %f\n", a.nota2);
}

Aluno* bubluSort(Aluno a[tam]){
    for(int i = 0; i<tam;i++){
        for (int j = i+1; j < tam; j++)
        {
            if(a[j].nota1 < a[i].nota1){
                Aluno aux = a[j];
                a[j] = a[i];
                a[i] = aux;
            }
        }
        
    }
    return a;
}



int main(int argc, char const *argv[])
{
    Aluno a[tam];

    cadastrar(a);
    bubluSort(a);
    printf("\n---------------------------\n");
    for (int i = 0; i < tam; i++)
    {
        listarAluno(a[i]);
    }
    

    return 0;
}
