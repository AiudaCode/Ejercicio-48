#ifndef LOGICA_H
#define LOGICA_H
#include "Empleado.h"
#include <iostream>

using namespace std;

class Logica
{
    public:
        Logica();
        virtual ~Logica();
        // métodos publicos de la clase Logica
        void setTamano(int val);
        int getTamano();
        void setVector(int pos, Empleado *val);
        Empleado *getVector(int pos);
        void crearVector();
        int buscar(string nom);
    protected:

    private:
        // atributos privados de la clase Logica
        int tamano;
        Empleado *vector;
};

#endif // LOGICA_H
