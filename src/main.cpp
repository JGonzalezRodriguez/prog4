//TODO: incluir coso para imprimir, para excepciones, etc
#include<stdio.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include "../include/fabrica.h"

using namespace std;
int main() {
    printf("\n Bienvenide, elija una opcion:");
    int opcion;
    while(opcion != 5){
        printf("\n1. Administrador");
        printf("\n2. Docente");
        printf("\n3. Estudiante");
        printf("\n4. Cargar datos de prueba");
        printf("\n5. Salir");
        printf("\n");
            
        scanf("%d", &opcion);
        switch(opcion){
            case 1: {// casos de uso de administrador
                printf("\n Elija el caso de uso a ejecutar como Administrador: ");
                printf("\n1. Alta de usuario");
                printf("\n2. Alta de asignatura");
                printf("\n3. Eliminacion de asignatura");
                printf("\n4. Asignacion de docentes a una asignatura");
                printf("\n5. Modificar fecha del sistema");
                printf("\n6. Consultar fecha del sistema");
                printf("\n");
                    
                int opcion2;
                scanf("%d", &opcion2);
                switch(opcion2){
                    case 1: {
                        break;
                    }
                    case 2: {
                        ///////////////// ALTA ASIGNATURA //////////////////////////
                        //obteniendo datos
                        std::string nombre, codigo;
                        char teo, prac, mon;
                        bool tieneteo, tieneprac, tienemon;
                        printf("\nPorfavor ingrese el nombre de la asignatura que desea dar de alto\n");
                        std::cin.ignore(1); // ignora el "2" ingresado previamente?
                        getline(std::cin, nombre);
                        printf("\nIngrese el codigo de la asignatura. Debe ser unico\n");
                        getline(std::cin, codigo);
                        printf("\nLa asignatura tendra modalidad de teorico? s/n\n");
                        std::cin >> teo;
                        if (teo == 's'){
                            tieneteo = true;
                        }else if (teo == 'n'){
                            tieneteo = false;
                        }else {
                            throw std::invalid_argument("\nRepuesta no valida, debe ingresar 's' o 'n'.\n");
                        }
                        printf("\nLa asignatura tendra modalidad de practico? s/n\n");
                        std::cin >> prac;
                        if (prac == 's'){
                            tieneprac = true;
                        }else if (prac == 'n'){
                            tieneprac = false;
                        }else{
                            throw std::invalid_argument("\nRepuesta no valida, debe ingresar 's' o 'n'.\n");
                        }
                        printf("\nLa asignatura tendra modalidad de monitoreo? s/n\n");
                        std::cin >> mon;
                        printf("eureka");
                        if (mon == 's'){
                            tienemon = true;
                        }else if (mon == 'n'){
                            tienemon = false;
                        }else{
                            throw std::invalid_argument("\nRepuesta no valida, debe ingresar 's' o 'n'.\n");
                        }
                        //creando asignatura
                        Fabrica *interface = Fabrica::getInstancia(); //esto va a explotar cuando santi suba la fabrica nueva que es singleton
                        interface->getIAsignatura()->altaAsignatura(nombre, codigo, tieneteo, tieneprac, tienemon);
                        DtAsignatura* asignatura = interface->getIAsignatura()->mostrarDatosAsignatura();
                        //TODO: sobrecargar '<<' para poder imprimir DtAsignatura (no quiero pisarme con nadie)
                        //mostrando datos a lo rustico de maneria provisoria:
                        std::cout << asignatura->getNombre();
                        std::cout << asignatura->getCodigo();
                        //confirmando
                        printf("\nConfirmar alta de asignatura? s/n\n");
                        char cConf;
                        std::cin >> cConf;
                        bool bConf;
                        if (cConf == 's'){
                            bConf = true;
                        }else if (cConf == 'n'){
                            bConf = false;
                        }else{
                            throw std::invalid_argument("\nRepuesta no valida, debe ingresar 's' o 'n'.\n");
                        }
                        interface->getIAsignatura()->confirmarAltaAsignatura(bConf);
                        delete asignatura;
                        delete interface;
                        break;
                    }
                    case 3: {
                        break;
                    }
                    case 4: {
                        break;
                    }
                    case 5: {
                        break;
                    }
                    case 6: {
                        break;
                    }
                    default: {
                        throw std::invalid_argument("Opcion no valida");
                        break;
                    }
                }
                break;
            }
            case 2: {// casos de uso de docente
                printf("\n Elija el caso de uso a ejecutar como Docente: ");
                printf("\n1. Inicio de clase");
                printf("\n2. Finalizacion de clase");
                printf("\n3. Suscribirse a notificacion");
                printf("\n4. Consulta de notificaciones");
                printf("\n5. Tiempo de dictado de clase");
                printf("\n6. Tiempo de asistencia a clase");
                printf("\n7. Envio de mensaje");
                printf("\n");
                    
                
                int opcion2;
                scanf("%d", &opcion2);
                switch(opcion2){
                    case 1: {
                        break;
                    }
                    case 2: {
                        break;
                    }
                    case 3: {
                        break;
                    }
                    case 4: {
                        break;
                    }
                    case 5: {
                        break;
                    }
                    case 6: {
                        break;
                    }
                    case 7: {
                        break;
                    }
                    default: {
                        throw std::invalid_argument("Opcion no valida");
                        break;
                    }
                }
                break;
            }
            case 3: {// casos de uso de estudiante
                printf("\n Elija el caso de uso a ejecutar como Estudiante: ");
                printf("\n1. Inscripcion a las asignaturas");
                printf("\n2. Asistencia a clase en vivo");
                printf("\n3. Envio de mensaje");
                printf("\n4. Suscribirse a notificacion");
                printf("\n5. Consulta de notificaciones");
                printf("\n");

                int opcion2;
                scanf("%d", &opcion2);
                switch(opcion2){
                    case 1: {
                        break;
                    }
                    case 2: {
                        break;
                    }
                    case 3: {
                        break;
                    }
                    case 4: {
                        break;
                    }
                    case 5: {
                        break;
                    }
                    default: {
                        throw std::invalid_argument("Opcion no valida");
                        break;
                    }
                }
                break;
            }
            case 4: {
                //TODO: cargar casos prueba (todo hardcodeado)
                break;
            }
            case 5: {
                printf("Gracias por usar FingClass, hasta la proxima!\n");
                break;
            }
            default: {
                throw std::invalid_argument("Opcion no valida");
                break;
            }
        }
    }
    return 0;
}