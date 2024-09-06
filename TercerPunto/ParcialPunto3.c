#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para almacenar la información del estudiante
typedef struct {
    char *nombre;
    char *apellido;
    unsigned int edad : 7;
    char *ID;
    int *calificaciones;
    size_t num_calificaciones;
} Estudiante;

// Función pura para asignar memoria dinámica a un nuevo estudiante (función pura)
Estudiante *crear_estudiante(const char *nombre, const char *apellido, unsigned int edad, const char *ID, int *calificaciones, size_t num_calificaciones) {
    Estudiante *nuevo_estudiante = (Estudiante *)malloc(sizeof(Estudiante));
    if (nuevo_estudiante == NULL) {
        return NULL;
    }

    nuevo_estudiante->nombre = strdup(nombre);  // strdup asigna memoria y copia la cadena
    nuevo_estudiante->apellido = strdup(apellido);
    nuevo_estudiante->ID = strdup(ID);

    if (nuevo_estudiante->nombre == NULL || nuevo_estudiante->apellido == NULL || nuevo_estudiante->ID == NULL) {
        return NULL;
    }

    nuevo_estudiante->edad = edad;

    nuevo_estudiante->calificaciones = (int *)malloc(num_calificaciones * sizeof(int));
    if (nuevo_estudiante->calificaciones == NULL) {
        return NULL;
    }

    memcpy(nuevo_estudiante->calificaciones, calificaciones, num_calificaciones * sizeof(int));
    nuevo_estudiante->num_calificaciones = num_calificaciones;

    return nuevo_estudiante;
}

// Función pura para calcular la memoria utilizada por un estudiante
size_t calcular_memoria_usada(const Estudiante *estudiante) {
    return sizeof(Estudiante) +
           strlen(estudiante->nombre) + 1 +
           strlen(estudiante->apellido) + 1 +
           strlen(estudiante->ID) + 1 +
           estudiante->num_calificaciones * sizeof(int);
}

// Función pura para imprimir información del estudiante (no modifica el estado)
void imprimir_estudiante(const Estudiante *estudiante) {
    printf("Nombre: %s %s\n", estudiante->nombre, estudiante->apellido);
    printf("Edad: %u\n", estudiante->edad);
    printf("ID: %s\n", estudiante->ID);
    printf("Calificaciones: ");
    for (size_t i = 0; i < estudiante->num_calificaciones; i++) {
        printf("%d ", estudiante->calificaciones[i]);
    }
    printf("\n");
}

// Función para liberar la memoria del estudiante
void liberar_estudiante(Estudiante *estudiante) {
    if (estudiante != NULL) {
        free(estudiante->nombre);
        free(estudiante->apellido);
        free(estudiante->ID);
        free(estudiante->calificaciones);
        free(estudiante);
    }
}

// Función declarativa que elimina un estudiante basado en su ID (retorna un nuevo array sin modificar el original)
Estudiante **eliminar_estudiante(Estudiante *estudiantes[], size_t *num_estudiantes, const char *ID) {
    Estudiante **nuevo_array = (Estudiante **)malloc((*num_estudiantes - 1) * sizeof(Estudiante *));
    if (nuevo_array == NULL) return NULL;

    size_t j = 0;
    for (size_t i = 0; i < *num_estudiantes; i++) {
        if (strcmp(estudiantes[i]->ID, ID) != 0) {
            nuevo_array[j++] = estudiantes[i];
        } else {
            liberar_estudiante(estudiantes[i]);
        }
    }

    (*num_estudiantes)--;
    return nuevo_array;
}

// Función declarativa para agregar un estudiante (retorna un nuevo array con el estudiante añadido)
Estudiante **agregar_estudiante(Estudiante *estudiantes[], size_t *num_estudiantes, Estudiante *nuevo_estudiante) {
    Estudiante **nuevo_array = (Estudiante **)realloc(estudiantes, (*num_estudiantes + 1) * sizeof(Estudiante *));
    if (nuevo_array == NULL) return NULL;

    nuevo_array[*num_estudiantes] = nuevo_estudiante;
    (*num_estudiantes)++;

    return nuevo_array;
}

int main() {
    // Array de estudiantes
    Estudiante **estudiantes = NULL;
    size_t num_estudiantes = 0;

    // Crear calificaciones
    int calificaciones1[] = {85, 90, 78};
    int calificaciones2[] = {88, 76, 92};

    // Crear estudiantes y agregarlos
    Estudiante *est1 = crear_estudiante("Carlos", "Gomez", 20, "12345678", calificaciones1, 3);
    Estudiante *est2 = crear_estudiante("Ana", "Lopez", 21, "87654321", calificaciones2, 3);

    estudiantes = agregar_estudiante(estudiantes, &num_estudiantes, est1);
    estudiantes = agregar_estudiante(estudiantes, &num_estudiantes, est2);

    // Imprimir estudiantes
    for (size_t i = 0; i < num_estudiantes; i++) {
        imprimir_estudiante(estudiantes[i]);
        printf("Memoria utilizada: %zu bytes\n", calcular_memoria_usada(estudiantes[i]));
    }

    // Eliminar un estudiante
    estudiantes = eliminar_estudiante(estudiantes, &num_estudiantes, "12345678");

    // Imprimir estudiantes después de eliminar
    printf("\nDespués de eliminar:\n");
    for (size_t i = 0; i < num_estudiantes; i++) {
        imprimir_estudiante(estudiantes[i]);
        printf("Memoria utilizada: %zu bytes\n", calcular_memoria_usada(estudiantes[i]));
    }

    // Liberar memoria
    for (size_t i = 0; i < num_estudiantes; i++) {
        liberar_estudiante(estudiantes[i]);
    }
    free(estudiantes);

	return 0;
}
