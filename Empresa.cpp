#include "Empresa.h"
using namespace std;

//Constructor
Empresa::Empresa(string nombreEmpresa) {
    this -> nombreEmpresa = nombreEmpresa;
}
//Gets y Setters
string Empresa::getNombreEmpresa() {
    return nombreEmpresa;}

void Empresa::setNombreEmpresa(string nombreEmpresa) {
    this -> nombreEmpresa = nombreEmpresa;
}
const vector <Proyecto*>& Empresa::getProyectos() {
    return proyectos;
}

//Métodos para manipular proyectos
void Empresa::anadirProyecto() {
    string nombre;
    int id, flag = 0;

    cout << endl << "Dar de alta proyecto..." << endl;

    //Limpieza de bufer de entrada
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese el nombre del proyecto: ";
    getline(cin, nombre);

    cout << "Ingrese el ID del proyecto: ";
    cin >> id;

    for (int i = 0; i < proyectos.size(); i++) {
        if(proyectos[i]->getIdProyecto() == id) {
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        cout << "\nEl ID ingresado ya pertenece a un proyecto" << endl;
    }
    else {
        proyectos.push_back(new Proyecto(nombre,id));
    }
}


void Empresa::eliminarProyecto() {
    int id,flag=0;
    int confirmacion;
    cout << endl << "Eliminar un proyecto..." << endl;
    cout << "Ingrese el ID del proyecto: ";
    cin >> id;

    for (int i = 0; i < proyectos.size(); ++i) {
        if (proyectos[i]->getIdProyecto() == id) {
            cout << "Confirmar eliminacion" << endl;
            cout << "1 para eliminar, 0 para cancelar" << endl;
            cout << "Seleccion: ";
            cin >> confirmacion; cin.ignore();
            if (confirmacion == 1) {
                flag = 1;
                proyectos.erase(proyectos.begin() + i);
                break;
            }
            else {
                flag = 2;
                break;
            }

        }
    }

    if (flag==1) {
        cout << "Proyecto eliminado" << endl;
    }
    else if (flag == 2) {
        cout << "Eliminacion cancelada" << endl;
    }
    else {
        cout << "Proyecto no encontrado" << endl;
    }
}

void Empresa::mostrarProyectos() {
    cout << endl << "Mostrar todos los proyectos" << endl;
    for (int i = 0; i < proyectos.size(); i++) {
        cout << "Id: " << proyectos[i]->getIdProyecto() << endl;
        cout << "Nombre: " << proyectos[i]->getNombreProyecto() << endl << endl;
    }
}

int Empresa::buscarProyecto(int id) {
    int encontrado = -1;
    for (int i = 0; i < proyectos.size(); ++i) {
        if (proyectos[i]->getIdProyecto() == id) {
            encontrado = i;
            break;
        }
    }
    return encontrado;
}

