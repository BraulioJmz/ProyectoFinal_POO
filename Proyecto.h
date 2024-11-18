#ifndef PROYECTO_H
#define PROYECTO_H
#include "Trabajador.h"
#include <iostream>
#include <string>

using namespace std;

class Proyecto {
    //Atributos de la clase
    private:
    string nombreProyecto;
    int idProyecto;
    vector <Trabajador*> trabajadores;

    public:
    //Constructor
    Proyecto(string, int);

    //Gets y Setters
    string getNombreProyecto();
    int getIdProyecto();
    void setNombreProyecto(string);
    void setIdProyecto(int);

    //Métodos para manipular proyectos
    void anadirTrabajador(Trabajador*);
    void eliminarTrabajador(int);
    Trabajador* buscarTrabajador(int);
};

#endif //PROYECTO_H
