#ifndef PROYECTO_H
#define PROYECTO_H
#include "Trabajador.h"
#include <iostream>
#include <string>
#include <vector>

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

    //Sobrecarga de metodo
    Proyecto& operator+(float incrementoSalario);
    Proyecto& operator-(float disminuirSalario);

    //Gets y Setters
    string getNombreProyecto();
    int getIdProyecto();
    const vector<Trabajador*>& getTrabajadores();
    void setNombreProyecto(string);
    void setIdProyecto(int);

    //Métodos para manipular trabajadores
    void anadirTrabajador(Trabajador*);
    void eliminarTrabajador(int);
    int buscarTrabajador(int);
};

#endif //PROYECTO_H
