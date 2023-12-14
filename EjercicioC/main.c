#include <stdio.h>
#include <string.h>


// Inicio parte 1: Estructura del estudiante
// Se crea la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    char materias[10][50];
    int numMaterias;
};

// Function to display student information
void mostrarEstudiante(const struct Estudiante *estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);
    printf("Materias: ");
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        printf("%s ", estudiante->materias[i]);
    }
    printf("\n");
}
// Fin parte 1: Estructura del estudiante
// Inicio parte 2: Gestión de materias
void agregarMateria(struct Estudiante *estudiante, const char *materia) {
    strcpy(estudiante->materias[estudiante->numMaterias], materia);
    estudiante->numMaterias++;
}

void eliminarMateria(struct Estudiante *estudiante, const char *materia) {
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            for (int j = i; j < estudiante->numMaterias - 1; ++j) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--;
            break;
        }
    }
}
// Fin parte 2: Gestión de materias

int main() {
    struct Estudiante estudiante;
    strcpy(estudiante.nombre, "Juan");
    estudiante.edad = 20;
    estudiante.promedio = 10.0;
    estudiante.numMaterias = 0;

    agregarMateria(&estudiante, "Matematicas");

    mostrarEstudiante(&estudiante);

    return 0;
}