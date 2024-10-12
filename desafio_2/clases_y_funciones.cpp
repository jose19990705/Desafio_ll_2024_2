#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "clases_y_funciones.h"

using namespace std;

// Definición del constructor.
surtidor::surtidor(string _codigo, string _modelo, string _categoria_combustible, bool _estado, unsigned short *_c_combustible) {
    codigo = _codigo;
    modelo = _modelo;
    categoria_combustible = _categoria_combustible;
    estado = _estado;
    c_combustible = _c_combustible;
}

// Definición del método encargado de registrar la venta.
void surtidor::Registro_venta(fstream &ventas,string codigo_surtidor,string cedula_cliente, string fecha, string hora,string t_combustible, unsigned long c_dinero, char manera_pago) {
    if (!ventas.is_open()) {
        cerr << "Error en la apertura del archivo." << endl;
    } else {
        ventas <<codigo_surtidor<<"@"<< cedula_cliente << "@" << fecha << "@" << hora <<t_combustible<< "@" << c_dinero << "@" << manera_pago <<"@"<< "\n";
    }
}

//Definición del método encargado de ver las ventas.
void surtidor::consultar_venta(fstream &ventas, string codigo_surtidor) {
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
        cantidad_pago = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Extraer el tipo de pago
        pos = linea.find(delimitador);
        tipo_pago = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Extraer el tipo de combustible
        pos = linea.find(delimitador);
        t_combustible = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Verificar si el código del surtidor coincide
        if (codigo == codigo_surtidor) {
            // Imprimir solo si el código coincide
            cout << "Código del surtidor: " << codigo << "\n";
            cout << "Cédula: " << cedula << "\n";
            cout << "Fecha: " << fecha_venta << "\n";
            cout << "Hora: " << hora_venta << "\n";
            cout << "Cantidad del pago: " << cantidad_pago << "\n";
            cout << "Tipo de pago: " << tipo_pago << "\n";
            cout << "Tipo de combustible: " << t_combustible << "\n";
            cout << "------------------------\n";
        }
    }
}

//Definicion del método encargado de actualizar la cantidad de combustible.
void actualizar_cantidad_combustible(fstream &dispo_tanque, string identificacion_tanque, string tipo_combustible, unsigned short litros_vendidos) {
    string tanque, combustible_regular, combustible_premium, combustible_extra, linea;
    bool tanque_encontrado = false;

    // Posición actual del archivo (para volver y sobrescribir la línea modificada).
    streampos posicion_inicio;

    while (getline(dispo_tanque, linea)) {
        // Delimitador para separar los campos.
        char delimitador = '@';
        int pos = 0;

        // Guardamos la posición inicial de la línea.
        posicion_inicio = dispo_tanque.tellg();

        // Extraer la identificación del tanque.
        pos = linea.find(delimitador);
        tanque = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Si la identificación del tanque coincide con la buscada.
        if (tanque == identificacion_tanque) {
            tanque_encontrado = true;

            // Extraer la cantidad de combustible regular.
            pos = linea.find(delimitador);
            combustible_regular = linea.substr(0, pos);
            linea = linea.substr(pos + 1);

            // Extraer la cantidad de combustible premium.
            pos = linea.find(delimitador);
            combustible_premium = linea.substr(0, pos);
            linea = linea.substr(pos + 1);

            // Extraer la cantidad de combustible extra.
            combustible_extra = linea;

            // Convertir los valores de combustible a números enteros.
            int cantidad_regular = stoi(combustible_regular);
            int cantidad_premium = stoi(combustible_premium);
            int cantidad_extra = stoi(combustible_extra);

            // Actualizar la cantidad según el tipo de combustible vendido.
            if (tipo_combustible == "regular") {
                cantidad_regular -= litros_vendidos;
            } else if (tipo_combustible == "premium") {
                cantidad_premium -= litros_vendidos;
            } else if (tipo_combustible == "extra") {
                cantidad_extra -= litros_vendidos;
            }

            // Reescribir la línea actualizada.
            string nueva_linea = identificacion_tanque + "@" + to_string(cantidad_regular) + "@" + to_string(cantidad_premium) + "@" + to_string(cantidad_extra);

            // Ir a la posición inicial de la línea para sobrescribir.
            dispo_tanque.seekp(posicion_inicio - (streamoff)linea.length() - 1);
            dispo_tanque << nueva_linea << endl;

            break;
        }
    }
}

// Definición del método encargado de activar o desactivar el surtidor.
void surtidor::activar(bool activa) {
    estado = activa;
}
