#include <iostream>
#include <string.h>

using namespace std;

//Inicio parte 1: Estructura del estudiante
// Se crea una estructura llamada Estudiante donde se almacena el nombre, edad y promedio de un estudiante
struct Estudiante{
    char nombre [50];
    int edad;
    int promedio;
};

// Se crea una función llamada mostrarEstudiante que muestra los datos del estudiante
void mostrarEstudiante(){
    Estudiante estudiante;
    strcpy(estudiante.nombre, "Juan");
    estudiante.edad = 20;
    estudiante.promedio = 10;
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;
}
// Fin parte 1: Estructura del estudiante

int main() {
    mostrarEstudiante();
}
