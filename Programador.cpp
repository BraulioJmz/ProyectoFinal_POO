#include "Programador.h"
#include "Trabajador.h"

Programador::Programador(string nombre, float salario, int idTrabajador, string lenguaje,
    string especializacion) :Trabajador(nombre, salario, idTrabajador) {
    this -> lenguaje = lenguaje;
    this -> especializacion = especializacion;
}

//Funcion de polimorfismo trabajar
void Programador::trabajar() {
    cout << "El programador " << nombre << " trabaja en " << lenguaje << endl;
}

//Metodos get y set

string Programador::getLenguaje() {
    return lenguaje;
}

string Programador::getEspecializacion() {
    return especializacion;
}

void Programador::setLenguaje(string lenguaje) {
    this -> lenguaje = lenguaje;
}

void Programador::setEspecializacion(string especializacion) {
    this -> especializacion = especializacion;
}




