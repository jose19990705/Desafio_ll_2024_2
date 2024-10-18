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
    string codigo, modelo,c_estacion;
    bool estado;
public:
    //Constructor y destructor de la clase.
    surtidor(string _c_estacion, string _modelo, string _codigo, bool _estado);
    ~surtidor();
    //metodos.
    void venta(string codigo_estacion,string cedula, string fecha, string hora, char manera_pago,unsigned short tipo_comb, float c_disponible, float c_pedida,const unsigned long *precio_galon);
    void consultar_venta();
    string mostar_codigo();
    void activar(bool activa);
};

class Tanque{
private:
    unsigned short capacidad_regular;
    unsigned short capacidad_premium;
    unsigned short capacidad_ecoextra;
    string codigo;
public:
    Tanque(unsigned short _capacidad_regular,unsigned short _capacidad_premium,unsigned short _capacidad_ecoextra_,string _codigo);
    ~Tanque();
    float entregar_combustible(string c_estacion, unsigned short tipo_comb, float c_entregada);
    void mostrar_combustible_gastado();
    void asignar_capacidad();
    string mostrar_codigo();
    //Función amiga de fugas, esta será una función de carácter general.
    void revisar_fugas();
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

public:
    // Métodos
    Estacion_de_servicio(string _nombre, string _codigo, string _gerente, string _region, string _ubi_geografica, unsigned short _c_islas);
    ~Estacion_de_servicio();
    string mostrar_codigo();


};

//---------------------------------subprogramas--------------------------------------------

//void eliminar_datos(string codigo_maquina);
//void menu_estaciones();
void ver_ventas_estacion(string c_estacion);

//void agregar_surtidor(string codigo_estacion, string codigo_surtidor);























#endif // CLASES_H
