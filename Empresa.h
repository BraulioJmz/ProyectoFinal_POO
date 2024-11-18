#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <vector>

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

    //Métodos para manipular proyectos
    void anadirProyecto();
    void eliminarProyecto();
    void mostrarProyectos();
    Proyecto* buscarProyecto();
};

#endif //EMPRESA_H
