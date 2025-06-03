#include <stdio.h>
#include <stdlib.h>

// Função que verifica se o número é primo
int primo(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Função para ler e validar o número informado pelo usuário
int ler_numero()
{
    int n;
    char buffer[100];
    do
    {
        printf("Digite um numero inteiro positivo maior que 1:\n");
        fflush(stdout);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            // Verifica se a entrada é um número inteiro
            if (sscanf(buffer, "%d", &n) != 1)
            {
                printf("Entrada invalida! Por favor, digite apenas numeros inteiros positivos maiores que 1.\n");
                n = 0;
            }
            else if (buffer[0] == '-' && n < 0)
            {
                printf("Numero negativo nao permitido! Digite apenas numeros positivos maiores que 1.\n");
                n = 0;
            }
            else if (n == 0)
            {
                printf("Zero nao permitido! Digite apenas numeros positivos maiores que 1.\n");
                n = 0;
            }
            else if (n == 1)
            {
                printf("Numero invalido! Por favor, digite um numero maior que 1.\n");
                n = 0;
            }
        }
        else
        {
            n = 0;
        }
    } while (n <= 1);
    return n;
}

int main()
{
    int n;

    printf("NUMEROS PRIMOS MENORES QUE UM NUMERO INFORMADO\n\n");

    n = ler_numero();

    printf("Numeros primos menores que %d:\n", n);
    for (int i = 2; i < n; i++)
    {
        if (primo(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}