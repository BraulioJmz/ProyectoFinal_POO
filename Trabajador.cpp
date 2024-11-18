#include "Trabajador.h"

//Constructor
Trabajador::Trabajador(string nombre, float salario, int idTrabajador) {
    this -> nombre = nombre;
    this -> salario = salario;
    this -> idTrabajador = idTrabajador;
}

//Sobrecarga del operador de entrada
istream& Trabajador::leer(istream& in) {
    cout << "Nombre del trabajador: ";
    in.ignore();
    getline(in, nombre);

    cout << "Salario del trabajador: ";
    in >> salario;

    cout << "ID del trabajador: ";
    in >> idTrabajador;

    return in;
}


//Metodos get y set
string Trabajador::getNombre() {
    return nombre;
}

float Trabajador::getSalario() {
    return salario;
}

int Trabajador::getIdTrabajador() {
    return idTrabajador;
}

void Trabajador::setNombre(string nombre) {
    this -> nombre = nombre;
}

void Trabajador::setSalario(float salario) {
    this -> salario = salario;
}

void Trabajador::setIdTrabajador(int idTrabajador) {
    this -> idTrabajador = idTrabajador;
}



