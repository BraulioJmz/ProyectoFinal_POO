#include "Proyecto.h"
using namespace std;

//Constructor
Proyecto::Proyecto(string nombreProyecto, int idProyecto) {
    this->nombreProyecto = nombreProyecto;
    this->idProyecto = idProyecto;
}

//Gets y Setters
int Proyecto::getIdProyecto() {
    return idProyecto;
}
void Proyecto::setIdProyecto(int idProyecto) {
    this->idProyecto = idProyecto;
}
string Proyecto::getNombreProyecto() {
    return nombreProyecto;
}
void Proyecto::setNombreProyecto(string nombreProyecto) {
    this->nombreProyecto = nombreProyecto;
}

//Métodos para manipular proyectos
void Proyecto::anadirTrabajador(Trabajador* trabajador) {
    trabajadores.push_back(trabajador);
}

void Proyecto::eliminarTrabajador(int idTrabajador) {
    for (int i = 0; i < trabajadores.size(); i++) {
        if (trabajadores[i]->getIdTrabajador() == idTrabajador) {
            trabajadores.erase(trabajadores.begin() + i);
            break;
        }
    }
}

Trabajador* Proyecto::buscarTrabajador(int idTrabajador) {
    for (int i = 0; i < trabajadores.size(); i++) {
        if (trabajadores[i]->getIdTrabajador() == idTrabajador) {
            return trabajadores[i];
        }
    }
    return nullptr;
}