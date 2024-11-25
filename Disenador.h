#ifndef DISENADOR_H
#define DISENADOR_H

#include "Trabajador.h"
#include <iostream>
#include <string>

using namespace std;

class Disenador : public Trabajador{
private:
    string herramientaDiseno;
    string tipoDiseno;

public:
    //Constructor
    Disenador();
    Disenador(string nombre, float salario, int idTrabajador,
        string herramientaDiseno, string tipoDiseno);

    //Polimorfismo
    void trabajar() override;
    void imprimir() override;
    float getSalario() const override;

    //Sobrecarga de función leer y sobrecarga del operador de entrada
    istream& leer(istream &in) override;
    friend istream& operator>>(istream& in, Disenador& designer);

    //Sobrecarga del operador de salida
    friend ostream& operator<<(ostream& os, Disenador& designer);

    //Metodos get y set
    string getHerramientaDiseno () const;
    string getTipoDiseno () const;

    void setHerramientaDiseno(string herramientaDiseno);
    void setTipoDiseno(string tipoDiseno);

};

#endif //DISENADOR_H
