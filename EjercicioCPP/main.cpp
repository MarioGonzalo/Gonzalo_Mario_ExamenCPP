#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

// Inicio parte 1: Estructura del estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    vector<string> materias;
};

struct Asistencia {
    int fecha;
    bool asistio;
    string materia;
};

void mostrarEstudiante(const Estudiante& estudiante) {
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;
    cout << "Materias: ";
    for (const string& materia : estudiante.materias) {
        cout << materia << " ";
    }
    cout << endl;
}
// Fin parte 1: Estructura del estudiante

// Inicio parte 2: Gestión de materias
// Se crea un void para agregar materias al vector de materias del estudiante
void agregarMateria(Estudiante& estudiante, const string& materia) {
    estudiante.materias.push_back(materia);
}
// Fin parte 2: Gestión de materias

// Inicio parte 3: Gestión de asistencias
// Se crea un void para especificar la asistencia
void agregarAsistencia(Asistencia& asistencia) {
    cout << "Ingrese la fecha: ";
    cin >> asistencia.fecha;
    cout << "Ingrese la materia: ";
    cin >> asistencia.materia;
    cout << "Ingrese la asistencia (1: asistio, 0: no asistio): ";
    cin >> asistencia.asistio;
}
// Fin parte 3: Gestión de asistencias
int main() {
    Estudiante estudiante;
    strcpy(estudiante.nombre, "Juan");
    estudiante.edad = 20;
    estudiante.promedio = 10;

    agregarMateria(estudiante, "Matematicas");

    mostrarEstudiante(estudiante);

    return 0;
}
