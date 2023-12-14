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
    int dia;
    int mes;
    int ano;
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
    if (estudiante.materias.size() > 10) {
        throw runtime_error("El estudiante no puede tener mas de 10 materias");
    }
    if(materia == " "){
        throw runtime_error("La materia no puede estar vacia");
    }
}
void eliminarMateria(Estudiante& estudiante, const string& materia) {
    for (int i = 0; i < estudiante.materias.size(); ++i) {
        if (estudiante.materias[i] == materia) {
            estudiante.materias.erase(estudiante.materias.begin() + i);
            break;
        } else {
            throw runtime_error("La materia no existe");
        }
    }
}
// Fin parte 2: Gestión de materias

// Inicio parte 3: Gestión de asistencias
// Se crea un void para especificar la asistencia
void agregarAsistencia(Asistencia& asistencia) {
    cout << "Ingrese el dia: ";
    cin >> asistencia.dia;
    if(asistencia.dia > 31 || asistencia.dia < 1){
        throw runtime_error("El dia ingresado no es valido");
    }
    cout << "Ingrese el mes: ";
    cin >> asistencia.mes;
    if(asistencia.mes > 12 || asistencia.mes < 1){
        throw runtime_error("El mes ingresado no es valido");
    }
    cout << "Ingrese el año: ";
    cin >> asistencia.ano;
    if(asistencia.ano < 2023){
        throw runtime_error("El año ingresado no es valido");
    }
    cout << "Ingrese la materia: ";
    cin >> asistencia.materia;
    cout << "Ingrese la asistencia (1: asistio, 0: no asistio): ";
    cin >> asistencia.asistio;
}

// Se crea un void para mostrar la asistencia
void mostrarAsistencia(const Asistencia& asistencia, const Estudiante& estudiante) {
    cout << "El dia " << asistencia.dia << "/" << asistencia.mes << "/" << asistencia.ano;
    cout << " el alumno "<< estudiante.nombre << " convocado a clase de " << asistencia.materia;
    if(asistencia.asistio == 1){
        cout << " asistio" << endl;
} else {
    cout << " no asistio" << endl;
}
}
// Fin parte 3: Gestión de asistencias
int main() {

    Estudiante estudiante;
    strcpy(estudiante.nombre, "Juan");
    estudiante.edad = 20;
    estudiante.promedio = 10;

    agregarMateria(estudiante, "Matematicas");

    Asistencia asistencia;

    agregarAsistencia(asistencia);

    mostrarAsistencia(asistencia, estudiante);

    mostrarEstudiante(estudiante);

    try {
        agregarAsistencia(asistencia);
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    try {
        agregarMateria(estudiante, " ");
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    try {
        eliminarMateria(estudiante, "Matematicas");
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
