#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio;
    bool disponible;
};

struct Administradores{
    string nombre;
    string cargo;
    int edad;
    char sexo;
};

struct Estudiantes{
    string nombre;
    string carrera;
    string codigo;
    int edad;
    char sexo;
    Libro librosPrestados[10];
    int numLibrosPrestados = 0;
};

void agregarEstudiante(string, string, string, int, char);
void agregarAdministrador(string, string, int, char);
void mostrarDatosEstudiante();
void mostrarDatosAdministrador();
void agregarLibro(string titulo, string autor, int anio);
bool libroExiste(string titulo);
void mostrarLibros();
void eliminarLibro(string titulo);
void inicializarLibros();
void cargarDatos();
void guardarDatos();
#endif 
