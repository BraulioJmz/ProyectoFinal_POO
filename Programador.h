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
    Programador(string nombre, float salario, int idTrabajador, string lenguaje,
        string especializacion);

    //Polimorfismo
    void trabajar() override;

    //Sobrecarga del operador de entrada con polimorfismo
    istream& leer(istream &in) override;

    //Metodos get y set
    string getLenguaje();
    string getEspecializacion();

    void setLenguaje(string lenguaje);
    void setEspecializacion(string especializacion);

};

#endif //PROGRAMADOR_H
