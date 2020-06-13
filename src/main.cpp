//TODO: incluir coso para imprimir, para excepciones, etc
int main() {
    printf("\n Bienvenido, elija una opcion:");
    int opcion;
    while(opcion != 5){
        printf(
            "\n1. Administrador
            \n2. Docente
            \n3. Estudiante
            \n4. Cargar datos de prueba
            \n5. Salir");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: {// casos de uso de administrador
                printf("\n Elija el caso de uso a ejecutar como Administrador:
                    \n1. Alta de usuario
                    \n2. Alta de asignatura
                    \n3. Eliminacion de asignatura
                    \n4. Asignacion de docentes a una asignatura
                    \n5. Modificar fecha del sistema
                    \n6. Consultar fecha del sistema");
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
                printf("\n Elija el caso de uso a ejecutar como Docente:
                    \n1. Inicio de clase
                    \n2. Finalizacion de clase
                    \n3. Suscribirse a notificacion
                    \n4. Consulta de notificaciones
                    \n5. Tiempo de dictado de clase
                    \n6. Tiempo de asistencia a clase
                    \n7. Envio de mensaje");
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
                printf("\n Elija el caso de uso a ejecutar como Estudiante:
                    \n1. Inscripcion a las asignaturas
                    \n2. Asistencia a clase en vivo
                    \n3. Envio de mensaje
                    \n4. Suscribirse a notificacion
                    \n5. Consulta de notificaciones");
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
                printf("Gracias por usar FingClass, hasta la proxima!");
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