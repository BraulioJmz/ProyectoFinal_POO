#include "Trabajador.h"

//Constructor
Trabajador::Trabajador(string nombre, float salario, int idTrabajador) {
    this -> nombre = nombre;
    this -> salario = salario;
    this -> idTrabajador = idTrabajador;
}

//Sobrecarga del funcion leer
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

void Trabajador::imprimir() {
    cout << endl << "Trabajador encontrado" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Salario: " << salario << endl;
}

//Sobrecarga de operador
ostream& operator<<(ostream& os, const Trabajador& trabajador) {
    os << "ID: " << trabajador.idTrabajador << endl;
    os << "Nombre: " << trabajador.nombre  << endl;
    os << "Salario: " << trabajador.salario << endl;
    return os;
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



