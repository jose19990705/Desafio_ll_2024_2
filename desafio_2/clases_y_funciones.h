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
    string codigo, modelo,categoria_combustible;
    unsigned short * c_combustible;
    bool estado;
public:
    //Constructor y destructor de la clase.
    surtidor(string _codigo, string _modelo, string _categoria_combustible, bool _estado, unsigned short *_c_combustible);
    ~surtidor();
    //metodos.
    void Registro_venta(fstream &ventas,string codigo_surtidor,string cedula_cliente, string fecha, string hora,string t_combustible, unsigned long c_dinero, char manera_pago);
    void consultar_venta(fstream &ventas, string codigo_surtidor);
    void actualizar_cantidad_combustible(unsigned short listros_vendidos);
    void activar(bool activa);
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
