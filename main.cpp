#include <iostream>

#include "Empresa.h"
#include "Proyecto.h"
#include "Trabajador.h"
#include "Disenador.h"
#include "Programador.h"

//Declaracion de funciones
void menuPrincipal();
void menuProyectos();

void menuBuscarProyecto();

void menuTrabajadores();
void menuElegirProyectos();
void menuAddTrabajador();
void menuBuscarTrabajador();
void menuEliminarTrabajador();
void menuSalarios();
void add_remove();
void menuCompararSalario();
void selectorSalario();
void despedida();

void addTrabajadorProyecto(const vector<Proyecto*>& proyectos);
int encontrarProyecto(const vector<Proyecto*>& proyectos, int ID);
void trabajadorAgregado(Proyecto* proyecto, int tipoTrabajador);
void buscarTrabajador(const vector<Proyecto*>& proyectos, int encontrado);
void eliminarTrabajador(const vector<Proyecto*>& proyectos, int encontrado);
void modificarSalario(const vector<Proyecto*>& proyectos);
void compararSalario(const vector<Proyecto*>& proyectos);

using namespace std;

int main() {
    int opc, opc_2,ID,encontrado;
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
                        case 2: {
                            menuBuscarProyecto();
                            cin >> ID; cin.ignore();
                            encontrado = empresa.buscarProyecto(ID);

                            const vector<Proyecto*>& proyectos = empresa.getProyectos();
                            if (encontrado != -1) {
                                cout << "Proyecto encontrado: " << proyectos[encontrado]->getNombreProyecto() << endl;
                            }
                            else {
                                cout << "Proyecto no encontrado." << endl;
                            }
                        }
                        break;
                        case 3:
                            empresa.eliminarProyecto();
                        break;
                        case 4:
                            empresa.mostrarProyectos();
                        break;
                        case 5: {
                            const vector<Proyecto*>& proyectos = empresa.getProyectos();
                            modificarSalario(proyectos);
                            break;
                        }
                        case 6: {
                            const vector<Proyecto*>& proyectos = empresa.getProyectos();
                            compararSalario(proyectos);
                            break;
                        }
                        case 7:
                            break;
                        default:
                            cout << endl << "Opcion invalida!" << endl;
                        break;
                    }
                } while (opc_2 != 7);
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
                        const vector<Proyecto*>& proyectos = empresa.getProyectos();
                        menuEliminarTrabajador();
                        cin >> ID; cin.ignore();

                        encontrado = empresa.buscarProyecto(ID);
                        buscarTrabajador(proyectos, encontrado);
                        break;
                    }

                    case 3: {
                        //Eliminar trabajadores
                        const vector<Proyecto*>& proyectos = empresa.getProyectos();
                        menuEliminarTrabajador();
                        cin >> ID; cin.ignore();
                        int proyecto = ID;

                        encontrado = empresa.buscarProyecto(ID);
                        eliminarTrabajador(proyectos, encontrado);
                        break;
                    }
                    case 4:
                        break;
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
    cout << "5. Aumentar o disminuir salario a proyecto" << endl;
    cout << "6. Comparar sueldos del proyecto" << endl;
    cout << "7. Salir al menu principal" << endl;
    cout << "Dame una opcion: " ;
}

