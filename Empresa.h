#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "Proyecto.h"
using namespace std;

class Empresa {
    //Atributos de la clase
    private:
    string nombreEmpresa;
    vector <Proyecto*> proyectos;

    public:
    //Constructor
    Empresa(string);

    //Gets y Setters
    string getNombreEmpresa();
    void setNombreEmpresa(string);
    const vector <Proyecto*>& getProyectos();

    //Métodos para manipular proyectos
    void anadirProyecto();
    void eliminarProyecto();
    void mostrarProyectos();
    int buscarProyecto(int);
};

#endif //EMPRESA_H
