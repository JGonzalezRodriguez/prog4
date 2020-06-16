//TODO: incluir coso para imprimir, para excepciones, etc
#include<stdio.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
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
                //Cargar Controladores
                IAsignatura* ctrlA = Fabrica::getIAsignatura();
                IUsuario* ctrlU = Fabrica::getIUsuario();
                IClase* ctrlC = Fabrica::getIClase();
                //Cargar Docentes
                ctrlU->altaDocente("Juan Perez", "juan@mail.com","123","fotito.com/1", instituto(6));
                ctrlU->altaDocente("Maria Pires", "maria@mail.com","1234","fotito.com/2", instituto(6));
                ctrlU->altaDocente("Jorge Chacho", "jorge@mail.com", "passw0rd", "imgur/elChacho", instituto(6));
                //Cargar Estudiantes
                ctrlU->altaEstudiante("Roberto Parra", "roberto@mail.com", "pass", "fotito.com/3", "12345678");
                ctrlU->altaEstudiante("Ana Rodriguez", "ana@mail.com", "p4ss", "fotito.com/4", "23456789");
                ctrlU->altaEstudiante("Ramon Valdez", "ramon@mail.com", "pass", "fotito.com/5", "34567890");
                /*Cargar Asignaturas
                Donde esta altaAsignatura?
                */

                //Asignacion Docente Asignatura
                ctrlA->elegirdocente(modalidad(1), "juan@mail.com");
                ctrlA->elegirAsignaturaAdmin("P1");
                ctrlA->confirmarAsignacionDocenteAsignatura(true);

                ctrlA->elegirdocente(modalidad(2), "maria@mail.com");
                ctrlA->elegirAsignaturaAdmin("P1");
                ctrlA->confirmarAsignacionDocenteAsignatura(true);

                ctrlA->elegirdocente(modalidad(3), "jorge@mail.com");
                ctrlA->elegirAsignaturaAdmin("P1");
                ctrlA->confirmarAsignacionDocenteAsignatura(true);

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