void menuBuscarProyecto() {
    cout << endl << "Buscar un proyecto" << endl;
    cout << "Ingrese el ID del proyecto: ";
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

void menuBuscarTrabajador() {
    cout << "\nBuscar trabajador..." << endl;
    cout << "En que proyecto esta el trabajador?" << endl;
    cout << "Ingrese el ID del proyecto: ";
}

void menuAddTrabajador() {
    cout << "\nDar de alta trabajador..." << endl;
    cout << "1. Designer" << endl;
    cout << "2. Programador" << endl;
    cout << "Dame una opcion: " ;
}

void menuEliminarTrabajador() {
    cout << "\nEliminar trabajador..." << endl;
    cout << "En que proyecto esta el trabajador?" << endl;
    cout << "Ingrese el ID del proyecto: ";
}

void menuSalarios() {
    cout << "\nA que proyecto modificar salarios?" << endl;
    cout << "Ingrese el ID del proyecto: ";
}

void add_remove() {
    cout << "\nModificar salarios..." << endl;
    cout << "1. Aumentar" << endl;
    cout << "2. Disminuir" << endl;
    cout << "Dame una opcion: " ;
}

void menuCompararSalario() {
    cout << "\nDe que proyecto quieres encontrar el mayor o menor salario?" << endl;
    cout << "Ingrese el ID del proyecto: ";
}

void selectorSalario() {
    cout << "\nComparar salarios..." << endl;
    cout << "1. Mejor pagado" << endl;
    cout << "2. Peor pagado" << endl;
    cout << "Dame una opcion: ";
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

void buscarTrabajador(const vector<Proyecto*>& proyectos, int encontrado) {
    int ID;

    if (encontrado != -1) {
        const vector<Trabajador*>& trabajadores = proyectos[encontrado]->getTrabajadores();
        cout << "Ingrese el ID del trabajador: ";
        cin >> ID; cin.ignore();

        encontrado = proyectos[encontrado]->buscarTrabajador(ID);
        if (encontrado != -1) {
            trabajadores[encontrado]->imprimir();
        }
        else {
            cout << "Trabajador no encontrado." << endl;
        }
    }
    else {
        cout << "Proyecto no encontrado." << endl;
    }
}

void eliminarTrabajador(const vector<Proyecto *> &proyectos, int encontrado) {
    int ID;

    if (encontrado != -1) {
        cout << "Ingrese el ID del trabajador: ";
        cin >> ID; cin.ignore();

        encontrado = proyectos[encontrado]->buscarTrabajador(ID);
        if (encontrado != -1) {
            proyectos[encontrado]->eliminarTrabajador(ID);
            cout << "Trabajador eliminado correctamente" << endl;
        }
        else {
            cout << "Trabajador no encontrado." << endl;
        }
    }
    else {
        cout << "Proyecto no encontrado." << endl;
    }
}

void modificarSalario(const vector<Proyecto*>& proyectos) {
    menuSalarios();
    int ID, opc;
    float masSalario;
    cin >> ID; cin.ignore();

    int indexProyecto = encontrarProyecto(proyectos,  ID);

    if(indexProyecto != -1) {
        Proyecto* proyecto = proyectos[indexProyecto];
        add_remove();
        cin >> opc; cin.ignore();

        if(opc == 1) {
            cout << "\nCuanto aumentar? ";
            cin >> masSalario; cin.ignore();

            for(int i=0; i<proyecto->getTrabajadores().size(); i++) {
                proyecto->getTrabajadores()[i]->setSalario(proyecto->getTrabajadores()[i]->getSalario() + masSalario);
            }
            cout << "Salarios aumentados!\n" << endl;
        }
        else if(opc == 2) {
            cout << "\nCuanto disminuir? "; ;
            cin >> masSalario; cin.ignore();

            for(int i=0; i<proyecto->getTrabajadores().size(); i++) {
                proyecto->getTrabajadores()[i]->setSalario(proyecto->getTrabajadores()[i]->getSalario() - masSalario);
            }
            cout << "Salarios disminuidos!\n" << endl;
        }
        else {
            cout << "Opcion invalida!" << endl;
        }
    }
    else {
        cout << "\nProyecto no encontrado" << endl;
    }
}

void compararSalario(const vector<Proyecto*>& proyectos) {
    menuCompararSalario();
    int masSalario;
    int ID, opc;
    cin >> ID; cin.ignore();

    int indexProyecto = encontrarProyecto(proyectos,  ID);

    if(indexProyecto != -1) {
        const vector<Trabajador*>& trabajadores = proyectos[indexProyecto]->getTrabajadores();

        selectorSalario();
        cin >> opc; cin.ignore();

        if(opc == 1) {
            cout << "\nEmpleado mejor pagado del proyecto" << endl;

            int mayor = 0;
            for(int i=0; i<trabajadores.size(); i++) {
                if(*trabajadores[i] > *trabajadores[mayor]) {
                    mayor = i;
                }
            }

            trabajadores[mayor]->imprimir();
        }
        else if(opc == 2) {
            cout << "\nEmpleado peor pagado del proyecto" << endl;

            int menor = 0;
            for(int i=0; i<trabajadores.size(); i++) {
                if(*trabajadores[i] < *trabajadores[menor]) {
                    menor = i;
                }
            }

            trabajadores[menor]->imprimir();
        }
        else {
            cout << "Opcion invalida!" << endl;
        }
    }
    else {
        cout << "\nProyecto no encontrado" << endl;
    }
}
