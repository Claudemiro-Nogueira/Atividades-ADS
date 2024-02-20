#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char NOME[5][30];


typedef struct
{
    char nome[30];
    float salario;
} Funcionario;


void listarFuncionario(Funcionario f){
    printf("Nome: %s\n", f.nome);
    printf("salario: %f\n", f.salario);
}


Funcionario* bubluSort(Funcionario f[5]){
    for(int i = 0; i<5;i++){
        for (int j = i+1; j <= 4; j++)
        {
            if(f[j].salario < f[i].salario){
                Funcionario aux = f[j];
                f[j] = f[i];
                f[i] = aux;
            }
        }
        
    }
    return f;
}

Funcionario* insertsort(Funcionario f[5]){
    int j;
    Funcionario chave;
    for (int i = 1; i < 5; i++)
    {
        chave = f[i]; // Pega o elemento do indice 1
        j = i-1; // Pega o indice do antecessor
        while (j>=0 && f[j].salario>chave.salario)
        {
            f[j+1] = f[j];
            j = j-1;
        }
        f[j+1] = chave;
    }
    return f;
}

Funcionario* selectionSort(Funcionario f[5]){
    for (int i = 0; i < 5; i++)
    {
        int menor = i;
        for (int j = i+1; j < 5; j++)
        {
            if (f[j].salario < f[menor].salario)
            {
                menor = j;
            }
            

            Funcionario aux = f[i];
            f[i] = f[menor];
            f[menor] = aux;

        }
        
    }

    
}

void ordenar(Funcionario f[5]){
    int x,y,r;
    Funcionario aux;
    for (int x = 0; x < 5; x++)
    {
        for (int y = x+1; y < 5; y++)
        {
            r = strcmp(f[x].nome, f[y].nome);
            if (r > 0)
            {
                aux = f[x];
                f[x] = f[y];
                f[y] = aux;
            }
            
        }

    }
    
}

void cadastrar(Funcionario f[5]){
    printf("Cadastre os funcionarios -----------------\n");
    for(int i = 0; i<5;i++){
        char nome[30];
        float salario;
        printf("Nome: ");
        scanf(" %s",nome);
        printf("Salario: ");
        scanf(" %f",&salario);

        f[i].salario = salario;
        strcpy(f[i].nome, nome);
    }
}

// Função Principal
int main(int argc, char const *argv[])
{
    Funcionario f[5], backcup[5]; 
    cadastrar(f);
    


    // Descomente para testar os outros metodos de ordenação ----------------------


    //bubluSort(f);
    //insertsort(f);
    // selectionSort(f);
    ordenar(f);


    // -----------------------------------------------------------------------------





    printf("\n\n--------ORDENADO--------\n\n");
    for (int i = 0; i < 5; i++) {
        listarFuncionario(f[i]);  
    }


    printf("\n\n-----ORDEM INVERSA-----\n\n");
    // ordem inversa corresponde ao do maior para o menor
    for (int i = 4; i >= 0; i--) {
        listarFuncionario(f[i]);  
    }
    return 0;
}
