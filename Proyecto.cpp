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