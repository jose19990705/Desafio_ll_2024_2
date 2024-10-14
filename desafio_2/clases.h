#ifndef CLASES_H
#define CLASES_H

#include <string>
#include <fstream>
#include <cstring>

using namespace std;
/*Clase surtidor.
*/
class surtidor {
private:
    string codigo, modelo;
    bool estado;
public:
    //Constructor y destructor de la clase.
    surtidor(string _codigo, string _modelo, bool _estado);
    ~surtidor();
    //metodos.
    void venta(string cedula, string fecha, string hora, char manera_pago,unsigned short tipo_comb, float c_disponible, float c_pedida,const unsigned long *precio_galon);
    void consultar_venta( string codigo_surtidor);
    void activar(bool activa);
};



/*


class Tanque{
private:
    unsigned short capacidad_regular;
    unsigned short capacidad_premium;
    unsigned short capacidad_ecoextra;
public:
    Tanque(float _capacidad_regular,float _capacidad_premium,float _capacidad_ecoextra);
    ~Tanque();
    void entregar_combustible(fstream &dispo_tanque, string c_estacion,unsigned short tipo_comb, float c_entregada);
    //Función amiga de fugas, esta será una función de carácter general.
    friend void revisar_fugas(unsigned short c_regular, unsigned short c_premium, unsigned short c_extra,unsigned short capacidad);
};


// Clase Estacion_de_servicio
class Estacion_de_servicio {
private:
    string nombre;
    string codigo;
    string gerente;
    string region;
    string ubi_geografica;
    unsigned short c_islas;
    Tanque tanque;

public:
    // Métodos
    void vender();            // Método para realizar una venta
    void poner_surtidor();     // Método para agregar un surtidor
    void quitar_surtidor();    // Método para quitar un surtidor
};


*/
#endif // CLASES_H
