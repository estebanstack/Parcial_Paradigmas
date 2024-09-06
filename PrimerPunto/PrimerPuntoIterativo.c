#include <stdio.h>
#include <time.h>  // -> libreria para medir el tiempo

unsigned long long factorial_iterativo(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int numero;
    clock_t inicio, fin;  // Variables para medir el tiempo
    double tiempo_total;

    printf("Introduce un número entero: ");
    scanf("%d", &numero);
    // Inicia la medición del tiempo
    inicio = clock();
    
    unsigned long long resultado = factorial_iterativo(numero);

    // Finaliza la medición del tiempo
    fin = clock();

    // Calcula el tiempo total en segundos
    tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Factorial (iterativo) de %d es: %llu\n", numero, resultado);
    printf("El programa tardó %.6f segundos en ejecutarse.\n", tiempo_total);

    return 0;
}
