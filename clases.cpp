#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include<random>
#include<ctime>
#include "clases.h"

using namespace std;

//--------------------Métodos de la clase Surtidor--------------------------------------
// Definición del constructor.
surtidor::surtidor(string _c_estacion, string _modelo, string _codigo, bool _estado) {
    codigo = _codigo;
    modelo = _modelo;
    estado = _estado;
    c_estacion=_c_estacion;
}
//Destructor.
surtidor::~surtidor(){

}
// Definición del método encargado de registrar la venta.
void surtidor::venta(string codigo_estacion, string cedula, string fecha, string hora, char manera_pago, unsigned short tipo_comb, float c_disponible, float c_pedida, const unsigned long *precio_galon) {
    if (estado == false) {
        cout << "El surtidor no está activo" << endl;
        return;
    }

    fstream ventas("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\ventas.txt", std::ios::out | std::ios::app);
    float c_dinero = 0,c_entregada_c;
    string tipo_pago;
    if (!ventas.is_open()) {
        cerr << "Error en la apertura del archivo." << endl;
    } else {
        switch (tipo_comb) {
        case 1:
            c_dinero = precio_galon[0];
            break;
        case 2:
            c_dinero = precio_galon[1];
            break;
        case 3:
            c_dinero = precio_galon[2];
            break;
        }

        if (c_pedida > c_disponible) {
            c_dinero *= c_disponible;
            c_entregada_c=c_disponible;
        } else {
            c_dinero *= c_pedida;
            c_entregada_c=c_pedida;
        }

        // Escribir los datos al final del archivo en una nueva línea
        ventas << codigo_estacion << "@" << codigo << "@" << cedula << "@" << fecha << "@" << hora << "@" << tipo_comb << "@" << c_dinero << "@" << manera_pago <<"@"<<c_entregada_c<< "\n";
        if(manera_pago=='e'){
            tipo_pago="Efectivo";
        }
        else if(manera_pago=='d'){
            tipo_pago="Debito";
        }
        else {
            tipo_pago="Credito";
        }
        // Imprimir los datos de la venta
        cout << "Venta realizada: \n";
        cout << "Estacion: " << codigo_estacion << "\n"
             << "Surtidor: " << codigo << "\n"
             << "Cedula: " << cedula << "\n"
             << "Fecha: " << fecha << "\n"
             << "Hora: " << hora << "\n"
             << "Tipo de combustible: " << tipo_comb << "\n"
             << "cantidad pedida.     " << c_pedida  <<"\n"
             << "Cantidad entregada:  "<<c_entregada_c<<" litros "<<"\n"
             << "Monto de la venta: $" << c_dinero << "\n"
             << "Forma de pago: " << tipo_pago << endl;
    }

    ventas.close();
}

