#include <iostream>
#include<cstring>
#include <iostream>
#include<cstring>
#include<fstream>
#include "clases.h"
using namespace std;



int main() {
    // definicion de Estaciones del norte
    Estacion_de_servicio ne1=Estacion_de_servicio("termax2","001","jose","norte","10°58'06.6'N 74°46'52.7'W",4);
    Estacion_de_servicio ne2=Estacion_de_servicio("termax3","002","marta","norte","11°14'26.9'N 74°11'56.4'W",4);
    Estacion_de_servicio ne3=Estacion_de_servicio("termax4","003","Andres","norte","10°23'27.6'N 75°28'45.8'W",4);
    //definición de Estaciones del centro.
    Estacion_de_servicio ce1=Estacion_de_servicio("termax5","004","jose","centro","4°36'35.0'N 74°05'40.2'W",4);
    Estacion_de_servicio ce2=Estacion_de_servicio("termax6","005","marta","centro","11°14'26.9'N 74°11'56.4'W",4);
    Estacion_de_servicio ce3=Estacion_de_servicio("termax7","006","Andres","centro","10°23'27.6'N 75°28'45.8'W",4);
    //definicion estaciones del sur.
    Estacion_de_servicio se1=Estacion_de_servicio("termax7","007","juan","sur","2°57'31.0'N 75°01'22.0'W",4);
    Estacion_de_servicio se2=Estacion_de_servicio("termax8","008","pepe","sur","2°26'23.7'N 76°38'37.6'W",4);
    Estacion_de_servicio se3=Estacion_de_servicio("termax9","009","raul","sur","4°12'06.6'S 69°56'47.0'W",4);

   // (unsigned short _capacidad_regular,unsigned short _capacidad_premium,unsigned short _capacidad_ecoextra, string _codigo);
    Tanque te1= Tanque(70,30,100,"001");
    Tanque te2=Tanque(70,30,100,"002");
    Tanque te3= Tanque(70,30,100,"003");
    Tanque te4=Tanque(70,30,100,"004");
    Tanque te5= Tanque(70,30,100,"005");
    Tanque te6=Tanque(70,30,100,"006");
    Tanque te7= Tanque(70,30,100,"007");
    Tanque te8=Tanque(70,30,100,"008");
    Tanque te9= Tanque(70,30,100,"009");
    //surtidores.


    surtidor sne11=surtidor("001","10","0011",true);
    surtidor sne12=surtidor("001","10","0012",true);
    surtidor sne13=surtidor("001","10","0013",true);
    //siguiente
    surtidor sne21=surtidor("002","10","0021",true);
    surtidor sne22=surtidor("002","10","0022",true);
    surtidor sne23=surtidor("002","10","0023",true);
    //siguient
    surtidor sne31=surtidor("003","10","0031",true);
    surtidor sne32=surtidor("003","10","0032",true);
    surtidor sne33=surtidor("003","10","0033",true);
    //siguiente
    surtidor sce11=surtidor("004","10","0041",true);
    surtidor sce12=surtidor("004","10","0042",true);
    surtidor sce13=surtidor("004","10","0043",true);
    //siguiente
    surtidor sce21=surtidor("005","10","0051",true);
    surtidor sce22=surtidor("005","10","0052",true);
    surtidor sce23=surtidor("005","10","0053",true);
    //siguiente
    surtidor sce31=surtidor("006","10","0061",true);
    surtidor sce32=surtidor("006","10","0062",true);
    surtidor sce33=surtidor("006","10","0063",true);
    //siguiente
    surtidor sse11=surtidor("007","10","0074",true);
    surtidor sse12=surtidor("007","10","0075",true);
    surtidor sse13=surtidor("007","10","0076",true);
    //siguiente
    surtidor sse21=surtidor("008","10","0081",true);
    surtidor sse22=surtidor("008","10","0082",true);
    surtidor sse23=surtidor("008","10","0083",true);
    //siguiente
    surtidor sse31=surtidor("009","10","0091",true);
    surtidor sse32=surtidor("009","10","0092",true);
    surtidor sse33=surtidor("009","10","0093",true);

Estacion_de_servicio* estaciones[] = {&ne1, &ne2, &ne3, &ce1, &ce2, &ce3, &se1, &se2, &se3};

    surtidor* surti_estaciones[] = {
        &sne11, &sne12, &sne13,
        &sne21, &sne22, &sne23,
        &sne31, &sne32, &sne33,
        &sce11, &sce12, &sce13,
        &sce21, &sce22, &sce23,
        &sce31, &sce32, &sce33,
        &sse11, &sse12, &sse13,
        &sse21, &sse22, &sse23,
        &sse31, &sse32, &sse33
    };

//Tanque* tanques[9] = {&te1, &te2, &te3, &te4, &te5, &te6, &te7, &te8, &te9};



//menú para el control de la red.
    char opcion;
    while(true){
        cout<<"Estas son las estaciones de servicio del norte: ";
        cout<<"termax2";
        cout<<"termax3";
        cout<<"termax4";
        cout<<"Estas son las estaciones de servicio del centro: ";
        cout<<"termax5";
        cout<<"termax6";
        cout<<"termax7";
        cout<<"Estas son las estaciones de servicio del sur: ";
        cout<<"termax8";
        cout<<"termax9";
        cout<<"termax10";

        cout<<"si desea ingresar a alguna, presione 'e', de lo contrario presione otra tecla: ";
        cin>>opcion;
        if(opcion=='e'){
            unsigned short eleccion_estacion;
            cout<<"1) termax2"<<endl;
            cout<<"2) termax3"<<endl;
            cout<<"3) termax4"<<endl;
            cout<<"4) termax5"<<endl;
            cout<<"5) termax6"<<endl;
            cout<<"6) termax7"<<endl;
            cout<<"7) termax8"<<endl;
            cout<<"8) termax9"<<endl;
            cout<<"9) termax10"<<endl;
            cin>>eleccion_estacion;
            string codi_surti;
            char desactivar;
            bool encontrado=false;
            unsigned short opciones_estacion;
            switch(eleccion_estacion){
            case 1:
                cout<<"Bienvenido a termax2"<<endl;
                cout<<"los códigos de los surtidores existentes son: 0011,0012,0013"<<endl;
                cout<<"si desea ver las ventas hechas en la estacion presione 1 "<<endl;
                cout<<"si desea consultar el histórico de transacciones de un surtidor 2"<<endl;
                cout<<"si desea consultar la cantidad de combustible vendida 3"<<endl;
                cout<<"si desea activar o desactivar un surtidor 4";
                cin>>opciones_estacion;

                switch(opciones_estacion){
                case 1:
                    ver_ventas_estacion("001");
                    break;
                case 2:
                    cout<<"Ingrese el codigo del surtidor:";
                    cin>>codi_surti;
                    for(unsigned short i=0;i<9;i++){
                        if(estaciones[i]->mostrar_codigo()=="001"){
                             for(int k=0;k<27;k++){
                                if(surti_estaciones[k]->mostar_codigo()==codi_surti){
                                     surti_estaciones[k]->consultar_venta();
                                     encontrado=true;
                                     break;
                                }
                             }
                        }
                        if(encontrado){
                            break;
                        }
                    }
                    break;
                case 3:
                    cout<<"la Cantidad de combustible vendido por cada clase es: "<<endl;
                    te1.mostrar_combustible_gastado();
                    break;
                case 4:
                    cout<<"Ingrese la el código de la estación que desea desactivar o activar: ";
                    cin>>codi_surti;
                    cout<<"si desea desactivar una estacion presione 1, si desea activarla presione 2: ";
                    cin>>desactivar;
                    if(desactivar=='1'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(false);
                                break;
                            }
                        }
                    }
                    else if(desactivar=='2'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(true);
                                break;
                            }
                        }
                    }
                    break;
                }
            case 2:
                cout<<"Bienvenido a termax3"<<endl;
                cout<<"los códigos de los surtidores existentes son: 0011,0012,0013"<<endl;
                cout<<"si desea ver las ventas hechas en la estacion presione 1 "<<endl;
                cout<<"si desea consultar el histórico de transacciones de un surtidor 2"<<endl;
                cout<<"si desea consultar la cantidad de combustible vendida 3"<<endl;
                cout<<"si desea activar o desactivar un surtidor 4";
                cin>>opciones_estacion;

                switch(opciones_estacion){
                case 1:
                    ver_ventas_estacion("001");
                    break;
                case 2:
                    cout<<"Ingrese el codigo del surtidor:";
                    cin>>codi_surti;
                    for(unsigned short i=0;i<9;i++){
                        if(estaciones[i]->mostrar_codigo()=="001"){
                            for(int k=0;k<27;k++){
                                if(surti_estaciones[k]->mostar_codigo()==codi_surti){
                                    surti_estaciones[k]->consultar_venta();
                                    encontrado=true;
                                    break;
                                }
                            }
                        }
                        if(encontrado){
                            break;
                        }
                    }
                    break;
                case 3:
                    cout<<"la Cantidad de combustible vendido por cada clase es: "<<endl;
                    te1.mostrar_combustible_gastado();
                    break;
                case 4:
                    cout<<"Ingrese la el código de la estación que desea desactivar o activar: ";
                    cin>>codi_surti;
                    cout<<"si desea desactivar una estacion presione 1, si desea activarla presione 2: ";
                    cin>>desactivar;
                    if(desactivar=='1'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(false);
                                break;
                            }
                        }
                    }
                    else if(desactivar=='2'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(true);
                                break;
                            }
                        }
                    }
                    break;
                }
                /////////////////////////////////////////////////
                break;
            case 3:
                cout<<"Bienvenido a termax2"<<endl;
                cout<<"los códigos de los surtidores existentes son: 0011,0012,0013"<<endl;
                cout<<"si desea ver las ventas hechas en la estacion presione 1 "<<endl;
                cout<<"si desea consultar el histórico de transacciones de un surtidor 2"<<endl;
                cout<<"si desea consultar la cantidad de combustible vendida 3"<<endl;
                cout<<"si desea activar o desactivar un surtidor 4";
                cin>>opciones_estacion;

                switch(opciones_estacion){
                case 1:
                    ver_ventas_estacion("001");
                    break;
                case 2:
                    cout<<"Ingrese el codigo del surtidor:";
                    cin>>codi_surti;
                    for(unsigned short i=0;i<9;i++){
                        if(estaciones[i]->mostrar_codigo()=="001"){
                            for(int k=0;k<27;k++){
                                if(surti_estaciones[k]->mostar_codigo()==codi_surti){
                                    surti_estaciones[k]->consultar_venta();
                                    encontrado=true;
                                    break;
                                }
                            }
                        }
                        if(encontrado){
                            break;
                        }
                    }
                    break;
                case 3:
                    cout<<"la Cantidad de combustible vendido por cada clase es: "<<endl;
                    te1.mostrar_combustible_gastado();
                    break;
                case 4:
                    cout<<"Ingrese la el código de la estación que desea desactivar o activar: ";
                    cin>>codi_surti;
                    cout<<"si desea desactivar una estacion presione 1, si desea activarla presione 2: ";
                    cin>>desactivar;
                    if(desactivar=='1'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(false);
                                break;
                            }
                        }
                    }
                    else if(desactivar=='2'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(true);
                                break;
                            }
                        }
                    }
                    break;
                }
                break;
            case 4:
                cout<<"Bienvenido a termax2"<<endl;
                cout<<"los códigos de los surtidores existentes son: 0011,0012,0013"<<endl;
                cout<<"si desea ver las ventas hechas en la estacion presione 1 "<<endl;
                cout<<"si desea consultar el histórico de transacciones de un surtidor 2"<<endl;
                cout<<"si desea consultar la cantidad de combustible vendida 3"<<endl;
                cout<<"si desea activar o desactivar un surtidor 4";
                cin>>opciones_estacion;

                switch(opciones_estacion){
                case 1:
                    ver_ventas_estacion("001");
                    break;
                case 2:
                    cout<<"Ingrese el codigo del surtidor:";
                    cin>>codi_surti;
                    for(unsigned short i=0;i<9;i++){
                        if(estaciones[i]->mostrar_codigo()=="001"){
                            for(int k=0;k<27;k++){
                                if(surti_estaciones[k]->mostar_codigo()==codi_surti){
                                    surti_estaciones[k]->consultar_venta();
                                    encontrado=true;
                                    break;
                                }
                            }
                        }
                        if(encontrado){
                            break;
                        }
                    }
                    break;
                case 3:
                    cout<<"la Cantidad de combustible vendido por cada clase es: "<<endl;
                    te1.mostrar_combustible_gastado();
                    break;
                case 4:
                    cout<<"Ingrese la el código de la estación que desea desactivar o activar: ";
                    cin>>codi_surti;
                    cout<<"si desea desactivar una estacion presione 1, si desea activarla presione 2: ";
                    cin>>desactivar;
                    if(desactivar=='1'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(false);
                                break;
                            }
                        }
                    }
                    else if(desactivar=='2'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(true);
                                break;
                            }
                        }
                    }
                    break;
                }
                break;
            case 5:
                cout<<"Bienvenido a termax2"<<endl;
                cout<<"los códigos de los surtidores existentes son: 0011,0012,0013"<<endl;
                cout<<"si desea ver las ventas hechas en la estacion presione 1 "<<endl;
                cout<<"si desea consultar el histórico de transacciones de un surtidor 2"<<endl;
                cout<<"si desea consultar la cantidad de combustible vendida 3"<<endl;
                cout<<"si desea activar o desactivar un surtidor 4";
                cin>>opciones_estacion;

                switch(opciones_estacion){
                case 1:
                    ver_ventas_estacion("001");
                    break;
                case 2:
                    cout<<"Ingrese el codigo del surtidor:";
                    cin>>codi_surti;
                    for(unsigned short i=0;i<9;i++){
                        if(estaciones[i]->mostrar_codigo()=="001"){
                            for(int k=0;k<27;k++){
                                if(surti_estaciones[k]->mostar_codigo()==codi_surti){
                                    surti_estaciones[k]->consultar_venta();
                                    encontrado=true;
                                    break;
                                }
                            }
                        }
                        if(encontrado){
                            break;
                        }
                    }
                    break;
                case 3:
                    cout<<"la Cantidad de combustible vendido por cada clase es: "<<endl;
                    te1.mostrar_combustible_gastado();
                    break;
                case 4:
                    cout<<"Ingrese la el código de la estación que desea desactivar o activar: ";
                    cin>>codi_surti;
                    cout<<"si desea desactivar una estacion presione 1, si desea activarla presione 2: ";
                    cin>>desactivar;
                    if(desactivar=='1'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(false);
                                break;
                            }
                        }
                    }
                    else if(desactivar=='2'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(true);
                                break;
                            }
                        }
                    }
                    break;
                }
                break;
            case 6:
                cout<<"Bienvenido a termax2"<<endl;
                cout<<"los códigos de los surtidores existentes son: 0011,0012,0013"<<endl;
                cout<<"si desea ver las ventas hechas en la estacion presione 1 "<<endl;
                cout<<"si desea consultar el histórico de transacciones de un surtidor 2"<<endl;
                cout<<"si desea consultar la cantidad de combustible vendida 3"<<endl;
                cout<<"si desea activar o desactivar un surtidor 4";
                cin>>opciones_estacion;

                switch(opciones_estacion){
                case 1:
                    ver_ventas_estacion("001");
                    break;
                case 2:
                    cout<<"Ingrese el codigo del surtidor:";
                    cin>>codi_surti;
                    for(unsigned short i=0;i<9;i++){
                        if(estaciones[i]->mostrar_codigo()=="001"){
                            for(int k=0;k<27;k++){
                                if(surti_estaciones[k]->mostar_codigo()==codi_surti){
                                    surti_estaciones[k]->consultar_venta();
                                    encontrado=true;
                                    break;
                                }
                            }
                        }
                        if(encontrado){
                            break;
                        }
                    }
                    break;
                case 3:
                    cout<<"la Cantidad de combustible vendido por cada clase es: "<<endl;
                    te1.mostrar_combustible_gastado();
                    break;
                case 4:
                    cout<<"Ingrese la el código de la estación que desea desactivar o activar: ";
                    cin>>codi_surti;
                    cout<<"si desea desactivar una estacion presione 1, si desea activarla presione 2: ";
                    cin>>desactivar;
                    if(desactivar=='1'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(false);
                                break;
                            }
                        }
                    }
                    else if(desactivar=='2'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(true);
                                break;
                            }
                        }
                    }
                    break;
                }
                break;
            case 7:
                cout<<"Bienvenido a termax2"<<endl;
                cout<<"los códigos de los surtidores existentes son: 0011,0012,0013"<<endl;
                cout<<"si desea ver las ventas hechas en la estacion presione 1 "<<endl;
                cout<<"si desea consultar el histórico de transacciones de un surtidor 2"<<endl;
                cout<<"si desea consultar la cantidad de combustible vendida 3"<<endl;
                cout<<"si desea activar o desactivar un surtidor 4";
                cin>>opciones_estacion;

                switch(opciones_estacion){
                case 1:
                    ver_ventas_estacion("001");
                    break;
                case 2:
                    cout<<"Ingrese el codigo del surtidor:";
                    cin>>codi_surti;
                    for(unsigned short i=0;i<9;i++){
                        if(estaciones[i]->mostrar_codigo()=="001"){
                            for(int k=0;k<27;k++){
                                if(surti_estaciones[k]->mostar_codigo()==codi_surti){
                                    surti_estaciones[k]->consultar_venta();
                                    encontrado=true;
                                    break;
                                }
                            }
                        }
                        if(encontrado){
                            break;
                        }
                    }
                    break;
                case 3:
                    cout<<"la Cantidad de combustible vendido por cada clase es: "<<endl;
                    te1.mostrar_combustible_gastado();
                    break;
                case 4:
                    cout<<"Ingrese la el código de la estación que desea desactivar o activar: ";
                    cin>>codi_surti;
                    cout<<"si desea desactivar una estacion presione 1, si desea activarla presione 2: ";
                    cin>>desactivar;
                    if(desactivar=='1'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(false);
                                break;
                            }
                        }
                    }
                    else if(desactivar=='2'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(true);
                                break;
                            }
                        }
                    }
                    break;
                }
                break;
            case 8:
                cout<<"Bienvenido a termax2"<<endl;
                cout<<"los códigos de los surtidores existentes son: 0011,0012,0013"<<endl;
                cout<<"si desea ver las ventas hechas en la estacion presione 1 "<<endl;
                cout<<"si desea consultar el histórico de transacciones de un surtidor 2"<<endl;
                cout<<"si desea consultar la cantidad de combustible vendida 3"<<endl;
                cout<<"si desea activar o desactivar un surtidor 4";
                cin>>opciones_estacion;

                switch(opciones_estacion){
                case 1:
                    ver_ventas_estacion("001");
                    break;
                case 2:
                    cout<<"Ingrese el codigo del surtidor:";
                    cin>>codi_surti;
                    for(unsigned short i=0;i<9;i++){
                        if(estaciones[i]->mostrar_codigo()=="001"){
                            for(int k=0;k<27;k++){
                                if(surti_estaciones[k]->mostar_codigo()==codi_surti){
                                    surti_estaciones[k]->consultar_venta();
                                    encontrado=true;
                                    break;
                                }
                            }
                        }
                        if(encontrado){
                            break;
                        }
                    }
                    break;
                case 3:
                    cout<<"la Cantidad de combustible vendido por cada clase es: "<<endl;
                    te1.mostrar_combustible_gastado();
                    break;
                case 4:
                    cout<<"Ingrese la el código de la estación que desea desactivar o activar: ";
                    cin>>codi_surti;
                    cout<<"si desea desactivar una estacion presione 1, si desea activarla presione 2: ";
                    cin>>desactivar;
                    if(desactivar=='1'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(false);
                                break;
                            }
                        }
                    }
                    else if(desactivar=='2'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(true);
                                break;
                            }
                        }
                    }
                    break;
                }
                break;
            case 9:
                cout<<"Bienvenido a termax2"<<endl;
                cout<<"los códigos de los surtidores existentes son: 0011,0012,0013"<<endl;
                cout<<"si desea ver las ventas hechas en la estacion presione 1 "<<endl;
                cout<<"si desea consultar el histórico de transacciones de un surtidor 2"<<endl;
                cout<<"si desea consultar la cantidad de combustible vendida 3"<<endl;
                cout<<"si desea activar o desactivar un surtidor 4";
                cin>>opciones_estacion;

                switch(opciones_estacion){
                case 1:
                    ver_ventas_estacion("001");
                    break;
                case 2:
                    cout<<"Ingrese el codigo del surtidor:";
                    cin>>codi_surti;
                    for(unsigned short i=0;i<9;i++){
                        if(estaciones[i]->mostrar_codigo()=="001"){
                            for(int k=0;k<27;k++){
                                if(surti_estaciones[k]->mostar_codigo()==codi_surti){
                                    surti_estaciones[k]->consultar_venta();
                                    encontrado=true;
                                    break;
                                }
                            }
                        }
                        if(encontrado){
                            break;
                        }
                    }
                    break;
                case 3:
                    cout<<"la Cantidad de combustible vendido por cada clase es: "<<endl;
                    te1.mostrar_combustible_gastado();
                    break;
                case 4:
                    cout<<"Ingrese la el código de la estación que desea desactivar o activar: ";
                    cin>>codi_surti;
                    cout<<"si desea desactivar una estacion presione 1, si desea activarla presione 2: ";
                    cin>>desactivar;
                    if(desactivar=='1'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(false);
                                break;
                            }
                        }
                    }
                    else if(desactivar=='2'){
                        for(int i =0; i<27;i++){
                            if(surti_estaciones[i]->mostar_codigo()==codi_surti){
                                surti_estaciones[i]->activar(true);
                                break;
                            }
                        }
                    }
                    break;
                }
                break;
            }
        }
        break;

    }








    return 0;
}




