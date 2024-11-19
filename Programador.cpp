#include "Programador.h"
#include "Trabajador.h"

Programador::Programador() : Trabajador("",0.0f,0),
lenguaje(""), especializacion(""){}

Programador::Programador(string nombre, float salario, int idTrabajador, string lenguaje,
    string especializacion) :Trabajador(nombre, salario, idTrabajador) {
    this -> lenguaje = lenguaje;
    this -> especializacion = especializacion;
}

//Funcion de polimorfismo trabajar
void Programador::trabajar() {
    cout << "El programador " << nombre << " trabaja en " << lenguaje << endl;
}

istream& Programador::leer(istream &in) {
    Trabajador::leer(in);
    cout << "Lenguaje programacion: ";
    in.ignore();
    getline(cin, lenguaje);

    cout << "Especializacion: ";
    getline(cin, especializacion);

    return in;
}

istream& operator>>(istream& in, Programador& developer) {
    developer.leer(in);
    return in;
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




