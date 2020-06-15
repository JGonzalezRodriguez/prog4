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
                        bool agregarusuario = true;
                        while(agregarusuario){
                            char letraselec;
                            printf("\n Desea agregar un nuevo usuario al sistema? s/n: ");
                            scanf("%s", &letraselec);
                            if(letraselec == 's'){
                                cin.ignore();
                                std::string nombre, contrasenia, email, imagen;
                                bool docente;
                                char letra;
                                printf("\n Introduzca su nombre: ");
                                getline(std::cin, nombre);
                                printf("\n Introduzca su contraseña: ");
                                getline(std::cin, contrasenia);
                                printf("\n Introduzca su email: ");
                                getline(std::cin, email);
                                printf("\n Introduzca el URL de su imagen: ");
                                getline(std::cin, imagen);
                                printf("\n Si el usuario a ingresar es docente presione la letra 'd', si es estudiante presione la letra 'e': ");
                                scanf("%s", &letra);
                                if(letra == 'd')
                                    docente = true;
                                else
                                    docente = false;
                                Fabrica *usuario = Fabrica::getInstancia();
                            
                                if(docente){//pregunto si es docnete para saber si muestro los institutos 
                                
                                    printf("\n Seleccione un instituto: ");
                                    printf("\n 1. IMERL");
                                    printf("\n 2. IIE");
                                    printf("\n 3. IA");
                                    printf("\n 4. DISI");
                                    printf("\n 5. IF");
                                    printf("\n 6. INCO");
                                    printf("\n Elija una opcion: ");
                                    char inst;
                                    scanf("%s", &inst);
                                    instituto elegido;
                                    switch(inst) {
                                        case '1': elegido = IMERL;
                                            break;
                                        case '2': elegido = IIE;
                                            break;
                                        case '3': elegido = IA;
                                            break; 
                                        case '4': elegido = DISI;
                                            break;
                                        case '5': elegido = IF;
                                            break;
                                        case '6': elegido = INCO;
                                            break;
                                        default: {
                                            throw std::invalid_argument("Número no válido");
                                            break;
                                        }
                                    }
                                    usuario->getIUsuario()->altaDocente(nombre, email, contrasenia, imagen, elegido);
                            
                                }else{
                                    std::string ci;
                                    cin.ignore();
                                    printf("\n Introduzca su CI: ");
                                    getline(std::cin, ci);
                                    usuario->getIUsuario()->altaEstudiante(nombre, email, contrasenia, imagen, ci);
                                
                                }
                                char letraconf;
                                bool confirmacion = false;
                                printf("\n Desea confirmar s/n: ");
                                scanf("%s", &letraconf);
                                if(letraconf == 's'){
                                    confirmacion = true;
                                    usuario->getIUsuario()->confirmarAltaUsuario(confirmacion);
                                }
                            agregarusuario = true;
                            }else
                                agregarusuario = false;
                            
                        }

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