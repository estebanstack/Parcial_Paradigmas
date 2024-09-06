#include <stdio.h>

unsigned long long factorial_iterativo(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int numero;
    printf("Introduce un número entero: ");
    scanf("%d", &numero);

    printf("Factorial (iterativo) de %d es: %llu\n", numero, factorial_iterativo(numero));

    return 0;
}