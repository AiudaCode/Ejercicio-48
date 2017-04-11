
import javax.swing.JOptionPane;

public class Main
{
    // método para llenar los datos en el vector
    public static void llenar(Empleado obj)
    {
        String nom = JOptionPane.showInputDialog("Ingrese su nombre:");
        obj.setNombre(nom);
        int cod = Integer.parseInt(JOptionPane.showInputDialog("Ingrese su codigo:"));
        obj.setCodigo(cod);
    }
    
    // método para mostrar los datos del vector
    public static void mostrar(Logica obj, int opc)
    {
        String datos = "";
        // dependiendo del valor de la variable opc pasada como parametro se seleccionara un caso
        switch(opc){
            case 1:
                for (int i = 0; i < obj.getTamaño(); i++)
                {
                    datos += "Nombre: " + obj.getVector(i).getNombre() + "\n" +
                             "Codigo: " + obj.getVector(i).getCodigo() + "\n\n";
                }
                JOptionPane.showMessageDialog(null, datos);
                break;
            case 2:
                for (int i = 0; i < obj.getTamaño(); i++)
                {
                    datos += "Nombre: " + obj.getVector(i).getNombre() + "\n\n";
                }
                JOptionPane.showMessageDialog(null, datos);
                break;
            case 3:
                for (int i = 0; i < obj.getTamaño(); i++)
                {
                    datos += "Codigo: " + obj.getVector(i).getCodigo()+ "\n\n";
                }
                JOptionPane.showMessageDialog(null, datos);
                break;
            default:
                if (obj.getVector(0) == null)
                {
                    JOptionPane.showMessageDialog(null, "No hay ningún empleado registrado.");
                }
                else
                {
                    int cod = Integer.parseInt(JOptionPane.showInputDialog("Ingrese codigo:"));
                    for (int i = 0; i < obj.getTamaño(); i++)
                    {
                        if (obj.getVector(i).getCodigo() > cod)
                        {
                            datos += "Nombre: " + obj.getVector(i).getNombre() + "\n" +
                                     "Codigo: " + obj.getVector(i).getCodigo() + "\n\n";
                        }
                    }
                    JOptionPane.showMessageDialog(null, datos);
                }
                break;
        }
    }
    
    // método para mostrar el menu
    public static int menu()
    {
        int opcion = 0;
        do
        {
            opcion = Integer.parseInt(JOptionPane.showInputDialog(
            "=========== SELECCIONE UNA OPCIÓN DEL MENÚ =========== \n" +
            "1. Registrar empleado.\n" +
            "2. Mostrar datos del vector.\n" +
            "3. Mostar nombres de los empleados.\n" +
            "4. Mostar códigos de los empleados.\n" +
            "5. Buscar empleado.\n" +
            "6. Mostrar información de los empleados, con códigos mayores a un codigo pedido por pantalla.\n" +
            "7. Salir\n\n" +
            " Seleccione una opción del 1 al 7:"));
        }
        while(opcion < 1 || opcion > 7);
        return opcion;
    }
    
    public static void main(String[] args)
    {
        // se crea un objeto de la clase Logica
        Logica obj = new Logica();
        // se declara una variable de tipo Empleado
        Empleado emp;
        // se crean 3 variables de tipo entero
        int opcion, tam, cod;
        // se crea una variable de tipo string
        String nombre;
        // se pide el tamaño del vector y se guarda en la variable tam
        tam = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite tamaño del Vector:"));
        // se encapsula el valor de la variable tam
        obj.setTamaño(tam);
        // se crea el vector con el tamaño ya dado
        obj.crearVector();
        do
        {
            // se le asigna a la variable opcion el valor que retorne el metodo menu
            opcion = menu();
            // dependiendo del valor de la variable opcion seleccionara un caso
            switch(opcion) 
            {
                case 1:
                    for (int i = 0; i < obj.getTamaño(); i++)
                    {
                        emp = new Empleado();
                        JOptionPane.showMessageDialog(null, "Llene la información del empleado " + i);
                        llenar(emp);
                        obj.setVector(i, emp);
                    }
                    break;
                case 2:
                    if (obj.getVector(0) == null)
                    {
                        JOptionPane.showMessageDialog(null, "No se creado el vector.");
                    }
                    else
                    {
                        mostrar(obj, 1);
                    }
                    break;
                case 3:
                    if (obj.getVector(0) == null)
                    {
                        JOptionPane.showMessageDialog(null, "No se creado el vector.");
                    }
                    else
                    {
                        mostrar(obj, 2);
                    }
                    break;
                case 4:
                    if (obj.getVector(0) == null)
                    {
                        JOptionPane.showMessageDialog(null, "No se creado el vector.");
                    }
                    else
                    {
                        mostrar(obj, 3);
                    }
                    break;
                case 5:
                    if (obj.getVector(0) == null)
                    {
                        JOptionPane.showMessageDialog(null, "No se creado el vector.");
                    }
                    else
                    {
                        nombre = JOptionPane.showInputDialog("Digite nombre del empleado que quiere buscar");
                        int pos = obj.buscar(nombre);
                        if (pos != -1)
                        {
                            JOptionPane.showMessageDialog(null,
                                "Nombre: " + obj.getVector(pos).getNombre() + "\n" +
                                "Código: " + obj.getVector(pos).getCodigo());
                        }
                        else
                        {
                            JOptionPane.showMessageDialog(null, "El dato no se encuentra.");
                        }
                    }
                    break;
                case 6:
                    if (obj.getVector(0) == null)
                    {
                        JOptionPane.showMessageDialog(null, "No se creado el vector.");
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
}