#include "Proyecto.h"
using namespace std;

//Constructor
Proyecto::Proyecto(string nombreProyecto, int idProyecto) {
    this->nombreProyecto = nombreProyecto;
    this->idProyecto = idProyecto;
}

//Sobrecarga de metodo
Proyecto& Proyecto::operator+(float incrementoSalario) {
    for(auto& trabajador : trabajadores) {
        trabajador->setSalario(trabajador->getSalario() + incrementoSalario);
    }
    return *this;
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
const vector<Trabajador*> &Proyecto::getTrabajadores() {
    return trabajadores;
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

int Proyecto::buscarTrabajador(int id) {
    int encontrado = -1;
    for (int i = 0; i < trabajadores.size(); i++) {
        if (trabajadores[i]->getIdTrabajador() == id) {
            encontrado = i;
        }
    }
    return encontrado;
}