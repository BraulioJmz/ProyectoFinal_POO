#include <iostream>
#include "Empresa.h"
#include "Proyecto.h"
#include "Trabajador.h"
#include "Disenador.h"
#include "Programador.h"

//Declaracion de funciones
void menuPrincipal();

using namespace std;

int main() {
    Empresa empresa1("BRUAL");

    Proyecto* proyecto1 = new Proyecto("Tiras LED", 1);
    Proyecto* proyecto2 = new Proyecto("Gorras", 2);

    Disenador dis1("Jose",1500.00,1234,"Photoshop","Logos");
    Programador prog1("Braulio", 20000.00, 1111, "C++", "Algoritmos");

    empresa1.anadirProyecto(proyecto1);
    empresa1.anadirProyecto(proyecto2);

    empresa1.mostrarProyectos();

    Proyecto* encontrado = empresa1.buscarProyecto(1);
    if (encontrado) {
        cout << "Proyecto encontrado: " << encontrado->getNombreProyecto() << endl;
    } else {
        cout << "Proyecto no encontrado." << endl;
    }

    empresa1.eliminarProyecto(1002);
    empresa1.mostrarProyectos();

    cout << "Hola mundo " << endl;

    dis1.trabajar();
    prog1.trabajar();

    return 0;
}

//Implementacion de funciones

void menuPrincipal() {
    cout << "Oracle" << endl;
    cout << "Sistema de gestion de proyectos y trabajadores" << endl;
}
