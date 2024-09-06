#include <stdio.h>

unsigned long long factorial_recursivo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial_recursivo(n - 1);
    }
}

int main() {
    int numero;
    printf("Introduce un número entero: ");
    scanf("%d", &numero);

    printf("Factorial (recursivo) de %d es: ", numero, factorial_recursivo(numero));

    return 0;
}