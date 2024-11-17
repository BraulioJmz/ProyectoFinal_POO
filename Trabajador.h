#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include <iostream>
#include <string>

using namespace std;

class Trabajador {
//Atributos de la clase padre
protected:
    string nombre;
    float salario;
    int idTrabajador;

public:
    //Constructor
    Trabajador(string, float, int);

    //Metodos get y set
    string getNombre();
    float getSalario();
    int getIdTrabajador();

    void setNombre(string nombre);
    void setSalario(float salario);
    void setIdTrabajador(int idTrabajador);
};



#endif //TRABAJADOR_H
