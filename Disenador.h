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
    Disenador(string nombre, float salario, int idTrabajador,
        string herramientaDiseno, string tipoDiseno);

    //Polimorfismo
    void trabajar() override;

    //Sobrecarga del operador de entrada con polimorfismo
    istream& leer(istream &in) override;

    //Metodos get y set
    string getHerramientaDiseno();
    string getTipoDiseno();

    void setHerramientaDiseno(string herramientaDiseno);
    void setTipoDiseno(string tipoDiseno);

};

#endif //DISENADOR_H
