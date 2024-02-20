#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

int main(int argc, char const *argv[])
{
    int tam = 10;
    int numeros[tam];

    // Preencher o vetor
    for (int i = 0; i < tam; i++)
    {
        printf("Informe o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\n");

    // Aqui vai ordenar usando o buuble Sort
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (numeros[j] < numeros[i])
            {
                int aux = numeros[j];
                numeros[j] = numeros[i];
                numeros[i] = aux;
            }
        }
    }

    int menorNumero = numeros[0], contadorMenor, maiorNumero = numeros[tam - 1], contadorMaior;
    for (int i = 0; i < tam; i++)
    {
        if (menorNumero == numeros[i])
        {
            contadorMenor++;
        }
        if (maiorNumero == numeros[i])
        {
            contadorMaior++;
        }
    }
    printf("Menor numero: %d aparece %d vez(es) no vetor\n", menorNumero, contadorMenor);
    printf("Maior numero: %d aparece %d vez(es) no vetor\n", maiorNumero, contadorMaior);
    return 0;
}
