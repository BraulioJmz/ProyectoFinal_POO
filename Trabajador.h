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

    //Metodos get y set
    string getNombre();
    float getSalario();
    int getIdTrabajador();

    void setNombre(string nombre);
    void setSalario(float salario);
    void setIdTrabajador(int idTrabajador);
};

#endif //TRABAJADOR_H
