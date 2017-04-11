#include <iostream>
#include "Empleado.h"
#include "Logica.h"
#include "stdlib.h"

using namespace std;

// método para llenar los datos en el vector
void llenar(Empleado *obj)
{
    string nom;
    cout << "Ingrese su nombre" << endl;
    cout << ">> ";
    cin >> nom;
    obj->setNombre(nom);
    int cod;
    cout << "Ingrese su codigo" << endl;
    cout << ">> ";
    cin >> cod;
    obj->setCodigo(cod);
}

// método para mostrar los datos del vector
void mostrar(Logica *obj, int opc)
{
    // dependiendo del valor de la variable opc pasada como parametro se seleccionara un caso
    switch(opc){
        case 1:
            for (int i = 0; i < obj->getTamano(); i++)
            {
                cout << "Nombre: " << obj->getVector(i)->getNombre() << endl;
                cout << "Codigo: " << obj->getVector(i)->getCodigo() << endl << endl;
            }
            break;
        case 2:
            for (int i = 0; i < obj->getTamano(); i++)
            {
                cout << "Nombre: " << obj->getVector(i)->getNombre() << endl << endl;
            }
            break;
        case 3:
            for (int i = 0; i < obj->getTamano(); i++)
            {
                cout << "Codigo: " << obj->getVector(i)->getCodigo() << endl << endl;
            }
            break;
        default:
            if (obj->getVector(0) == NULL)
            {
                cout << "No hay ningún empleado registrado." << endl;
            }
            else
            {
                int cod;
                cout << "Ingrese codigo" << endl;
                cout << ">> ";
                cin >> cod;
                for (int i = 0; i < obj->getTamano(); i++)
                {
                    if (obj->getVector(i)->getCodigo() > cod)
                    {
                        cout << "Nombre: " << obj->getVector(i)->getNombre() << endl;
                        cout << "Codigo: " << obj->getVector(i)->getCodigo() << endl << endl;
                    }
                }
            }
            break;
    }
}

// método para mostrar el menu
int menu()
{
    int opcion = 0;
    do
    {
        cout << "=========== SELECCIONE UNA OPCION DEL MENU ===========" << endl;
        cout << "1. Registrar empleado." << endl;
        cout << "2. Mostrar datos del vector." << endl;
        cout << "3. Mostar nombres de los empleados." << endl;
        cout << "4. Mostar códigos de los empleados." << endl;
        cout << "5. Buscar empleado." << endl;
        cout << "6. Mostrar informacion de los empleados, con códigos mayores a un codigo pedido por pantalla." << endl;
        cout << "7. Salir" << endl;
        cout << ">> ";
        cin >> opcion;
        system("cls");
    }
    while(opcion < 1 || opcion > 7);
    return opcion;
}

int main(void)
{
    // se crea un objeto de la clase Logica
    Logica *obj = new Logica();
    // se declara una variable de tipo Empleado
    Empleado *emp;
    // se crean 3 variables de tipo entero
    int opcion, tam, cod;
    // se crea una variable de tipo string
    string nombre;
    // se pide el tamaño del vector y se guarda en la variable tam
    cout << "Digite tamano del Vector" << endl;
    cout << ">> ";
    cin >> tam;
    // se encapsula el valor de la variable tam
    obj->setTamano(tam);
    // se crea el vector con el tamaño ya dado
    obj->crearVector();
    do
    {
        // se le asigna a la variable opcion el valor que retorne el metodo menu
        opcion = menu();
        // dependiendo del valor de la variable opcion seleccionara un caso
        switch(opcion)
        {
            case 1:
                for (int i = 0; i < obj->getTamano(); i++)
                {
                    emp = new Empleado();
                    cout << "Llene la informacion del empleado " << i << endl;
                    llenar(emp);
                    obj->setVector(i, emp);
                }
                break;
            case 2:
                if (obj->getVector(0) == NULL)
                {
                    cout << "No se creado el vector." << endl;
                }
                else
                {
                    mostrar(obj, 1);
                }
                break;
            case 3:
                if (obj->getVector(0) == NULL)
                {
                    cout << "No se creado el vector." << endl;
                }
                else
                {
                    mostrar(obj, 2);
                }
                break;
            case 4:
                if (obj->getVector(0) == NULL)
                {
                    cout << "No se creado el vector." << endl;
                }
                else
                {
                    mostrar(obj, 3);
                }
                break;
            case 5:
                if (obj->getVector(0) == NULL)
                {
                    cout << "No se creado el vector." << endl;
                }
                else
                {
                    cout << "Digite nombre del empleado que quiere buscar" << endl;
                    cout << ">> ";
                    cin >> nombre;
                    int pos = obj->buscar(nombre);
                    if (pos != -1)
                    {
                        cout << "Nombre: " << obj->getVector(pos)->getNombre() << endl;
                        cout << "Codigo: " << obj->getVector(pos)->getCodigo() << endl;
                    }
                    else
                    {
                        cout << "El dato no se encuentra." << endl;
                    }
                }
                break;
            case 6:
                if (obj->getVector(0) == NULL)
                {
                    cout << "No se creado el vector." << endl;
                }
                else
                {
                    mostrar(obj, 4);
                }
                break;
            default:
                break;
        }
    }
    while (opcion != 7);
}
