#include <stdio.h>
#include <time.h>

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
    clock_t inicio, fin; 
    double tiempo_total;

    printf("Introduce un número entero: ");
    scanf("%d", &numero);

    inicio = clock();

    unsigned long long resultado = factorial_dinamico(numero);

    fin = clock();

    tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Factorial (dinámico) de %d es: %llu\n", numero, resultado);
    printf("El programa tardó %.6f segundos en ejecutarse.\n", tiempo_total);

    return 0;
}
