public class Empleado
{
    // se declaran los atributos privados de la clase Empleado
    private String nombre;
    private int codigo;
    
    public Empleado()
    {
        // se le asignan valores por defecto a los atributos de la clase
        nombre = "";
        codigo = 0;
    }
    
    // métodos Setters y Getters de los atributos de la clase
    public void setNombre(String val)
    {
        nombre = val;
    }
    
    public String getNombre()
    {
        return nombre;
    }
    
    public void setCodigo(int val)
    {
        codigo = val;
    }
    
    public int getCodigo()
    {
        return codigo;
    }
}