public class Logica
{
    // atributos privados de la clase Logica
    private int tamaño;
    private Empleado [] vector;
    
    public Logica()
    {
        // se le asignan valores por defecto a los atributos de la clase
        tamaño = 0;
        vector = null;
    }
    
    // métodos Setters y Getters de los atributos de la clase
    public void setTamaño(int val)
    {
        tamaño = val;
    }
    
    public int getTamaño()
    {
        return tamaño;
    }
    
    public void setVector(int pos, Empleado val)
    {
        vector[pos] = val;
    }
    
    public Empleado getVector(int pos)
    {
        return vector[pos];
    }
    
    // método para crear el vector
    public void crearVector()
    {
        // se le asigna al vector el nuevo tamaño
        vector = new Empleado[tamaño];
    }
    
    // método para buscar un nombre
    public int buscar(String nom)
    {
        // recorremos todo el vector con el ciclo for
        for (int i = 0; i < getTamaño(); i++)
        {
            // si el nombre de la posicion i es igual al valor de la variable nom pasada como parametro
            if (getVector(i).getNombre().equals(nom))
            {
                // entonces se retorna la posicion actual de i
                return i;
            }
        }
        // si no se encontro nada, se retorna -1
        return -1;
    }
}