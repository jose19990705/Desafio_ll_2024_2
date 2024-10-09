#ifndef CLASES_Y_FUNCIONES_H
#define CLASES_Y_FUNCIONES_H


//clase gasolinera
/*Se encargará de definir los atributos y métodos correspondientes
a una estación de gasolina*/
class Estacion_gasolinera{
private:
    string nombre;
    string codigo;
    string gerente;
    string region;
    string ubi_geografica;
    unsigned short islas;
    // Tanque tanque; // Aún debo crear la clase tanque, no te olvides joseeeeee!!!!. :)
public:
    void vender();
    void poner_surtidor();
    void quitar_surtidor();
};





#endif // CLASES_Y_FUNCIONES_H