//Definición del método encargado de ver las ventas.
void surtidor::consultar_venta() {
    if(estado==false){
        cout<<"El surtidor no esta activo";
        return;
    }
    fstream ventas("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\ventas.txt", std::ios::in);
    string linea;
    while (getline(ventas, linea)) {
        string codigo_estacion, codigo_surtidor, cedula, fecha_venta, hora_venta, tipo_combustible, cantidad_pago, tipo_pago;

        // Delimitador
        char delimitador = '@';

        // Separar los datos según el nuevo formato
        size_t pos = 0;

        // Extraer el código de la estación
        pos = linea.find(delimitador);
        codigo_estacion = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Extraer el código del surtidor
        pos = linea.find(delimitador);
        codigo_surtidor = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Extraer la cédula
        pos = linea.find(delimitador);
        cedula = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Extraer la fecha de la venta
        pos = linea.find(delimitador);
        fecha_venta = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Extraer la hora de la venta
        pos = linea.find(delimitador);
        hora_venta = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Extraer el tipo de combustible
        pos = linea.find(delimitador);
        tipo_combustible = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Extraer la cantidad del pago
        pos = linea.find(delimitador);
        cantidad_pago = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Extraer el tipo de pago
        tipo_pago = linea;  // El tipo de pago es el último elemento

        // Verificar si el código del surtidor coincide
        if (codigo_surtidor == codigo) {  // Asegúrate de que `codigo` es el código del surtidor actual
            // Imprimir solo si el código coincide
            if(tipo_combustible=="1"){
                tipo_combustible="Regular";
            }
            else if(tipo_combustible=="2"){
                tipo_combustible="Premium";
            }
            else{
                tipo_combustible="Ecoextra";
            }

            if(tipo_pago=="e"){
                tipo_pago="Efectivo";
            }
            else if(tipo_pago=="c"){
                tipo_pago="credito";
            }
            else{
                tipo_pago="Debito";
            }
            cout << "Código de la estación: " << codigo_estacion << "\n";
            cout << "Código del surtidor: " << codigo_surtidor << "\n";
            cout << "Cédula: " << cedula << "\n";
            cout << "Fecha: " << fecha_venta << "\n";
            cout << "Hora: " << hora_venta << "\n";
            cout << "Tipo de combustible: " << tipo_combustible << "\n";
            cout << "Cantidad de la venta: " << cantidad_pago << "\n";
            cout << "Tipo de pago: " << tipo_pago << "\n";
            cout << "------------------------\n";
        }
    }
    ventas.close();
}








string surtidor::mostar_codigo(){
    if(estado==false){
        return "no esta activa la estacion";
    }
    return codigo;
}
// Definición del método encargado de activar o desactivar el surtidor.
void surtidor::activar(bool activa) {
    estado = activa;
}


//----------------------Métodos de la clase Tanque-----------------------------------------------------------
//Definición del constructor.
Tanque::Tanque(unsigned short _capacidad_regular, unsigned short _capacidad_premium, unsigned short _capacidad_ecoextra_, string _codigo) {
    capacidad_regular = _capacidad_regular;
    capacidad_premium = _capacidad_premium;
    capacidad_ecoextra = _capacidad_ecoextra_;
    codigo = _codigo;

    // Abrir el archivo para lectura y escritura
    fstream archivo("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\cantidad_combustible.txt", ios::in | ios::out | ios::app);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    // Verificar si el código ya está registrado
    string linea;
    bool codigo_existe = false;

    while (getline(archivo, linea)) {
        unsigned short pos = linea.find('@');
        if (pos != string::npos) {
            string codigo_existente = linea.substr(0, pos);  // Extraer el código de la línea
            if (codigo_existente == _codigo) {
                codigo_existe = true;
                break;  // Salir del bucle si el código ya está registrado
            }
        }
    }

    // Si el código no existe, registrar el tanque
    if (!codigo_existe) {
        archivo.clear();  // Limpiar el estado del archivo para poder escribir
        archivo.seekp(0, ios::end);  // Mover el cursor al final del archivo para escribir
        archivo << _codigo << "@" << _capacidad_regular << "@" << _capacidad_premium << "@" << _capacidad_ecoextra_ << "\n";
    }
    // Cerrar el archivo
    archivo.close();
}
//Definición del destructor.
Tanque::~Tanque(){
}

