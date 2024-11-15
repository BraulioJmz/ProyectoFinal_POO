#include <iostream>
#include "Empresa.h"
#include "Proyecto.h"
#include "Disenador.h"
#include "Programador.h"

using namespace std;

int main() {
    Empresa empresa1("BRUAL");

    Proyecto* proyecto1 = new Proyecto("Tiras LED", 1);
    Proyecto* proyecto2 = new Proyecto("Gorras", 2);

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

    return 0;
}
