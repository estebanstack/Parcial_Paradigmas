#include <stdio.h>

unsigned long long factorial_dinamico(int n) {
    unsigned long long resultados[n + 1];
    resultados[0] = 1;

    for (int i = 1; i <= n; i++) {
        resultados[i] = i * resultados[i - 1];
    }

    return resultados[n];
}

int main() {
    int numero;
    printf("Introduce un número entero: ");
    scanf("%d", &numero);

    printf("Factorial (dinámico) de %d es: ", numero, factorial_dinamico(numero));

    return 0;
}