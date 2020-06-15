//TODO: incluir coso para imprimir, para excepciones, etc
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <map>
#include <iterator>
#include "fabrica.h"

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
                        break;
                    }
                    case 3: {
                        break;
                    }
                    case 4: {
                        IAsignatura* ctrl = Fabrica::getIAsignatura();
                        std::map<std::string, DtAsignatura*> x = ctrl->listarAsignaturas();
                        if (x.empty()) break;
                        std::map<std::string, DtAsignatura*>::iterator it;
                        for (it = x.begin(); it != x.end(); it++){
                            std::cout << "(%s, %s)" << it->first, it->second->getNombre();
                        };
                        std::string codigo;
                        std::cin >> codigo;
                        delete[] &x;
                        ctrl->elegirAsignaturaAdmin(codigo);
                        std::set<DtDocente*> z = ctrl->listarDocentes();
                        if (z.empty()) break;
                        std::set<DtDocente*>::iterator it2;
                        for (it2 = z.begin(); it2 != z.end(); it2++){
                            std::cout << "(%s, %s)" << (*it2)->getNombre(), (*it2)->getEmail();
                        }
                        std::string email;
                        int mod;
                        std::cin >> email;
                        printf("\n Elija la modalidad del docente:");
                        printf("\n 1. Teorico");
                        printf("\n 2. Practico");
                        printf("\n 3. Monitoreo");
                        printf("\n");
                        std::cin >> mod;
                        ctrl->elegirdocente(modalidad(mod),email);
                        delete[] &z;
                        bool confi = ctrl->getConfi();
                        ctrl->confirmarAsignacionDocenteAsignatura(confi);
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