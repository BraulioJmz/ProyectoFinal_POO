#include "Disenador.h"
#include "Trabajador.h"

Disenador::Disenador(string nombre, float salario, int idTrabajador, string herramientaDiseno,
    string tipoDiseno) : Trabajador(nombre, salario, idTrabajador) {
    this -> herramientaDiseno = herramientaDiseno;
    this -> tipoDiseno = tipoDiseno;
}

//Funcion de polimorfismo trabajar
void Disenador::trabajar() {
    cout << "El designer "<< nombre << " trabaja en " << herramientaDiseno  << endl;
}

//Metodos get y set

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


