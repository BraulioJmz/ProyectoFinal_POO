#ifndef PROYECTO_H
#define PROYECTO_H
#include <string>
using namespace std;

class Proyecto {
    //Atributos de la clase
    private:
    string nombreProyecto;
    int idProyecto;

    public:
    //Constructor
    Proyecto(string, int);

    //Gets y Setters
    string getNombreProyecto();
    int getIdProyecto();
    void setNombreProyecto(string);
    void setIdProyecto(int);
};

#endif //PROYECTO_H
