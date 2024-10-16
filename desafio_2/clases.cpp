#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
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
 void surtidor::venta(string codigo_estacion,string cedula, string fecha, string hora, char manera_pago,unsigned short tipo_comb, float c_disponible, float c_pedida,const unsigned long *precio_galon){
     if(estado==false){
         cout<<"El surtidor no esta activo";
         return;
     }
    fstream ventas("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\ventas.txt", std::ios::out | std::ios::app);
    float c_dinero = 0;
    if (!ventas.is_open()) {
        cerr << "Error en la apertura del archivo." << endl;
    } else {
        switch(tipo_comb) {
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
        } else {
            c_dinero *= c_pedida;
        }

        // Escribir los datos al final del archivo en una nueva línea
        ventas <<codigo_estacion<<"@"<< codigo << "@" << cedula << "@" << fecha << "@" << hora << "@" << tipo_comb << "@" << c_dinero << "@" << manera_pago << "\n";
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
Tanque::Tanque(unsigned short _capacidad_regular,unsigned short _capacidad_premium, unsigned short _capacidad_ecoextra_,string _codigo){
    capacidad_regular=_capacidad_regular;
    capacidad_premium=_capacidad_premium;
    capacidad_ecoextra=_capacidad_ecoextra_;
    codigo=_codigo;
    fstream archivo("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\cantidad_combustible.txt", ios::in | ios::out| ios::app);
    archivo<<_codigo<<"@"<<_capacidad_regular<<"@"<<_capacidad_premium<<"@"<<_capacidad_ecoextra_<<"\n";
    archivo.close();
}
//Definición del destructor.
Tanque::~Tanque(){
}

//método encargado de entrgar el combustible del tanque central.
void Tanque::entregar_combustible(string c_estacion, unsigned short tipo_comb, float c_entregada) {
    ifstream archivoEntrada("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\cantidad_combustible.txt");
    if (!archivoEntrada.is_open()) {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
        return;
    }

    string linea;
    string contenidoActualizado;
    bool encontrado = false;

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
                    capacidad1 = to_string(nueva_capacidad);
                    break;
                case 2:
                    nueva_capacidad = stof(capacidad2) - c_entregada;
                    capacidad2 = to_string(nueva_capacidad);
                    break;
                case 3:
                    nueva_capacidad = stof(capacidad3) - c_entregada;
                    capacidad3 = to_string(nueva_capacidad);
                    break;
                default:
                    cerr << "Tipo de combustible no válido." << endl;
                    return;
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
        return;
    }

    // Escribir el contenido actualizado en el archivo
    ofstream archivoSalida("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\cantidad_combustible.txt", ios::trunc);
    if (archivoSalida.is_open()) {
        archivoSalida << contenidoActualizado;
        archivoSalida.close();
    } else {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
    }
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

//----------------------Métodos de la clase Estación de servicio-----------------------------------------------------------
//Definicion del constructor.
Estacion_de_servicio::Estacion_de_servicio(string _nombre, string _codigo, string _gerente, string _region, string _ubi_geografica, unsigned short _c_islas){
    nombre=_nombre;
    codigo=_codigo;
    gerente=_gerente;
    region=_region;
    ubi_geografica=_ubi_geografica;
    c_islas=_c_islas;
    fstream archivo("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\cantidad_estaciones.txt", ios::in | ios::out| ios::app);
    archivo<<_codigo<<"@"<<_nombre<<"@"<<_gerente<<"@"<<_region<<"@"<<_ubi_geografica<<c_islas<<"\n";
    archivo.close();
}
Estacion_de_servicio::~Estacion_de_servicio(){
}
string Estacion_de_servicio:: mostrar_codigo(){
    return codigo;
}
//----------------------Verificación de fugas-----------------------------------------------------------

void revisar_fugas(unsigned short v_regular, unsigned short v_premium, unsigned short v_extra,unsigned short capacidad){
    if((v_regular+v_premium+v_extra)>(0.95*capacidad)){
        cout<<"No hay fugas";
    }
    else{
        cout<<"hay fugas";
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
