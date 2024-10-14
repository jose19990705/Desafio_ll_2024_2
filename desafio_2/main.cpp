#include <iostream>
#include<cstring>
#include <iostream>
#include<cstring>
#include<fstream>
#include "clases.h"
using namespace std;



int main() {
    const unsigned short MAX_ESTACIONES = 100;  // Definir un máximo de 100 estaciones.
    Estacion_de_servicio* estaciones[MAX_ESTACIONES];  // Arreglo de punteros a objetos Estacion_de_servicio.
    unsigned short num_estaciones = 0;  // Contador de estaciones.

    while (true) {
        string region;
        char opcion;
        cout << "Diga la región de la red: ";
        cin >> region;

        if (region == "norte") {
            cout << "Bienvenido a la región del norte." << endl;
            cout << "Si desea agregar una estación de servicio, presione a." << endl;
            cout << "Si desea acceder a una estación de servicio, presione b." << endl;
            cin >> opcion;

            if (opcion == 'a') {
                if (num_estaciones >= MAX_ESTACIONES) {
                    cout << "No se pueden agregar más estaciones. Límite alcanzado." << endl;
                    continue;
                }

                // Solicitar datos para la nueva estación.
                string nombre, codigo, gerente, coordenadas;
                unsigned short islas;
                cout << "Diga el nombre de la estación: ";
                cin >> nombre;
                cout << "Diga el código de la estación: ";
                cin >> codigo;
                cout << "Diga el gerente de la estación: ";
                cin >> gerente;
                cout << "Diga las coordenadas: ";
                cin >> coordenadas;
                cout << "Diga el número de islas: ";
                cin >> islas;

                // Crear una nueva instancia en memoria dinámica y asignarla al arreglo.
                estaciones[num_estaciones] = new Estacion_de_servicio(nombre, codigo, gerente, region, coordenadas, islas);
                num_estaciones++;

                cout << "Estación agregada exitosamente." << endl;
            }
            else if (opcion == 'b') {
                // Acceder a una estación.
                if (num_estaciones == 0) {
                    cout << "No hay estaciones disponibles." << endl;
                    continue;
                }

                string codigo_buscar;
                cout << "Digite el código de la estación que desea acceder: ";
                cin >> codigo_buscar;

                // Buscar la estación por código.
                bool encontrada = false;
                for (unsigned short i = 0; i < num_estaciones; i++) {
                    if ((*estaciones[i]).mostrar_codigo() == codigo_buscar) {
                        cout << "Estación encontrada: " << endl;
                        // Mostrar información o permitir acciones.
                        encontrada = true;
                        break;
                    }
                }

                if (!encontrada) {
                    cout << "Estación no encontrada." << endl;
                }
            }
        }
    }

    // Liberar memoria al final del programa
    for (unsigned short i = 0; i < num_estaciones; i++) {
        delete estaciones[i];
    }


    return 0;
}




