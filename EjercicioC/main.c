#include <stdio.h>
#include <string.h>

// Inicio parte 1: Estructura del estudiante
// Se crea una estructura llamada Estudiante donde se almacena el nombre, edad y promedio de un estudiante
struct Estudiante{
    char nombre [50];
    int edad;
    int promedio;
};

// Se crea una función llamada mostrarEstudiante que muestra los datos del estudiante
void mostrarEstudiante(){
    struct Estudiante estudiante;
    strcpy(estudiante.nombre, "Juan");
    estudiante.edad = 20;
    estudiante.promedio = 10;
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Edad: %d\n", estudiante.edad);
    printf("Promedio: %d\n", estudiante.promedio);
}
// Fin parte 1: Estructura del estudiante
int main() {
    mostrarEstudiante();
}
