//TODO: incluir coso para imprimir, para excepciones, etc
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include "../include/fabrica.h"
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
                        std::cin.ignore();
                        IAsignatura* ctrl = Fabrica::getIAsignatura();
                        std::map<std::string, DtAsignatura*> x = ctrl->listarAsignaturas();
                        if (x.empty()) break;
                        std::map<std::string, DtAsignatura*>::iterator it;
                        for (it = x.begin(); it != x.end(); it++){
                            std::cout << "%s. %s" << it->first, it->second->getNombre();
                        };
                        std::cout << "\nIngrese el Codigo de la asignatura\n";
                        std::string codigo;
                        std::cin >> codigo;
                        delete[] &x;
                        ctrl->elegirAsignaturaAdmin(codigo);
                        std::set<DtDocente*> z = ctrl->listarDocentes();
                        if (z.empty()) break;
                        std::set<DtDocente*>::iterator it2;
                        for (it2 = z.begin(); it2 != z.end(); it2++){
                            std::cout << "%d. (%s, %s)" <<(*it2), (*it2)->getNombre(), (*it2)->getEmail();
                        }
                        int id = 0;
                        int mod;
                        while (id > std::distance(it2, z.begin()) || id <= 0){
                            std::cout << "\nIngrese el numero del docente deseado.\n";
                            std::cin >> id;
                        }
                        for(int i=1;i<=id;it2++);
                        printf("\n Elija la modalidad del docente:");
                        printf("\n 1. Teorico");
                        printf("\n 2. Practico");
                        printf("\n 3. Monitoreo");
                        printf("\n");
                        std::cin >> mod;
                        ctrl->elegirdocente(modalidad(mod),(*it2)->getEmail());
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
                        // inicio de clase
                        IClase* ctrl = Fabrica::getIClase();
                        std::string email, contrasenia;
                        std::cin.ignore();
                        printf("\n Introduzca su email: ");
                        getline(std::cin, email);
                        printf("\n Introduzca su contrasenia: ");
                        getline(std::cin, contrasenia);
                        ctrl->identificarse(email, contrasenia);
                        std::set<DtAsignatura*> coldtasig = ctrl->listarAsignaturasDocente();
                        for (std::set<DtAsignatura*>::iterator it=coldtasig.begin(); it!=coldtasig.end(); ++it) {
                            std::cout << std::endl << *it;
                        }
                        std::string codigo, nombre;
                        printf("\n Introduzca el codigo de la asignatura de la cual desea iniciar una clase: ");
                        getline(std::cin, codigo);
                        printf("\n Introduzca el nombre que tendra la clase que va a iniciar: ");
                        getline(std::cin, nombre);
                        ctrl->inicioDeClase(codigo, nombre);
                        modalidad mod = ctrl->getModalidad();
                        if (mod == monitoreo) {
                            int cant = 0;
                            char letraselec;
                            printf("\n Desea agregar un nuevo estudiante al monitoreo? s/n: ");
                            scanf("%s", &letraselec);
                            while (cant < 15 && letraselec == 's') {
                                std::set<DtEstudiante*> coldtest= ctrl->listarEstudiantesHabilitados();

                                for (std::set<DtEstudiante*>::iterator it=coldtest.begin(); it!=coldtest.end(); ++it) {
                                    std::cout << std::endl << *it;
                                }

                                printf("\n Introduzca la CI del estudiante al que desea agregar: ");
                                std::string CI;
                                getline(std::cin, CI);
                                ctrl->elegirEstudiante(CI);
                                printf("\n Desea agregar un nuevo estudiante al monitoreo? s/n: ");
                                scanf("%s", &letraselec);
                                cant++;
                            }    
                        }
                        DtClase* preview = ctrl->mostrarDatos();
                        std::cout << std::endl << *preview;

                        printf("\n Desea confirmar s/n: ");
                        char letraconf;
                        scanf("%s", &letraconf);
                        bool confirmacion = letraconf == 's';
                        ctrl->confirmarInicioDeClase(confirmacion);
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