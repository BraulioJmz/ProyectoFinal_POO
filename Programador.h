#ifndef PROGRAMADOR_H
#define PROGRAMADOR_H

#include "Trabajador.h"
#include <iostream>
#include <string>

using namespace std;

class Programador : public Trabajador{
private:
    string lenguaje;
    string especializacion;

public:
    //Constructor
    Programador();
    Programador(string nombre, float salario, int idTrabajador, string lenguaje,
        string especializacion);

    //Polimorfismo
    void trabajar() override;
    void imprimir() override;

    //Sobrecarga del operador de entrada con polimorfismo
    istream& leer(istream &in) override;
    friend istream& operator>>(istream& in, Programador& developer);

    //Sobrecarga del operador de salida
    friend ostream& operator<<(ostream& os, Programador& developer);

    //Metodos get y set
    string getLenguaje() const;
    string getEspecializacion() const;

    void setLenguaje(string lenguaje);
    void setEspecializacion(string especializacion);

};

#endif //PROGRAMADOR_H
