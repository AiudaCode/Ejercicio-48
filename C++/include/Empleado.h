#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>

using namespace std;

class Empleado
{
    public:
        Empleado();
        virtual ~Empleado();
        // se declaran los métodos publicos de la clase Empleado
        void setNombre(string val);
        string getNombre();
        void setCodigo(int val);
        int getCodigo();
    protected:

    private:
        // se declaran los atributos privados de la clase Empleado
        string nombre;
        int codigo;
};

#endif // EMPLEADO_H
