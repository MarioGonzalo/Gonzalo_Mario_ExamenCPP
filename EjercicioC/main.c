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

// Se crea la estructura Asistencia
struct Asistencia {
    int dia;
    int mes;
    int ano;
    int asistio;
    char materia[50];
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

// Inicio parte 3: Gestión de asistencias
// Se crea un void para especificar la asistencia
void agregarAsistencia(struct Asistencia *asistencia) {
    printf("Ingrese el dia: ");
    scanf("%d", &asistencia->dia);
    if (asistencia->dia < 1 || asistencia->dia > 31) {
        printf("El dia debe estar entre 1 y 31\n");
        return;
    }
    printf("Ingrese el mes: ");
    scanf("%d", &asistencia->mes);
    if (asistencia->mes < 1 || asistencia->mes > 12) {
        printf("El mes debe estar entre 1 y 12\n");
        return;
    }
    printf("Ingrese el año: ");
    scanf("%d", &asistencia->ano);
    if (asistencia->ano < 2023) {
        printf("El año debe ser menor a 2023\n");
        return;
    }
    printf("Ingrese si asistio (1) o no asistio (0): ");
    scanf("%d", &asistencia->asistio);
    printf("Ingrese la materia: ");
    scanf("%s", asistencia->materia);
}
void mostrarAsistencia(const struct Asistencia *asistencia) {
    printf("Fecha: %d/%d/%d\n", asistencia->dia, asistencia->mes, asistencia->ano);
    printf("Asistio: %s\n", asistencia->asistio ? "Si" : "No");
    printf("Materia: %s\n", asistencia->materia);
}
// Fin parte 3: Gestión de asistencias

int main() {
    struct Estudiante estudiante;
    strcpy(estudiante.nombre, "Juan");
    estudiante.edad = 20;
    estudiante.promedio = 10.0;
    estudiante.numMaterias = 0;

    agregarMateria(&estudiante, "Matematicas");

    struct Asistencia asistencia;

    agregarAsistencia(&asistencia);

    mostrarAsistencia(&asistencia);
    mostrarEstudiante(&estudiante);

    return 0;
}