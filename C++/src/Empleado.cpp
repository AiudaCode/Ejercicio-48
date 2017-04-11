#include "Empleado.h"

Empleado::Empleado()
{
    // se le asignan valores por defecto a los atributos de la clase
    nombre = "";
    codigo = 0;
}

Empleado::~Empleado()
{
    //dtor
}

// métodos Setters y Getters de los atributos de la clase
void Empleado::setNombre(string val)
{
    nombre = val;
}

string Empleado::getNombre()
{
    return nombre;
}

void Empleado::setCodigo(int val)
{
    codigo = val;
}

int Empleado::getCodigo()
{
    return codigo;
}
