#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para almacenar la información del estudiante
typedef struct {
    char *nombre;
    char *apellido;
    unsigned int edad : 7;  // Usamos bitfields para reducir el tamaño de edad (0-127)
    char *ID;
    int *calificaciones;
    size_t num_calificaciones;
} Estudiante;

// Función para crear un nuevo estudiante
Estudiante *crear_estudiante(const char *nombre, const char *apellido, unsigned int edad, const char *ID, int *calificaciones, size_t num_calificaciones) {
    // Asignar memoria para el estudiante
    Estudiante *nuevo_estudiante = (Estudiante *)malloc(sizeof(Estudiante));
    if (nuevo_estudiante == NULL) {
        printf("Error al asignar memoria para el estudiante.\n");
        return NULL;
    }

    // Asignar memoria para nombre, apellido, ID y copiarlos
    nuevo_estudiante->nombre = (char *)malloc(strlen(nombre) + 1);
    nuevo_estudiante->apellido = (char *)malloc(strlen(apellido) + 1);
    nuevo_estudiante->ID = (char *)malloc(strlen(ID) + 1);

    if (nuevo_estudiante->nombre == NULL || nuevo_estudiante->apellido == NULL || nuevo_estudiante->ID == NULL) {
        printf("Error al asignar memoria para los campos de texto.\n");
        free(nuevo_estudiante->nombre);
        free(nuevo_estudiante->apellido);
        free(nuevo_estudiante->ID);
        free(nuevo_estudiante);
        return NULL;
    }

    strcpy(nuevo_estudiante->nombre, nombre);
    strcpy(nuevo_estudiante->apellido, apellido);
    strcpy(nuevo_estudiante->ID, ID);

    // Asignar edad
    nuevo_estudiante->edad = edad;

    // Asignar memoria para las calificaciones y copiarlas
    nuevo_estudiante->calificaciones = (int *)malloc(num_calificaciones * sizeof(int));
    if (nuevo_estudiante->calificaciones == NULL) {
        printf("Error al asignar memoria para las calificaciones.\n");
        free(nuevo_estudiante->nombre);
        free(nuevo_estudiante->apellido);
        free(nuevo_estudiante->ID);
        free(nuevo_estudiante);
        return NULL;
    }
	
	size_t i=0;
    for (i = 0; i < num_calificaciones; i++) {
        nuevo_estudiante->calificaciones[i] = calificaciones[i];
    }

    nuevo_estudiante->num_calificaciones = num_calificaciones;

    return nuevo_estudiante;
}

// Función para liberar la memoria de un estudiante
void liberar_estudiante(Estudiante *estudiante) {
    if (estudiante != NULL) {
        free(estudiante->nombre);
        free(estudiante->apellido);
        free(estudiante->ID);
        free(estudiante->calificaciones);
        free(estudiante);
    }
}

// Función para imprimir la información de un estudiante
void imprimir_estudiante(const Estudiante *estudiante) {
    if (estudiante != NULL) {
        printf("Nombre: %s %s\n", estudiante->nombre, estudiante->apellido);
        printf("Edad: %u\n", estudiante->edad);
        printf("ID: %s\n", estudiante->ID);
        printf("Calificaciones: ");
        size_t j=0;
        for (j = 0; j < estudiante->num_calificaciones; j++) {
            printf("%d ", estudiante->calificaciones[j]);
        }
        printf("\n");
    }
}

// Función para calcular la memoria utilizada por un estudiante
size_t calcular_memoria_usada(const Estudiante *estudiante) {
    size_t memoria_usada = sizeof(Estudiante) + 
                           strlen(estudiante->nombre) + 1 + 
                           strlen(estudiante->apellido) + 1 + 
                           strlen(estudiante->ID) + 1 + 
                           estudiante->num_calificaciones * sizeof(int);
    return memoria_usada;
}

// Función para eliminar un estudiante por su ID
Estudiante *eliminar_estudiante(Estudiante *estudiantes[], size_t *num_estudiantes, const char *ID) {
	size_t k=0;
    for (k = 0; k < *num_estudiantes; k++) {
        if (strcmp(estudiantes[k]->ID, ID) == 0) {
            // Liberar memoria del estudiante
            liberar_estudiante(estudiantes[k]);

            // Mover el último estudiante al lugar del eliminado para evitar huecos
            estudiantes[k] = estudiantes[*num_estudiantes - 1];
            (*num_estudiantes)--;

            printf("Estudiante con ID %s eliminado correctamente.\n", ID);
            return NULL;
        }
    }
    printf("Estudiante con ID %s no encontrado.\n", ID);
    return NULL;
}

int main() {
    // Almacén de estudiantes
    Estudiante *estudiantes[100];
    size_t num_estudiantes = 0;

    // Ejemplo de calificaciones
    int calificaciones1[] = {85, 90, 78};
    

    // Crear y agregar estudiantes
    estudiantes[num_estudiantes++] = crear_estudiante("Carlos", "Gomez", 20, "12345678", calificaciones1, 3);
   

    // Imprimir información de estudiantes y memoria utilizada
    size_t l=0;
    for (l= 0; l < num_estudiantes; l++) {
        imprimir_estudiante(estudiantes[l]);
        size_t memoria_usada = calcular_memoria_usada(estudiantes[l]);
        printf("Memoria utilizada: %zu bytes\n", memoria_usada);
    }

    // Eliminar un estudiante
    eliminar_estudiante(estudiantes, &num_estudiantes, "12345678");

    // Imprimir información después de la eliminación
    size_t a=0;
    for ( a = 0; a < num_estudiantes; a++) {
        imprimir_estudiante(estudiantes[a]);
        size_t memoria_usada = calcular_memoria_usada(estudiantes[a]);
        printf("Memoria utilizada: %zu bytes\n", memoria_usada);
    }

    // Liberar memoria de los estudiantes restantes
    size_t b=0;
    for (b = 0; b< num_estudiantes; b++) {
        liberar_estudiante(estudiantes[b]);
    }

    return 0;
}

