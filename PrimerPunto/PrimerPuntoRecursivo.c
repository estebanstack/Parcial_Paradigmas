#include <stdio.h>
#include <time.h>  

unsigned long long factorial_recursivo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial_recursivo(n - 1);
    }
}

int main() {
    int numero;
    clock_t inicio, fin; 
    double tiempo_total;

    printf("Introduce un número entero: ");
    scanf("%d", &numero);
    inicio = clock();
    
    unsigned long long resultado = factorial_recursivo(numero);
    
    fin = clock();
    
    tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Factorial (recursivo) de %d es: %llu\n", numero, resultado);
    printf("El programa tardó %.6f segundos en ejecutarse.\n", tiempo_total);

    return 0;
}
