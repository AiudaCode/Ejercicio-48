#include "Logica.h"

Logica::Logica()
{
    // se le asignan valores por defecto a los atributos de la clase
    tamano = 0;
    vector = NULL;
}

Logica::~Logica()
{
    //dtor
}

// métodos Setters y Getters de la clase Logica
void Logica::setTamano(int val)
{
    tamano = val;
}

int Logica::getTamano()
{
    return tamano;
}

// debo aclarar que el set del vector es algo complicado de entender, se debe tener un puntero hacia la variable val
// para poder modificarlo
void Logica::setVector(int pos, Empleado *val)
{
    vector[pos] = *val;
}

// el simbolo & solo significa que tomaremos el valor que hay en la posicion pos del vector, recuerden que si no se escribe esto
// dara error porque entonces, estariamos retornando la direccion de la memoria asignada para ese vector...
Empleado *Logica::getVector(int pos)
{
    return &vector[pos];
}

// método para crear el vector
void Logica::crearVector()
{
    // se le asigna al vector el nuevo tamaño
    vector = new Empleado[tamano];
}

int Logica::buscar(string nom)
{
    // recorremos todo el vector con el ciclo for
    for (int i = 0; i < getTamano(); i++)
    {
        // si el nombre de la posicion i es igual al valor de la variable nom pasada como parametro
        if (getVector(i)->getNombre().compare(nom) == 0)
        {
            // entonces se retorna la posicion actual de i
            return i;
        }
    }
    // si no se encontro nada, se retorna -1
    return -1;
}