//método encargado de entrgar el combustible del tanque central.
float Tanque::entregar_combustible(string c_estacion, unsigned short tipo_comb, float c_entregada) {
    ifstream archivoEntrada("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\cantidad_combustible.txt");
    if (!archivoEntrada.is_open()) {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
        return 0;
    }

    string linea;
    string contenidoActualizado;
    bool encontrado = false;
    float cantidad_entregada;

    // Procesar cada línea del archivo
    while (getline(archivoEntrada, linea)) {
        string codigo, capacidad1, capacidad2, capacidad3;

        // Separar la línea en codigo y las capacidades de los tres combustibles
        unsigned short pos1 = linea.find('@');
        unsigned short pos2 = linea.find('@', pos1 + 1);
        unsigned short pos3 = linea.find('@', pos2 + 1);

        if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
            codigo = linea.substr(0, pos1);
            capacidad1 = linea.substr(pos1 + 1, pos2 - pos1 - 1);
            capacidad2 = linea.substr(pos2 + 1, pos3 - pos2 - 1);
            capacidad3 = linea.substr(pos3 + 1);

            // Si se encuentra la estación, actualizar la capacidad
            if (codigo == c_estacion) {
                float nueva_capacidad;
                switch (tipo_comb) {
                case 1:
                    nueva_capacidad = stof(capacidad1) - c_entregada;
                    if(nueva_capacidad<0){
                        nueva_capacidad=0;
                        cantidad_entregada=stof(capacidad1);
                    }
                    capacidad1 = to_string(nueva_capacidad);
                    break;
                case 2:
                    nueva_capacidad = stof(capacidad2) - c_entregada;
                    if(nueva_capacidad<0){
                        nueva_capacidad=0;
                        cantidad_entregada=stof(capacidad2);
                    }
                    capacidad2 = to_string(nueva_capacidad);
                    break;
                case 3:
                    nueva_capacidad = stof(capacidad3) - c_entregada;
                    if(nueva_capacidad<0){
                        nueva_capacidad=0;
                        cantidad_entregada=stof(capacidad3);
                    }
                    capacidad3 = to_string(nueva_capacidad);
                    break;
                default:
                    cerr << "Tipo de combustible no válido." << endl;
                    return 0;
                }
                encontrado = true;
            }

            // Volver a formar la línea actualizada
            contenidoActualizado += codigo + "@" + capacidad1 + "@" + capacidad2 + "@" + capacidad3 + "\n";
        }
    }

    archivoEntrada.close();

    if (!encontrado) {
        cerr << "Estación no encontrada." << endl;
        return 0;
    }

    // Escribir el contenido actualizado en el archivo
    ofstream archivoSalida("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\cantidad_combustible.txt", ios::trunc);
    if (archivoSalida.is_open()) {
        archivoSalida << contenidoActualizado;
        archivoSalida.close();
    } else {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
    }
    return cantidad_entregada;
}


void Tanque::mostrar_combustible_gastado() {
    // Abrir el archivo
    ifstream archivo("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\cantidad_combustible.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        // Dividir la línea para extraer las cantidades
        int pos1 = linea.find('@');
        int pos2 = linea.find('@', pos1 + 1);
        int pos3 = linea.find('@', pos2 + 1);

        // Extraer cantidades como strings y convertirlas a números
        string codigo_estacion = linea.substr(0, pos1);
        float cantidad_regular = stoi(linea.substr(pos1 + 1, pos2 - pos1 - 1));
        float cantidad_premium = stoi(linea.substr(pos2 + 1, pos3 - pos2 - 1));
        float cantidad_ecoextra = stoi(linea.substr(pos3 + 1));

        // Calcular el combustible gastado para cada tipo
        float gastado_regular = capacidad_regular - cantidad_regular;
        float gastado_premium = capacidad_premium - cantidad_premium;
        float gastado_ecoextra = capacidad_ecoextra - cantidad_ecoextra;
        if(codigo_estacion==codigo){
            // Mostrar el combustible gastado para esa estación
            cout << "Estación " << codigo_estacion << ":" << endl;
            cout << "Regular: " << gastado_regular << " galones" << endl;
            cout << "Premium: " << gastado_premium << " galones" << endl;
            cout << "Ecoextra: " << gastado_ecoextra << " galones" << endl;
            cout << "-----------------------------" << endl;
        }

    }

    // Cerrar el archivo
    archivo.close();
}
void Tanque::asignar_capacidad(){
    srand(time(0));

    // Generar un valor aleatorio para k entre 100 y 200 (ambos incluidos)
    int k = rand() % 101 + 100;

    // Repartir k en tres variables
    capacidad_regular= rand() % (k + 1);         // Primer número aleatorio entre 0 y k
    capacidad_ecoextra= rand() % (k - capacidad_regular+ 1);     // Segundo número aleatorio entre 0 y (k - a)
    capacidad_premium = k - capacidad_ecoextra- capacidad_regular;                // Tercer número, es el restante para que la suma sea k
}
string Tanque::mostrar_codigo(){
    return codigo;
}
//----------------------Métodos de la clase Estación de servicio-----------------------------------------------------------
//Definicion del constructor.

