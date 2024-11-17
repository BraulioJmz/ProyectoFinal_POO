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
//Métodos para manipular proyectos
void Empresa::anadirProyecto() {
    string nombre;
    int id;

    cout << endl << "Dar de alta proyecto" << endl;
    cout << "Ingrese el nombre del proyecto: ";
    cin >> nombre;
    cout << "Ingrese el ID del proyecto: ";
    cin >> id;
    proyectos.push_back(new Proyecto(nombre,id));
}
void Empresa::eliminarProyecto() {
    int id,flag=0;
    cout << endl << "Eliminar un proyecto" << endl;
    cout << "Ingrese el ID del proyecto: ";
    cin >> id;

    for (int i = 0; i < proyectos.size(); ++i) {
        if (proyectos[i]->getIdProyecto() == id) {
            flag = 1;
            proyectos.erase(proyectos.begin() + i);
            break;
        }
    }

    if (flag==1) {
        cout << "Proyecto eliminado." << endl;
    }
    else {
        cout << "Proyecto no encontrado." << endl;
    }
}
void Empresa::mostrarProyectos() {
    cout << endl << "Mostrar todos los proyectos" << endl;
    for (int i = 0; i < proyectos.size(); i++) {
        cout << "Id: " << proyectos[i]->getIdProyecto() << endl;
        cout << "Nombre: " << proyectos[i]->getNombreProyecto() << endl << endl;
    }
}
Proyecto *Empresa::buscarProyecto() {
    int id;
    cout << endl << "Buscar un proyecto" << std::endl;
    cout << "Ingrese el ID del proyecto: ";
    cin >> id;

    Proyecto* encontrado = nullptr;
    for (int i = 0; i < proyectos.size(); ++i) {
        if (proyectos[i]->getIdProyecto() == id) {
            encontrado = proyectos[i];
            break;
        }
    }

    if (encontrado) {
        cout << "Proyecto encontrado: " << encontrado->getNombreProyecto() << endl;
    }
    else {
        cout << "Proyecto no encontrado." << endl;
    }
    return nullptr;
}
