#ifndef CLASES_Y_FUNCIONES_H
#define CLASES_Y_FUNCIONES_H

#include <string>
#include <fstream>
#include <cstring>

using namespace std;
/*Clase tipo surtidor.
*/
class surtidor {
private:
    string codigo;
    string modelo;
    string categoria_combustible;
    unsigned short c_combustible;
    bool estado;

public:
    //Constructor de la clase.
    surtidor(string _codigo, string _modelo, string _categoria_combustible, bool _estado,_c_combustible);
    //metodos.
    void Registro_venta(string cedula_cliente,string fecha, string hora,unsigned long c_dinero, char manera_pago);
    void consultar_venta(string cedula_cliente,string fecha, string hora);
    void actualizar_cantidad_disponible(unsigned short listros_vendidos);
    void activar(bool activa);
    void desactivar(bool inactiva);
};

/*
// Clase Estacion_de_servicio
class Estacion_de_servicio {
private:
    string nombre;
    string codigo;
    string gerente;
    string region;
    string ubi_geografica;
    // Isla islas; // Número de islas para los surtidores.
    // Tanque tanque; // No te olvides de esto, Joseeeeee, hay que crear el tanque. :)

public:
    // Métodos
    void vender();            // Método para realizar una venta
    void poner_surtidor();     // Método para agregar un surtidor
    void quitar_surtidor();    // Método para quitar un surtidor
};
*/
#endif // CLASES_Y_FUNCIONES_H
