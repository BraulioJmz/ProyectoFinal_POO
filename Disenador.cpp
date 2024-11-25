#include "Disenador.h"
#include "Trabajador.h"

Disenador::Disenador(): Trabajador("", 0.0f, 0),
herramientaDiseno(""), tipoDiseno("") {}

Disenador::Disenador(string nombre, float salario, int idTrabajador, string herramientaDiseno,
    string tipoDiseno) : Trabajador(nombre, salario, idTrabajador) {
    this -> herramientaDiseno = herramientaDiseno;
    this -> tipoDiseno = tipoDiseno;
}

//Funcion de polimorfismo trabajar
void Disenador::trabajar() {
    cout << "El designer "<< nombre << " trabaja en " << herramientaDiseno  << endl;
}

//Sobrecarga de función leer y sobrecarga del operador de entrada

istream& Disenador::leer(istream &in) {
    Trabajador::leer(in);
    cout << "Herramienta design: ";
    in.ignore();
    getline(cin, herramientaDiseno);

    cout << "Tipo de design: ";
    getline(cin, tipoDiseno);

    return in;
}

istream& operator>>(istream& in, Disenador& designer) {
    designer.leer(in);
    return in;
}

ostream& operator<<(ostream& os, Disenador& designer) {
    os << static_cast<const Trabajador&>(designer);
    os << "Herramienta design: " << designer.getHerramientaDiseno() << endl;
    os << "Tipo de design: " << designer.getTipoDiseno() << endl;

    return os;
}

void Disenador::imprimir()  {
    Trabajador::imprimir();
    cout << "Herramienta design: " << herramientaDiseno << endl;
    cout << "Tipo de design: " << tipoDiseno << endl;

}

//Metodos get y set

string Disenador::getHerramientaDiseno() const {
    return herramientaDiseno;
}

string Disenador::getTipoDiseno() const{
    return tipoDiseno;
}

void Disenador::setHerramientaDiseno(string herramientaDiseno) {
    this->herramientaDiseno = herramientaDiseno;
}

void Disenador::setTipoDiseno(string tipoDiseno) {
    this->tipoDiseno = tipoDiseno;
}


