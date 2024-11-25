#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include <iostream>
#include <string>

using namespace std;

//Clase padre de Diseñador y Programador

class Trabajador {
//Atributos de la clase padre
protected:
    string nombre;
    float salario;
    int idTrabajador;

public:
    //Constructor
    Trabajador(string nombre, float salario, int idTrabajador);

    //Uso de polimorfismo
    virtual void trabajar() = 0;
    virtual istream& leer(istream& in);
    virtual void imprimir();

    //Sobrecarga de operador
    friend ostream& operator<<(ostream& os, const Trabajador& trabajador);
    friend bool operator>(Trabajador& t1, Trabajador& t2);
    friend bool operator<(Trabajador& t1, Trabajador& t2);

    //Metodos get y set
    string getNombre();
    virtual float getSalario() const;
    int getIdTrabajador();

    void setNombre(string nombre);
    void setSalario(float salario);
    void setIdTrabajador(int idTrabajador);
};

#endif //TRABAJADOR_H
