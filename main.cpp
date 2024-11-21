#include <iostream>

#include "Empresa.h"
#include "Proyecto.h"
#include "Trabajador.h"
#include "Disenador.h"
#include "Programador.h"

//Declaracion de funciones
void menuPrincipal();
void menuProyectos();

void menuTrabajadores();
void menuElegirProyectos();
void menuAddTrabajador();
void menuBuscarTrabajador();
void despedida();

void addTrabajadorProyecto(const vector<Proyecto*>& proyectos);
int encontrarProyecto(const vector<Proyecto*>& proyectos, int ID);
void trabajadorAgregado(Proyecto* proyecto, int tipoTrabajador);

using namespace std;

int main() {
    int opc, opc_2, opc_3;
    int ID;
    int flag = 0;
    Empresa empresa("ORACLE");

    do {
        opc = 0;
        opc_2 = 0;

        menuPrincipal();
        cin >> opc;

        switch (opc) {
            case 1: //Seleccionar acciones con PROYECTOS
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
                        break;
                        case 4:
                            empresa.mostrarProyectos();
                        break;
                        case 5:
                            break;
                        default:
                            cout << endl << "Opcion invalida!" << endl;
                        break;
                    }
                } while (opc_2 != 5);
            break;

            case 2: {  //Seleccionar acciones con TRABAJADORES
                menuTrabajadores();
                cin >> opc_2;

                switch (opc_2) {
                    case 1: {
                        //Añadir trabajadores a un proyecto
                        const vector<Proyecto*>& proyectos = empresa.getProyectos();
                        addTrabajadorProyecto(proyectos);  //Implementación con funciones
                        break;
                    }

                    case 2: {
                        //Buscar trabajadores
                        int ID;
                        menuBuscarTrabajador();
                        cin >> ID; cin.ignore();


                        break;
                    }
                    default:
                        cout << endl << "Opcion invalida!" << endl;
                        break;
                }
                break;
            }

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

void menuElegirProyectos() {
    cout << "\nA que proyecto agregar el trabajador?" << endl;
    cout << "Ingrese el ID del proyecto: ";
}

void menuAddTrabajador() {
    cout << "\nDar de alta trabajador..." << endl;
    cout << "1. Designer" << endl;
    cout << "2. Programador" << endl;
    cout << "Dame una opcion: " ;
}

void menuBuscarTrabajador() {
    cout << "\nBuscar trabajador...?" << endl;
    cout << "Ingrese el ID del trabajador: ";
}

//Función para la despedida
void despedida() {
    cout << endl << "Gracias por usar el programa" << endl;
    cout << "Version 1.0" << endl;
    cout << "Alberto Adrian Vera Ruiz" << endl;
    cout << "Braulio Jimenez Chavez" << endl;
}

void addTrabajadorProyecto(const vector<Proyecto*>& proyectos) {
    int ID;
    menuElegirProyectos();
    cin >> ID; cin.ignore();

    int indexProyecto = encontrarProyecto(proyectos,  ID);

    if(indexProyecto != -1) {
        Proyecto* proyecto = proyectos[indexProyecto];

        int tipoTrabajador;
        menuAddTrabajador();
        cin >> tipoTrabajador;

        //Agregar trabajador al proyecto ingresado
        trabajadorAgregado(proyecto, tipoTrabajador);
    }
    else {
        cout << "\nProyecto no encontrado" << endl;
    }
}

//Buscar proyecto por ID y devuelve su indice
int encontrarProyecto(const vector<Proyecto*>& proyectos, int ID) {
    for(int i = 0; i < proyectos.size(); i++ ) {
        if(ID == proyectos[i]->getIdProyecto()) {
            return i;
        }
    }
    return -1;
}

//Instancia un trabajador segun el tipo ingresado y lo agrega al proyecto
void trabajadorAgregado(Proyecto* proyecto, int tipoTrabajador) {
    switch (tipoTrabajador) {
        case 1: { //Ingresar diseñadores
            cout << "\nIngresando designer..." << endl;
            Disenador* designer = new Disenador(); //Crear diseñador
            cin >> *designer; //Utilizar sobrecarga para agregar

            //Agregar trabajador al proyecto encontrado
            proyecto-> anadirTrabajador(designer);
            cout << "\nTrabajador agregado correctamente" << endl;
            break;
        }

        case 2: {
            //Ingresar programadores
            cout << "\nIngresando programador..." << endl;
            Programador* developer = new Programador(); //Crear programador
            cin >> *developer; //Utilizar sobrecarga para agregar

            //Agregar trabajador al proyecto encontrado
            proyecto-> anadirTrabajador(developer);
            cout << "\nTrabajador agregado correctamente" << endl;
            break;
        }

        default:
            cout << "Opcion invalida!" << endl;
        break;
    }
}