Estacion_de_servicio::Estacion_de_servicio(string _nombre, string _codigo, string _gerente, string _region, string _ubi_geografica, unsigned short _c_islas) {
    nombre = _nombre;
    codigo = _codigo;
    gerente = _gerente;
    region = _region;
    ubi_geografica = _ubi_geografica;
    c_islas = _c_islas;

    // Abrir el archivo en modo lectura para verificar si el código ya existe
    fstream archivo("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\cantidad_estaciones.txt", ios::in);
    string linea;
    bool estacion_existe = false;

    // Verificar si el código ya existe en el archivo
    while (getline(archivo, linea)) {
        // Buscar el código al principio de la línea antes del primer '@'
        int posicion_arroba = linea.find('@');
        if (posicion_arroba != string::npos) {
            string codigo_en_archivo = linea.substr(0, posicion_arroba);  // Obtener el código
            if (codigo_en_archivo == _codigo) {
                estacion_existe = true;
                break;
            }
        }
    }
    archivo.close();  // Cerrar archivo de lectura

    // Si la estación no existe, escribir en el archivo
    if (!estacion_existe) {
        fstream archivo_salida("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\cantidad_estaciones.txt", ios::app);
        archivo_salida << _codigo << "@" << _nombre << "@" << _gerente << "@" << _region << "@" << _ubi_geografica << "@" << _c_islas << "\n";
        archivo_salida.close();  // Cerrar archivo de escritura
    }
}
Estacion_de_servicio::~Estacion_de_servicio(){
}
string Estacion_de_servicio:: mostrar_codigo(){
    return codigo;
}
//----------------------Verificación de fugas-----------------------------------------------------------
void Tanque::revisar_fugas() {
    float almacenado_r = 0, almacenado_p = 0, almacenado_e = 0;
    float vendido_r = 0, vendido_p = 0, vendido_e = 0;

    // Leer cantidades almacenadas
    ifstream archivo_combustible("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\cantidad_combustible.txt");
    if (archivo_combustible.is_open()) {
        string linea;
        getline(archivo_combustible, linea);

        // Separar las cantidades almacenadas manualmente
        size_t pos = 0;
        int index = 0;
        while ((pos = linea.find('@')) != string::npos) {
            string token = linea.substr(0, pos);
            if (index == 0) {
                almacenado_r = stof(token); // Convertir a float
            } else if (index == 1) {
                almacenado_p = stof(token); // Convertir a float
            } else if (index == 2) {
                almacenado_e = stof(token); // Convertir a float
            }
            linea.erase(0, pos + 1);
            index++;
        }
        almacenado_e = stof(linea); // Última cantidad almacenada
        archivo_combustible.close();
    } else {
        cout << "Error al abrir el archivo de cantidades de combustible." << endl;
        return;
    }

    // Leer ventas
    ifstream archivo_ventas("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\ventas.txt");
    if (archivo_ventas.is_open()) {
        string linea;
        while (getline(archivo_ventas, linea)) {
            // Separamos el tipo de combustible y la cantidad vendida
            size_t pos = 0;
            string tipo_comb;
            float cantidad_vendida;

            // Ignorar los primeros campos hasta llegar al tipo de combustible
            for (int i = 0; i < 5; ++i) {
                pos = linea.find('@');
                linea.erase(0, pos + 1);
            }

            // Obtener el tipo de combustible
            pos = linea.find('@');
            tipo_comb = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            // Obtener la cantidad vendida
            cantidad_vendida = stof(linea); // Convertir a float

            // Acumular las ventas según el tipo de combustible
            if (tipo_comb == "Regular") {
                vendido_r += cantidad_vendida;
            } else if (tipo_comb == "Premium") {
                vendido_p += cantidad_vendida;
            } else if (tipo_comb == "Ecoextra") {
                vendido_e += cantidad_vendida;
            }
        }
        archivo_ventas.close();
    } else {
        cout << "Error al abrir el archivo de ventas." << endl;
        return;
    }

    // Verificación para el combustible regular
    if ((vendido_r + almacenado_r) >= (0.95 * capacidad_regular)) {
        cout << "No hay fugas en Regular" << endl;
    } else {
        cout << "Hay fugas en Regular" << endl;
    }

    // Verificación para el combustible premium
    if ((vendido_p + almacenado_p) >= (0.95 * capacidad_premium)) {
        cout << "No hay fugas en Premium" << endl;
    } else {
        cout << "Hay fugas en Premium" << endl;
    }

    // Verificación para el combustible extra
    if ((vendido_e + almacenado_e) >= (0.95 * capacidad_ecoextra)) {
        cout << "No hay fugas en Extra" << endl;
    } else {
        cout << "Hay fugas en Extra" << endl;
    }
}
//------------------------------subprogramas----------------------------------------------
void agregar_surtidor(string codigo_estacion, string codigo_surtidor) {
    const string ruta_archivo = "C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\surtidores.txt";
    ifstream archivo_in(ruta_archivo);
    string linea;
    bool surtidor_existe = false;
    int contador_surtidores = 0;

    // Contar los surtidores existentes para la estación y verificar si el surtidor ya existe
    while (getline(archivo_in, linea)) {
        // Suponiendo que el formato del archivo es: codigo_estacion@codigo_surtidor
        if (linea.find(codigo_estacion + "@") == 0) { // Si la línea comienza con el código de la estación
            contador_surtidores++;
            if (linea == (codigo_estacion + "@" + codigo_surtidor)) {
                surtidor_existe = true; // El surtidor ya existe
                break;
            }
        }
    }
    archivo_in.close();

    // Verificar si se puede agregar el nuevo surtidor
    if (surtidor_existe) {
        cout << "El surtidor con código " << codigo_surtidor << " ya existe para la estación " << codigo_estacion << "." << endl;
    } else if (contador_surtidores >= 9) {
        cout << "No se pueden agregar más de 9 surtidores a la estación " << codigo_estacion << "." << endl;
    } else {
        // Agregar el surtidor al archivo
        ofstream archivo_out(ruta_archivo, ios::app); // Abrir en modo añadir
        if (archivo_out.is_open()) {
            archivo_out << codigo_estacion << "@" << codigo_surtidor << endl; // Escribir en el archivo
            archivo_out.close();
            cout << "Surtidor con código " << codigo_surtidor << " agregado exitosamente a la estación " << codigo_estacion << "." << endl;
        } else {
            cout << "Error al abrir el archivo para escribir." << endl;
        }
    }
}

// mostrar ventas de estacion..
void ver_ventas_estacion(string c_estacion) {
    const string ruta_archivo = "C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\ventas.txt";
    ifstream archivo_in(ruta_archivo);
    string linea;
    unsigned long total_ventas = 0;

    if (!archivo_in.is_open()) {
        cout << "Error al abrir el archivo de ventas." << endl;
        return;
    }

    // Leer línea por línea
    while (getline(archivo_in, linea)) {
        int pos = 0;
      //string token;
        string delimiter = "@";
        string tokens[8];
        int i = 0;

        // Dividir la línea en tokens usando el delimitador '@'
        while ((pos = linea.find(delimiter)) != -1 && i < 8) {
            tokens[i++] = linea.substr(0, pos);
            linea.erase(0, pos + delimiter.length());
        }
        tokens[i] = linea;  // Último token

        // Verificar si la venta corresponde a la estación dada
        if (tokens[0] == c_estacion) {
            // Convertir el valor de venta a unsigned long y sumar
            total_ventas += stoul(tokens[6]);  // Convertir a unsigned long y sumar
        }
    }

    archivo_in.close();

    // Imprimir el total final de ventas
    cout << "Total ventas para la estación " << c_estacion << ": " << total_ventas << endl;
}
