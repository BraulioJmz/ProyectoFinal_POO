#include <iostream>
#include <cstdlib>

#include "Empresa.h"
#include "Proyecto.h"
#include "Trabajador.h"
#include "Disenador.h"
#include "Programador.h"

//Declaracion de funciones
void menuPrincipal();
void menuProyectos();
void menuTrabajadores();
void despedida();

using namespace std;

int main() {
    int opc,opc_2;
    Empresa empresa("BRUAL");

    do {
        opc = 0;
        opc_2 = 0;
        menuPrincipal();
        cin >> opc;

        switch (opc) {
            case 1:
                do {
                    menuProyectos();
                    cin >> opc_2;

                    switch (opc_2) {
                        case 1:
                            empresa.anadirProyecto();
                        break;
                        case 2:
                            empresa.buscarProyecto();
                        break;
                        case 3:
                            empresa.eliminarProyecto();
                        break;;
                        case 4:
                            empresa.mostrarProyectos();
                        break;
                        case 5:
                            break;
                        default:
                            cout << endl << "Opcion invalida!" << endl;
                        break;
                    }
                } while (opc != 5);
                break;
            case 2:
                menuTrabajadores();

                break;
            case 3:
                despedida();
                break;
            default:
                cout << endl << "Opcion invalida!" << endl;
                break;
        }
    } while(opc!=3);
}

//Implementacion de funciones

//Función para el menu principal
void menuPrincipal() {
    cout << endl << "Sistema de gestion empresa Tech" << endl;
    cout << "---------Menu Principal---------" << endl;
    cout << "1. Proyectos" << endl;
    cout << "2. Trabajadores" << endl;
    cout << "3. Salir del programa" << endl;
    cout << "Dame una opcion: ";
}

//Función para el menu de proyectos
void menuProyectos() {
    cout << endl << "Menu | Proyectos" << endl;
    cout << "------------------" << endl;
    cout << "1. Dar de alta un proyecto" << endl;
    cout << "2. Buscar un proyecto" << endl;
    cout << "3. Dar de baja un proyecto" << endl;
    cout << "4. Mostrar todos los proyectos" << endl;
    cout << "5. Salir al menu principal" << endl;
    cout << "Dame una opcion: " ;
}

//Función para el menu de trabajadores
void menuTrabajadores() {
    cout << endl << "Menu | Trabajadores" << endl;
    cout << "------------------" << endl;
    cout << "1. Dar de alta un trabajador" << endl;
    cout << "2. Buscar un trabajador" << endl;
    cout << "3. Dar de baja un trabajador" << endl;
    cout << "4. Salir al menu principal" << endl;
    cout << "Dame una opcion: " ;
}

//Función para la despedida
void despedida() {
    cout << endl << "Gracias por usar el programa" << endl;
    cout << "Version 1.0" << endl;
    cout << "Alberto Adrian Vera Ruiz" << endl;
    cout << "Braulio Jimenez Chavez" << endl;
}