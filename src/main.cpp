//TODO: incluir coso para imprimir, para excepciones, etc
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include "../include/fabrica.h"
#include "../include/reloj.h"
#include <map>
#include <iterator>

using namespace std;
int main() {
    printf("\nBienvenide a FingClass, elija una opcion:");
    printf("\n");
    int opcion;
    while(opcion != 5){
    try {
        printf("\n1. Administrador");
        printf("\n2. Docente");
        printf("\n3. Estudiante");
        printf("\n4. Cargar datos de prueba");
        printf("\n5. Salir");
        printf("\n\n");
            
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
                        Fabrica *f = Fabrica::getInstancia();
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
                                    f->getIUsuario()->altaDocente(nombre, email, contrasenia, imagen, elegido);
                            
                                }else{
                                    std::string ci;
                                    cin.ignore();
                                    printf("\n Introduzca su CI: ");
                                    getline(std::cin, ci);
                                    f->getIUsuario()->altaEstudiante(nombre, email, contrasenia, imagen, ci);
                                
                                }
                                char letraconf;
                                bool confirmacion = false;
                                printf("\n Desea confirmar s/n: ");
                                scanf("%s", &letraconf);
                                if(letraconf == 's'){
                                    confirmacion = true;
                                    f->getIUsuario()->confirmarAltaUsuario(confirmacion);
                                }
                            agregarusuario = true;
                            }else
                                agregarusuario = false;
                                
                        }
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
                        if (mon == 's'){
                            tienemon = true;
                        }else if (mon == 'n'){
                            tienemon = false;
                        }else{
                            throw std::invalid_argument("\nRepuesta no valida, debe ingresar 's' o 'n'.\n");
                        }
                        //creando asignatura
                        Fabrica* fabrica = Fabrica::getInstancia(); //esto va a explotar cuando santi suba la fabrica nueva que es singleton
                        IAsignatura* interface = fabrica->getIAsignatura();
                        interface->altaAsignatura(nombre, codigo, tieneteo, tieneprac, tienemon);
                        DtAsignatura* asignatura = interface->mostrarDatosAsignatura();
                        cout << *asignatura;
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
                        interface->confirmarAltaAsignatura(bConf);
                        delete asignatura;
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
                        //////////MODIFICAR FECHA DEL SISTEMA////////////
                        int anio, mes, dia, min, hora;
                        printf("\nIngrese el año deseado\n");
                        scanf("%d", &anio);
                        printf("\nIngrese el mes deseado\n");
                        scanf("%d", &mes);
                        printf("\nIngrese el dia deseado\n");
                        scanf("%d", &dia);
                        printf("\nIngrese la hora deseada\n");
                        scanf("%d", &hora);
                        printf("\nIngrese el minuto deseado\n");
                        scanf("%d", &min);
                        Reloj* reloj = Reloj::getInstancia();
                        DtFecha* fecha = new DtFecha(dia, mes, anio, hora, min);
                        reloj->setFecha(fecha);
                        printf("\nFecha ingresada con exito. El tiempo de sistema es el siguiente:\n");
                        std::cout << *fecha;
                        break;
                    }
                    case 6: {
                        //////////CONSULTAR FECHA DEL SISTEMA////////////
                        Reloj* reloj = Reloj::getInstancia();
                        DtFecha* fecha = reloj->getFecha();
                        printf("\nEl tiempo de sistema es el siguiente:\n");
                        std::cout << *fecha;
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
                        cin.ignore();
                        std::string email, contrasenia;
                        printf("\nIntroduzca su email: ");
                        getline(std::cin, email);
                        printf("\nIntroduzca su contraseña: ");
                        getline(std::cin, contrasenia);
                        Fabrica *asignatura = Fabrica::getInstancia();
                        //se identifica el estudiante
                        asignatura->getIAsignatura()->identificarse(email, contrasenia);
                        bool inscribirse = false;
                        if(asignatura->getIAsignatura()->getIdentificado())
                            inscribirse = true;
                        else{
                            printf("\nEl email o la contraseña son incorrectos");
                            printf("\n");
                        }
                        
                        while(inscribirse){
                            char letraselec;
                            printf("\nDesea inscribirse a una nueva asignatura? s/n: ");
                            scanf("%s", &letraselec);
                            if(letraselec == 's'){
                                std::set<DtAsignatura*> lista = asignatura->getIAsignatura()->listarAsignaturasEstudiante();
                                std::set<DtAsignatura*>::iterator it;
                                for(it = lista.begin(); it != lista.end(); ++it){
                                    cout << endl << **it;
                                }
                                std::string codigo;
                                cin.ignore();
                                printf("\nIntroduzca el código de la asignatura que desee inscribirse: ");
                                getline(std::cin, codigo);
                                asignatura->getIAsignatura()->elegirAsignaturaEst(codigo);
                                if(!asignatura->getIAsignatura()->getCodigovalido()){
                                    printf("\nLo sentimos el código introducido no es válido");
                                    printf("\n");
                                    break;
                                }
                                
                                
                                char letraconf;
                                bool confirmacion = false;
                                printf("\nDesea confirmar s/n: ");
                                scanf("%s", &letraconf);
                                if(letraconf == 's'){
                                    confirmacion = true;
                                    asignatura->getIAsignatura()->confirmarInscripcionAsignatura(confirmacion);
                                }
                            }else
                            {
                                inscribirse = false;
                            }
                            
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
                    default: {
                        throw std::invalid_argument("Opcion no valida");
                        break;
                    }
                }
                break;
            }
            case 4: {
             
                //Cargar Controladores
                Fabrica* f = Fabrica::getInstancia();
                IAsignatura* ctrlA = f->getIAsignatura();
                IUsuario* ctrlU = f->getIUsuario();
                //IAsignatura* ctrlA = Fabrica::getIAsignatura();
                //IUsuario* ctrlU = Fabrica::getIUsuario();
                //IClase* ctrlC = Fabrica::getIClase();
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
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        //atrapa el invalid argument y lo imprime, evitando que termine el programa.
    }
    }
    return 0;
}
