#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "clases.h"

using namespace std;

// Definición del constructor.
surtidor::surtidor(string _codigo, string _modelo, bool _estado) {
    codigo = _codigo;
    modelo = _modelo;
    estado = _estado;
}
//Destructor.
surtidor::~surtidor(){

}
// Definición del método encargado de registrar la venta.
void surtidor::venta(string cedula, string fecha, string hora, char manera_pago,unsigned short tipo_comb, float c_disponible, float c_pedida,const unsigned long *precio_galon){
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
        ventas << codigo << "@" << cedula << "@" << fecha << "@" << hora << "@" << tipo_comb << "@" << c_dinero << "@" << manera_pago << "\n";
    }

    ventas.close();

}

//Definición del método encargado de ver las ventas.
void surtidor::consultar_venta( string codigo_surtidor) {
    fstream ventas("C:\\Users\\JOSE ANDRES\\Desktop\\desafio2_2024_2\\codigo\\desafio_2\\ventas.txt", std::ios::in);
    string linea;
    while (getline(ventas, linea)) {
        string codigo, cedula, fecha_venta, hora_venta, cantidad_pago, tipo_pago, t_combustible;

        // Delimitador
        char delimitador = '@';
        //posición.
        int pos = 0;

        // Extraer el código del surtidor
        pos = linea.find(delimitador);
        codigo = linea.substr(0, pos);
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

        // Extraer la cantidad del pago
        pos = linea.find(delimitador);
        t_combustible = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Extraer el tipo de pago
        pos = linea.find(delimitador);
        cantidad_pago = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Extraer el tipo de combustible
        pos = linea.find(delimitador);
        tipo_pago = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Verificar si el código del surtidor coincide
        if (codigo == codigo_surtidor) {
            // Imprimir solo si el código coincide
            cout << "Codigo del surtidor: " << codigo << "\n";
            cout << "Cedula: " << cedula << "\n";
            cout << "Fecha: " << fecha_venta << "\n";
            cout << "Hora: " << hora_venta << "\n";
            cout << "Cantidad del pago: " << cantidad_pago << "\n";
            cout << "Tipo de pago: " << tipo_pago << "\n";
            cout << "Tipo de combustible: " << t_combustible << "\n";
            cout << "------------------------\n";
        }
    }
ventas.close();
}

// Definición del método encargado de activar o desactivar el surtidor.
void surtidor::activar(bool activa) {
    estado = activa;
}
