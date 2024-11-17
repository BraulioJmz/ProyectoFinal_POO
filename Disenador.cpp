#include "Disenador.h"
#include "Trabajador.h"

Disenador::Disenador(string nombre, float salario, int idTrabajador, string herramientaDiseno,
    string tipoDiseno) : Trabajador(nombre, salario, idTrabajador) {
    this -> herramientaDiseno = herramientaDiseno;
    this -> tipoDiseno = tipoDiseno;
}

//Funcion de polimorfismo
void Disenador::trabajar() {
    cout << "El diseñador "<< nombre << "trabaja en " << herramientaDiseno  << endl;
}

string Disenador::getHerramientaDiseno() {
    return herramientaDiseno;
}

string Disenador::getTipoDiseno() {
    return tipoDiseno;
}

void Disenador::setHerramientaDiseno(string herramientaDiseno) {
    this->herramientaDiseno = herramientaDiseno;
}

void Disenador::setTipoDiseno(string tipoDiseno) {
    this->tipoDiseno = tipoDiseno;
}


