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
void Empresa::anadirProyecto(Proyecto* proyecto) {
    proyectos.push_back(proyecto);
}
void Empresa::eliminarProyecto(int idProyecto) {
    for (int i = 0; i < proyectos.size(); i++) {
        if (proyectos[i]->getIdProyecto() == idProyecto) {
            proyectos.erase(proyectos.begin() + i);
            break;
        }
    }
}
void Empresa::mostrarProyectos() {
    for (int i = 0; i < proyectos.size(); i++) {
        cout << "Id: " << proyectos[i]->getIdProyecto() << endl;
        cout << "Nombre: " << proyectos[i]->getNombreProyecto() << endl;
    }
}
Proyecto *Empresa::buscarProyecto(int idProyecto) {
    for (int i = 0; i < proyectos.size(); i++) {
        if (proyectos[i]->getIdProyecto() == idProyecto) {
            return proyectos[i];
        }
    }
    return nullptr;
}