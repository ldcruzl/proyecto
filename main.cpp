#include <iostream>
#include "biblioteca.h"
#include <cctype>
using namespace std;

int main(){
    char tipoUsuario;
    bool esAdmin;
    bool usuarioValido = false;
    //Datos del estudiante
    string nombreEstudiante;
    string carrera;
    string codigo;
    int edadEstudiante;
    char sexoEstudiante;

    //Datos del administrador
    string nombreAdminsitrador;
    string cargo;
    int edadAdministrador;
    char sexoAdministrador;
    
    cargarDatos();

    while (usuarioValido == false){
        cout<<"Ingrese el tipo de usuario (A para administrador, E para estudiante): ";cin>>tipoUsuario;
        tipoUsuario = toupper(tipoUsuario);
    
        if (tipoUsuario == 'A'){
            esAdmin = true;
            usuarioValido = true;
            cin.ignore(); 
            cout<<"Ingrese su nombre: "; getline(cin, nombreAdminsitrador); 
            cout<<"Ingrese su cargo: ";getline(cin, cargo);
            cout<<"Ingrese su edad: ";cin>>edadAdministrador;
            cout<<"Ingrese su sexo (M)(F): ";cin>>sexoAdministrador;
            sexoAdministrador = toupper(sexoAdministrador);
            agregarAdministrador(nombreAdminsitrador, cargo, edadAdministrador, sexoAdministrador);

        }else if (tipoUsuario == 'E'){
            esAdmin = false;
            usuarioValido = true;
            cin.ignore(); 
            cout<<"Ingrese su nombre: "; getline(cin, nombreEstudiante); 
            cout<<"Ingrese su carrera: ";getline(cin, carrera);
            cout<<"Ingrese su codigo universitario: ";cin>>codigo;
            cout<<"Ingrese su edad: ";cin>>edadEstudiante;
            cout<<"Ingrese su sexo (M)(F): ";cin>>sexoEstudiante;
            sexoEstudiante = toupper(sexoEstudiante);
            agregarEstudiante(nombreEstudiante, carrera, codigo, edadEstudiante, sexoEstudiante);
        }else{
            cout<<"La entrada no es valida"<<endl;
            }
        }

    int op;
    cout<<"=================================================="<<endl;
    cout<<"         Bienvenido a la BIBLIOTECA "<<endl;
    cout<<"=================================================="<<endl;    

    inicializarLibros();
    do{
        cout<<"Menu de opciones:"<<endl;
        if (esAdmin == true){
            cout<<"1. Agregar libro"<<endl;
            cout<<"2. Eliminar libro"<<endl;
            cout<<"4. Mostrar datos"<<endl;
        }
        else{
            cout<<"3. Mostrar libros"<<endl;
            cout<<"5. Solicitar libro"<<endl;
            cout<<"6. Devolver libro"<<endl;
        }
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: ";cin>>op;

        string titulo, autor;
        int anio;
        string tlibro;

        switch (op){
            case 1:
                if (esAdmin == true){
                    cin.ignore(); 
                    cout<<"Ingrese el titulo del libro: "; getline(cin, titulo);
                    cout<<"Ingrese el autor del libro: "; getline(cin, autor);
                    cout<<"Ingrese el anio del libro: ";cin>>anio;

                    agregarLibro(titulo, autor, anio);
                }else{
                    cout<<"Opcion invalida, intente de nuevo."<<endl;
                }
                cout<<endl;
                break;
            case 2:
                if (esAdmin == true){
                    cin.ignore(); cout<<"Ingrese el titulo del libro que desea eliminar: "; getline(cin, titulo);
                    eliminarLibro(titulo);
                }else{
                    cout<<"Opcion invalida, intente de nuevo"<<endl;
                }
                break;
            case 3:
                mostrarLibros();
                break;
            case 4:
                char opDatos;
                if (esAdmin == true){
                    cout<<"Ingrese los datos del tipo de usuario que desea mostrar (A para administrador, E para estudiante): ";cin>>opDatos;
                    opDatos = toupper(opDatos);

                    if (opDatos == 'A'){
                        mostrarDatosAdministrador();
                    } else if (opDatos == 'E'){
                        mostrarDatosEstudiante();
                    } else {
                        cout<<"Opcion invalida, intente de nuevo"<<endl;
                    }
                }else{
                    mostrarDatosEstudiante();
                }
                break;
            case 5:
                cin.ignore();
                cout<<"Ingrese su codigo: ";getline(cin, codigo);
                cout<<"Ingrese titulo del libro: ";getline(cin, tlibro);
                solicitarLibro(codigo, tlibro);
                break;
            case 6:
                cin.ignore();
                cout<<"Ingrese su codigo: ";getline(cin, codigo);
                cout<<"Ingrese titulo del libro a devolver: ";getline(cin, tlibro);
                devolverLibro(codigo, tlibro);
                break;
            case 7:
                if (esAdmin == true){
                    mostrarLibrosPrestadosAdmin();
                }else{
                    mostrarLibrosPrestadosEstudiantes();
                }
                break;
            case 0:
                cout<<"Saliendo..."<<endl;
                guardarDatos();
                break;
            default:
                cout<<"Opcion invalida, intente de nuevo."<<endl;
                cout<<endl;
                break;
        }

    } while (op != 0);

    return 0;
}