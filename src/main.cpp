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
//para envio mensaje hacemos un metodo porque se llama en dos casos en docentes (7) y en estudiantes (3)
void envioMensaje(){
    Fabrica* fabrica = Fabrica::getInstancia();
    IMensaje* interface = fabrica->getIMensaje();
    std::string email, contrasenia, id, idMensaje, texto;
    printf("\n Introduzca su email: ");
    std::cin.ignore(1);
    getline(std::cin, email);
    printf("\n Introduzca su contrasenia: ");
    getline(std::cin, contrasenia);
    interface->identificarse(email, contrasenia);
    std::set<DtClase*> clases = interface->listarClases();
    printf("\nListando clases disponibles:\n");
    printf("\n------------------------------\n");
    for (std::set<DtClase*>::iterator it=clases.begin(); it!=clases.end(); ++it){
        DtClase* c = *it;
        std::cout << *c;
        printf("\n------------------------------\n");
    }
    printf("\nIngrese el ID de la clase en la cual desea escribir un mensaje: ");
    getline(std::cin, id);
    interface->elegirClase(id);
    std::set<DtMensaje*> msjs = interface->listarMensajes(); //solo agarra los mensajes raiz para que luego recursivePrint no repita mensajes
    printf("\nListando los mensajes de la clase:\n");
    printf("\n------------------------------\n");
    for (std::set<DtMensaje*>::iterator it=msjs.begin(); it!=msjs.end(); ++it){
        DtMensaje* msj = *it;
        msj->recursivePrint(0);
    }
    printf("\nDesea responder a algún mensaje existente? s/n\n");
    char letra;
    scanf("%s", &letra);
    if (letra != 's' && letra != 'n'){
        throw std::invalid_argument("Respuesta no válida, debe escribir 's' o 'n'");
    }
    std::cin.ignore(1);
    if (letra == 's'){
        printf("\nIngrese el ID del mensaje al cual desea responder: ");
        getline(std::cin, idMensaje);
        interface->seleccionarMensaje(idMensaje);
    }
    printf("\nIngrese el contenido de su mensaje:\n");
    getline(std::cin, texto);
    interface->textoEnviar(texto);
    printf("\nConfirmar envio de mensaje? s/n\n");
    scanf("%s", &letra);
    if (letra != 's' && letra != 'n'){
        throw std::invalid_argument("Respuesta no válida, debe escribir 's' o 'n'");
    }
    bool conf = false;
    if (letra == 's'){
        conf = true;
    }
    interface->confirmarEnvioMensaje(conf);
}
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
                printf("\n7. Tiempo de dictado de clase");
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
                        DtAsignaturaExt* asignatura = interface->mostrarDatosAsignatura();
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
                        std::cin.ignore();
                        Fabrica* f = Fabrica::getInstancia();
                        IAsignatura* ctrlA = f->getIAsignatura();
                        std::set<DtAsignatura*> asignaturas = ctrlA->listarAsignaturas();
                        std::set<DtAsignatura*>::iterator it;
                        for(it=asignaturas.begin(); it != asignaturas.end(); it++) {
                            std::cout << *(*it) << endl;
                        }
                        std::string id;
                        printf("Por favor ingrese el codigo de la asignatura a eliminar:\n");
                        std::cin >> id;
                        ctrlA->elegirAsignaturaAdmin(id);
                        printf("Desea eliminar asignatura?");
                        printf("\n1. Si");
                        printf("\n2. No\n");
                        int i;
                        std::cin >> i;
                        ctrlA->confirmarEliminacionAsignatura(!(i-1));
                        break;
                    }
                    case 4: {
                        bool asignar = true;
                        while(asignar){
                            char letraselec;
                            printf("\n Desea asignar un docente a una asignatura? s/n: ");
                            scanf("%s", &letraselec);
                            if(letraselec == 's'){
                                std::cin.ignore();
                                Fabrica* ctrl = Fabrica::getInstancia();
                                std::set<DtAsignatura*> x = ctrl->getIAsignatura()->listarAsignaturas();
                                if (x.empty()) break;
                                std::set<DtAsignatura*>::iterator it;
                                for (it = x.begin(); it != x.end(); it++){
                                    std::cout << **it;
                                };
                                std::cout << "\nIngrese el Codigo de la asignatura\n";
                                std::string codigo;
                                std::cin >> codigo;
                                //delete[] &x;
                                ctrl->getIAsignatura()->elegirAsignaturaAdmin(codigo);
                                ctrl->getIAsignatura()->imprimirModalidad();
                                printf("\nDocentes no asignados: ");
                                printf("\n");

                                std::set<DtDocente*> z = ctrl->getIAsignatura()->listarDocentes();
                                if (z.empty()) break;
                                std::set<DtDocente*>::iterator it2;
                                for (it2 = z.begin(); it2 != z.end(); it2++){
                                    //std::cout << "%d. (%s, %s)" <<(*it2), (*it2)->getNombre(), (*it2)->getEmail();
                                    cout << **it2;
                                }
                                
                                std::string email;
                                std::cout << "\nIngrese el email del docente deseado.\n";
                                cin.ignore();
                                getline(std::cin, email);
                                printf("\n Elija la modalidad del docente:");
                                printf("\n 1. Teórico");
                                printf("\n 2. Práctico");
                                printf("\n 3. Monitoreo");
                                printf("\n Elija una opcion: ");
                                char inst;
                                scanf("%s", &inst);
                                modalidad mod;
                                
                                switch(inst) {
                                    case '1': mod = teorico;
                                        break;
                                    case '2': mod = practico;
                                        break;
                                    case '3': mod = monitoreo;
                                        break; 
                    
                                    default: {
                                        throw std::invalid_argument("Número no válido");
                                        break;    
                                    }
                                }
                                if(ctrl->getIAsignatura()->tieneAsignaturaMod(mod)){
                                ctrl->getIAsignatura()->elegirdocente(mod,email);
                                //delete[] &z;
                                bool confi = ctrl->getIAsignatura()->getConfi();
                                ctrl->getIAsignatura()->confirmarAsignacionDocenteAsignatura(confi);
                                }else{
                                    printf("\nLo sentimos, la asignatura seleccionada no posee tal modalidad");
                                    printf("\n");

                                }
                            }else
                            {
                                asignar = false;
                            }
                            
                        }
                        break;
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
                    case 7:{
                        //TIEMPO DE DICTADO DE CLASE//
                        Fabrica *ctrl = Fabrica::getInstancia();
                        std::set<DtTiempoAsignatura*> colec = ctrl->getIClase()->tiempoDictadoClases();
                        std::set<DtTiempoAsignatura*>::iterator it;
                        for(it = colec.begin(); it != colec.end(); ++it){
                            cout << **it;
                        }

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
                printf("\n5. Tiempo de asistencia a clase");
                printf("\n6. Envio de mensaje");
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
                            std::cout << std::endl << *(*it);
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
                            while (cant < 15 && letraselec == 's') { // ESTE LISTAR NO DEBERIA LISTAR LOS YA ELEGIDOS
                                std::set<DtEstudiante*> coldtest= ctrl->listarEstudiantesHabilitados();

                                for (std::set<DtEstudiante*>::iterator it=coldtest.begin(); it!=coldtest.end(); ++it) {
                                    std::cout << std::endl << **it;
                                }

                                printf("\n Introduzca la CI del estudiante al que desea agregar: ");
                                std::string CI;
                                cin.ignore();
                                getline(std::cin, CI);
                                ctrl->elegirEstudiante(CI);
                                printf("\n Desea agregar un nuevo estudiante al monitoreo? s/n: ");
                                scanf("%s", &letraselec);
                                cant++;
                            }    
                        }
                        DtPreview* preview = ctrl->mostrarDatos();
                        std::cout << std::endl << *preview << std::endl;
                        // LUEGO DEL PREVIEW SE DEBERIA LISTAR LOS ESTUDIANTES ELEGIDOS
                        if (mod == monitoreo) {
                            std::cout  << "Estudiantes elegidos: " << std::endl;
                            std::set<DtEstudiante*> setest = (*preview).getEstudiantes();
                            for (std::set<DtEstudiante*>::iterator it=setest.begin(); it!=setest.end(); ++it) {
                                DtEstudiante* dtest = *it;
                                std::cout << std::endl << *dtest << std::endl;
                            }
                        }
                        
                        printf("\n Desea confirmar s/n: ");
                        char letraconf;
                        scanf("%s", &letraconf);
                        bool confirmacion = letraconf == 's';
                        ctrl->confirmarInicioDeClase(confirmacion);
                        break;
                    }
                    case 2: {
                        // --- finalizacion de clase ---
                        IClase* ctrl = Fabrica::getIClase();
                        std::string email, contrasenia;
                        std::cin.ignore();
                        printf("\n Introduzca su email: ");
                        getline(std::cin, email);
                        printf("\n Introduzca su contrasenia: ");
                        getline(std::cin, contrasenia);
                        ctrl->identificarse(email, contrasenia);
                        std::set<DtPreview*> coldtpreview = ctrl->listarClasesEnVivo();
                        for (std::set<DtPreview*>::iterator it=coldtpreview.begin(); it!=coldtpreview.end(); ++it) {
                            std::cout << std::endl << **it << std::endl;
                        }
                        printf("\n Introduzca el id de la clase que desea finalizar: ");
                        std::string id;
                        getline(std::cin, id);
                        ctrl->elegirClase(id);
                        std::cout << std::endl << *(ctrl->mostrarClase()) << std::endl;
                        printf("\n Desea confirmar la finalizacion de esta clase? s/n: ");
                        char letraselec;
                        scanf("%s", &letraselec);
                        if (letraselec == 's') {
                            ctrl->confirmarFinalizacionDeClase(true);
                        }
                        break;
                    }
                    case 3: {
                        cin.ignore();
                        std::string email, contrasenia;
                        printf("\nIntroduzca su email: ");
                        getline(std::cin, email);
                        printf("\nIntroduzca su contraseña: ");
                        getline(std::cin, contrasenia);
                        Fabrica *ctrl = Fabrica::getInstancia();
                        //se identifica el estudiante
                        ctrl->getISubscripcion()->identificarse(email, contrasenia);
                        
                        if(ctrl->getISubscripcion()->getIdentifico()){
                            ctrl->getISubscripcion()->elegirModo();
                            printf("\nHa quedado suscrito al modo respuesta a un usuario");
                            printf("\n");
                        }else{
                            printf("\nEl email o la contraseña son incorrectos");
                            printf("\n");
                        }
                        

                        break;
                    }
                    case 4: {
                        // consulta de notificaciones ---------
                        cin.ignore();
                        std::string email, contrasenia;
                        printf("\nIntroduzca su email: ");
                        getline(std::cin, email);
                        printf("\nIntroduzca su contraseña: ");
                        getline(std::cin, contrasenia);
                        Fabrica* f = Fabrica::getInstancia();
                        //se identifica el estudiante
                        ISubscripcion* ctrl = f->getISubscripcion();
                        ctrl->identificarse(email, contrasenia);
                        
                        if(ctrl->getIdentifico()){    
                            std::set<DtNotificacion*> coldtnot = ctrl->listarNotificaciones();
                            printf("\nNotificaciones: ");
                            printf("\n-------------------------------\n");
                            for (std::set<DtNotificacion*>::iterator it=coldtnot.begin(); it!=coldtnot.end(); ++it) {
                                std::cout << std::endl << **it << "-------------------------------";
                            }

                            ctrl->eliminarNotificaciones();

                        }else{
                            printf("\nEl email o la contraseña son incorrectos");
                            printf("\n");
                        }

                        break;
                    }
                   
                    case 5: {
                        // tiempo asistencia asignatura
                        cin.ignore();
                        std::string email, contrasenia;
                        printf("\nIntroduzca su email: ");
                        getline(std::cin, email);
                        printf("\nIntroduzca su contraseña: ");
                        getline(std::cin, contrasenia);
                        Fabrica* f = Fabrica::getInstancia();
                        //se identifica el estudiante
                        IClase* ctrl = f->getIClase();
                        ctrl->identificarse(email, contrasenia);
                        std::set<DtAsignatura*> coldtasig = ctrl->listarAsignaturasDocente();
                        for (std::set<DtAsignatura*>::iterator it=coldtasig.begin(); it!=coldtasig.end(); ++it) {
                                std::cout << std::endl << **it << std::endl;
                        }
                        printf("\nInserte el codigo de la asignatura cuyos tiempos de asistencia en promedio desea ver: ");
                        std::string codigo;
                        getline(std::cin, codigo);
                        ctrl->elegirAsignaturaDoc(codigo);
                        std::set<DtPromAsistencia*> coldtprom = ctrl->promedioAsistencia();
                        for (std::set<DtPromAsistencia*>::iterator it=coldtprom.begin(); it!=coldtprom.end(); ++it) {
                                std::cout << std::endl << **it << std::endl;
                        }
                        break;
                    }
                    case 6: {
                        envioMensaje();
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
                printf("\n1. Inscripción a las asignaturas");
                printf("\n2. Asistencia a clase en vivo");
                printf("\n3. Envio de mensaje");
                printf("\n4. Suscribirse a notificacion");
                printf("\n5. Consulta de notificaciones");
                printf("\n6. Finalizar asistencia a clase en vivo");
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

                        cin.ignore();
                        Fabrica* f = Fabrica::getInstancia();
                        IReproduccion* ctrlR = f->getIReproduccion();
                        std::string email, contrasenia;
                        printf("\nIntroduzca su email: ");
                        getline(std::cin, email);
                        printf("\nIntroduzca su contraseña: ");
                        getline(std::cin, contrasenia);
                        //se identifica el estudiante
                        if (!ctrlR->identificarse(email, contrasenia)) break;
                        //lista asignaturas a las que el estudiante esta inscripto
                        printf("Estas son las asignaturas a las que esta inscripto:\n\n");
                        std::set<DtAsignatura*> lista = ctrlR->listarAsignaturasEstudiante();
                        if (lista.empty()) {
                            printf("Usted no esta cursando ninguna asignatura");
                            break;
                        };
                        std::set<DtAsignatura*>::iterator it;
                        for(it = lista.begin(); it != lista.end(); ++it){
                            cout << **it;
                        }

                        std::string codigo;
                        std::cout << "\nIntroduzca el codigo de la asignatura a la que desea asistir:";
                        std::cin >> codigo;
                        ctrlR->elegirAsignaturaEst(codigo);
                        std::set<DtClase*> x = ctrlR->listarClasesEstudiante();
                        if (x.empty()) { 
                            break;
                        };
                        std::set<DtClase*>::iterator it2;
                        for(it2 = x.begin(); it2 != x.end(); it2++){
                            cout << endl << **it2;
                        }
                        std::string id;
                        std::cout << endl << "Introduzca el id de la clase a la que desea asistir:";
                        std::cin >> id;
                        ctrlR->elegirClase(id);
                        if (ctrlR->mostrarDatosClase() == NULL) {
                            printf("No hay clase asociada a ese id");
                            break;
                        }
                        std::cout << "Desea Asistir a la siguiente clase?\n\n" << *(ctrlR->mostrarDatosClase());
                        std::cout << endl;
                        std::cout << "1. Si \n2. No\n";
                        
                        int i;
                        std::cin >> i;
                        bool confi = !(i-1);
                        ctrlR->confirmarAsistenciaClaseEnVivo(confi);                      
                        break;
                    }
                    case 3: {
                        envioMensaje();
                        break;
                    }
                    case 4: {
                        cin.ignore();
                        std::string email, contrasenia;
                        printf("\nIntroduzca su email: ");
                        getline(std::cin, email);
                        printf("\nIntroduzca su contraseña: ");
                        getline(std::cin, contrasenia);
                        Fabrica *ctrl = Fabrica::getInstancia();
                        //se identifica el estudiante
                        ctrl->getISubscripcion()->identificarse(email, contrasenia);
                        
                        if(ctrl->getISubscripcion()->getIdentifico()){
                            ctrl->getISubscripcion()->elegirModo();
                            printf("\nHa quedado suscrito al modo respuesta a un usuario");
                            printf("\n");
                        }else{
                            printf("\nEl email o la contraseña son incorrectos");
                            printf("\n");
                        }
                        

                        break;
                    }
                    case 5: {
                        // consulta de notificaciones ---------
                        cin.ignore();
                        std::string email, contrasenia;
                        printf("\nIntroduzca su email: ");
                        getline(std::cin, email);
                        printf("\nIntroduzca su contraseña: ");
                        getline(std::cin, contrasenia);
                        Fabrica* f = Fabrica::getInstancia();
                        //se identifica el estudiante
                        ISubscripcion* ctrl = f->getISubscripcion();
                        ctrl->identificarse(email, contrasenia);
                        
                        if(ctrl->getIdentifico()){    
                            std::set<DtNotificacion*> coldtnot = ctrl->listarNotificaciones();
                            printf("\nNotificaciones: ");
                            printf("\n-------------------------------\n");
                            for (std::set<DtNotificacion*>::iterator it=coldtnot.begin(); it!=coldtnot.end(); ++it) {
                                std::cout << std::endl << **it << "-------------------------------";
                            }

                            ctrl->eliminarNotificaciones();

                        }else{
                            printf("\nEl email o la contraseña son incorrectos");
                            printf("\n");
                        }
                        break;
                    }
                    case 6: {
                        cin.ignore();
                        Fabrica* f = Fabrica::getInstancia();
                        IReproduccion* ctrlR = f->getIReproduccion();
                        std::string email, contrasenia;
                        printf("\nIntroduzca su email: ");
                        getline(std::cin, email);
                        printf("\nIntroduzca su contraseña: ");
                        getline(std::cin, contrasenia);
                        //se identifica el estudiante
                        if (!ctrlR->identificarse(email, contrasenia)) break;
                        if (!ctrlR->estaAsistiendo()) {
                            printf("Usted no esta asistiendo a ninguna clase");
                            break;
                        }
                        std::set<DtClase*> x = ctrlR->listarClasesEstudianteVivo();
                        std::set<DtClase*>::iterator it2;
                        for(it2 = x.begin(); it2 != x.end(); it2++){
                            cout << endl << **it2;
                        }
                        std::string id;
                        std::cout << endl << "Introduzca el id de la clase a la que desea finalizar su asistencia:";
                        std::cin >> id;
                        ctrlR->elegirClase(id);
                        if (ctrlR->mostrarDatosClase() == NULL) {
                            printf("No hay clase asociada a ese id");
                            break;
                        }
                        std::cout << "Desea finalizar su asistencia a la siguiente clase?\n\n" << *(ctrlR->mostrarDatosClase());
                        std::cout << endl;
                        std::cout << "1. Si \n2. No\n";

                        int i;
                        std::cin >> i;
                        bool confi = !(i-1);
                        ctrlR->confirmarFinalizacionAsistencia(confi);                      
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
                IClase *ctrlC = f->getIClase();
                IReproduccion *ctrlR = f->getIReproduccion();
                IMensaje *ctrlM = f->getIMensaje();
                
                //IAsignatura* ctrlA = Fabrica::getIAsignatura();
                //IUsuario* ctrlU = Fabrica::getIUsuario();
                //IClase* ctrlC = Fabrica::getIClase();
                //Cargar Docentes

                ctrlU->altaDocente("Juan Perez", "juan@mail.com","123","fotito.com/1", instituto(5));
                ctrlU->confirmarAltaUsuario(true);
                ctrlU->altaDocente("Maria Pires", "maria@mail.com","1234","fotito.com/2", instituto(5));
                ctrlU->confirmarAltaUsuario(true);
                ctrlU->altaDocente("Jorge Chacho", "jorge@mail.com", "passw0rd", "imgur/elChacho", instituto(5));
                ctrlU->confirmarAltaUsuario(true);
                //Cargar Estudiantes
                ctrlU->altaEstudiante("Roberto Parra", "roberto@mail.com", "pass", "fotito.com/3", "12345678");
                ctrlU->confirmarAltaUsuario(true);
                ctrlU->altaEstudiante("Ana Rodriguez", "ana@mail.com", "pass", "fotito.com/4", "23456789");
                ctrlU->confirmarAltaUsuario(true);
                ctrlU->altaEstudiante("Ramon Valdez", "ramon@mail.com", "pass", "fotito.com/5", "34567890");
                ctrlU->confirmarAltaUsuario(true);
                //Cargar Asignaturas
                ctrlA->altaAsignatura("Programacion 1", "P1", true, true, true);
                ctrlA->confirmarAltaAsignatura(true);
                ctrlA->altaAsignatura("Programacion 2", "P2", true, true, true);
                ctrlA->confirmarAltaAsignatura(true);
                ctrlA->altaAsignatura("Programacion 3", "P3", true, true, false);
                ctrlA->confirmarAltaAsignatura(true);
                //Asignacion Docente Asignatura
                ctrlA->elegirAsignaturaAdmin("P1");
                ctrlA->elegirdocente(teorico, "juan@mail.com");
                ctrlA->confirmarAsignacionDocenteAsignatura(true);

                ctrlA->elegirAsignaturaAdmin("P1");
                ctrlA->elegirdocente(practico, "maria@mail.com");
                ctrlA->confirmarAsignacionDocenteAsignatura(true);

                ctrlA->elegirAsignaturaAdmin("P1");
                ctrlA->elegirdocente(monitoreo, "jorge@mail.com");
                ctrlA->confirmarAsignacionDocenteAsignatura(true);

                ctrlA->identificarse("roberto@mail.com","pass");
                ctrlA->elegirAsignaturaEst("P1");
                ctrlA->confirmarInscripcionAsignatura(true);

                ctrlA->identificarse("ana@mail.com","pass");
                ctrlA->elegirAsignaturaEst("P1");
                ctrlA->confirmarInscripcionAsignatura(true);
                ctrlA->elegirAsignaturaEst("P2");
                ctrlA->confirmarInscripcionAsignatura(true);

                ctrlA->identificarse("ramon@mail.com","pass");
                ctrlA->elegirAsignaturaEst("P1");
                ctrlA->confirmarInscripcionAsignatura(true);

                //CLASES
                Reloj* reloj = Reloj::getInstancia();
                //para iniciar C1
                ctrlC->identificarse("juan@mail.com", "123");
                DtFecha* fecha1 = new DtFecha(1, 5, 2020, 9, 0);
                reloj->setFecha(fecha1);
                ctrlC->inicioDeClase("P1", "Intro");
                ctrlC->confirmarInicioDeClase(true);
                std::string id1 = ctrlC->getIdgenerado();

                //E1 para asistir a C1
                ctrlR->identificarse("roberto@mail.com", "pass");
                ctrlR->elegirAsignaturaEst("P1");
                ctrlR->elegirClase(id1);
                DtFecha* fecha13 = new DtFecha(1, 5, 2020, 9, 1);
                reloj->setFecha(fecha13);
                ctrlR->confirmarAsistenciaClaseEnVivo(true);
                

                //E2 para asistir C1
                ctrlR->identificarse("ana@mail.com", "pass");
                ctrlR->elegirAsignaturaEst("P1");
                ctrlR->elegirClase(id1);
                DtFecha* fecha15 = new DtFecha(1, 5, 2020, 9, 2);
                reloj->setFecha(fecha15);
                ctrlR->confirmarAsistenciaClaseEnVivo(true);
                

                //E3 para asistir a C1
                ctrlR->identificarse("ramon@mail.com", "pass");
                ctrlR->elegirAsignaturaEst("P1");
                ctrlR->elegirClase(id1);
                DtFecha* fecha17 = new DtFecha(1, 5, 2020, 9, 3);
                reloj->setFecha(fecha17);
                ctrlR->confirmarAsistenciaClaseEnVivo(true);
                

                //MENSAJES

                //los id de los mensajes comienza en 1
                ctrlM->identificarse("juan@mail.com","123");
                ctrlM->elegirClase(id1);
                ctrlM->textoEnviar("Bienvenidos!");
                DtFecha* fecha21 = new DtFecha(1, 5, 2020, 9, 1);
                reloj->setFecha(fecha21);
                ctrlM->confirmarEnvioMensaje(true);
                //-----------------------------------------
                ctrlM->identificarse("juan@mail.com","123");
                ctrlM->elegirClase(id1);
                ctrlM->textoEnviar("Confirmen materiales por favor.");
                DtFecha* fecha22 = new DtFecha(1, 5, 2020, 9, 2);
                reloj->setFecha(fecha22);
                ctrlM->confirmarEnvioMensaje(true);
                //-----------------------------------------
                ctrlM->identificarse("roberto@mail.com","pass");
                ctrlM->elegirClase(id1);
                ctrlM->seleccionarMensaje(to_string(1));
                ctrlM->textoEnviar("Listo para aprender.");
                DtFecha* fecha24 = new DtFecha(1, 5, 2020, 9, 5);
                reloj->setFecha(fecha24);
                ctrlM->confirmarEnvioMensaje(true);
                //-----------------------------------------
                ctrlM->identificarse("juan@mail.com","123");
                ctrlM->elegirClase(id1);
                ctrlM->seleccionarMensaje(to_string(3));
                ctrlM->textoEnviar("Me alegro");
                DtFecha* fecha25 = new DtFecha(1, 5, 2020, 9, 6);
                reloj->setFecha(fecha25);
                ctrlM->confirmarEnvioMensaje(true);
                //-----------------------------------------
                ctrlM->identificarse("ana@mail.com","pass");
                ctrlM->elegirClase(id1);
                ctrlM->seleccionarMensaje(to_string(2));
                ctrlM->textoEnviar("Todo listo");
                DtFecha* fecha26 = new DtFecha(1, 5, 2020, 9, 6);
                reloj->setFecha(fecha26);
                ctrlM->confirmarEnvioMensaje(true);
                //-----------------------------------------
                //para finalizar asistencia de E1
                ctrlR->identificarse("roberto@mail.com", "pass");
                ctrlR->elegirClase(id1);
                DtFecha* fecha14 = new DtFecha(1, 5, 2020, 9, 21);
                reloj->setFecha(fecha14);
                ctrlR->confirmarFinalizacionAsistencia(true);

                //para finalizar asistencia de E2
                ctrlR->identificarse("ana@mail.com", "pass");
                ctrlR->elegirClase(id1);
                DtFecha* fecha16 = new DtFecha(1, 5, 2020, 9, 32);
                reloj->setFecha(fecha16);
                ctrlR->confirmarFinalizacionAsistencia(true);

                //para finalizar asistencia E3
                ctrlR->identificarse("ramon@mail.com", "pass");
                ctrlR->elegirClase(id1);
                DtFecha* fecha18 = new DtFecha(1, 5, 2020, 9, 43);
                reloj->setFecha(fecha18);
                ctrlR->confirmarFinalizacionAsistencia(true);

                
                //para finalizar C1
                ctrlC->identificarse("juan@mail.com", "123");
                DtFecha* fecha2 = new DtFecha(1, 5, 2020, 10, 0);
                reloj->setFecha(fecha2);
                ctrlC->elegirClase(id1);
                ctrlC->confirmarFinalizacionDeClase(true);
                //-----------------------------------------
                
                //para iniciar
                ctrlC->identificarse("juan@mail.com", "123");
                DtFecha* fecha3 = new DtFecha(3, 5, 2020, 9, 0);
                reloj->setFecha(fecha3);
                ctrlC->inicioDeClase("P1", "Tema1");
                ctrlC->confirmarInicioDeClase(true);
                std::string id2 = ctrlC->getIdgenerado();
                //para finalizar
                ctrlC->identificarse("juan@mail.com", "123");
                DtFecha* fecha4 = new DtFecha(3, 5, 2020, 10, 0);
                reloj->setFecha(fecha4);
                ctrlC->elegirClase(id2);
                ctrlC->confirmarFinalizacionDeClase(true);
                //-----------------------------------------
                //para iniciar
                ctrlC->identificarse("juan@mail.com", "123");
                DtFecha* fecha5 = new DtFecha(8, 5, 2020, 9, 0);
                reloj->setFecha(fecha5);
                ctrlC->inicioDeClase("P1", "Tema2");
                ctrlC->confirmarInicioDeClase(true);
                std::string id3 = ctrlC->getIdgenerado();
                //para finalizar
                ctrlC->identificarse("juan@mail.com", "123");
                DtFecha* fecha6 = new DtFecha(8, 5, 2020, 10, 0);
                reloj->setFecha(fecha6);
                ctrlC->elegirClase(id3);
                ctrlC->confirmarFinalizacionDeClase(true);
                //-----------------------------------------
                //para iniciar
                ctrlC->identificarse("maria@mail.com", "1234");
                DtFecha* fecha7 = new DtFecha(2, 5, 2020, 16, 0);
                reloj->setFecha(fecha7);
                ctrlC->inicioDeClase("P1", "Pra1");
                ctrlC->confirmarInicioDeClase(true);
                std::string id4 = ctrlC->getIdgenerado();
                //para finalizar
                ctrlC->identificarse("maria@mail.com", "1234");
                DtFecha* fecha8 = new DtFecha(2, 5, 2020, 17, 0);
                reloj->setFecha(fecha8);
                ctrlC->elegirClase(id4);
                ctrlC->confirmarFinalizacionDeClase(true);
                //-----------------------------------------
                //para iniciar
                ctrlC->identificarse("maria@mail.com", "1234");
                DtFecha* fecha9 = new DtFecha(3, 5, 2020, 16, 0);
                reloj->setFecha(fecha9);
                ctrlC->inicioDeClase("P1", "Pra2");
                ctrlC->confirmarInicioDeClase(true);
                std::string id5 = ctrlC->getIdgenerado();
                //para finalizar
                ctrlC->identificarse("maria@mail.com", "1234");
                DtFecha* fecha10 = new DtFecha(3, 5, 2020, 17, 0);
                reloj->setFecha(fecha10);
                ctrlC->elegirClase(id5);
                ctrlC->confirmarFinalizacionDeClase(true);
                //-----------------------------------------
                
                //para iniciar C6
                ctrlC->identificarse("jorge@mail.com", "passw0rd");
                DtFecha* fecha11 = new DtFecha(4, 5, 2020, 16, 0);
                reloj->setFecha(fecha11);
                ctrlC->inicioDeClase("P1", "06/01/20");
                //Estudiantes habilitados
                ctrlC->elegirEstudiante("23456789");
                ctrlC->elegirEstudiante("34567890");
                ctrlC->confirmarInicioDeClase(true);
                std::string id6 = ctrlC->getIdgenerado();

                //E3 para asistir C6
                ctrlR->identificarse("ramon@mail.com", "pass");
                ctrlR->elegirAsignaturaEst("P1");
                ctrlR->elegirClase(id6);
                DtFecha* fecha19 = new DtFecha(4, 5, 2020, 16, 0);
                reloj->setFecha(fecha19);
                ctrlR->confirmarAsistenciaClaseEnVivo(true);
                

                //MENSAJES
                
                ctrlM->identificarse("jorge@mail.com","passw0rd");
                ctrlM->elegirClase(id6);
                ctrlM->textoEnviar("Comparto pantalla.");
                DtFecha* fecha23 = new DtFecha(4, 5, 2020, 16, 1);
                reloj->setFecha(fecha23);
                ctrlM->confirmarEnvioMensaje(true);
                //-----------------------------------------
                
                ctrlM->identificarse("ramon@mail.com","pass");
                ctrlM->elegirClase(id6);
                ctrlM->seleccionarMensaje(to_string(6));
                ctrlM->textoEnviar("Ya la vemos");
                DtFecha* fecha27 = new DtFecha(4, 5, 2020, 16, 5);
                reloj->setFecha(fecha27);
                ctrlM->confirmarEnvioMensaje(true);
                //-----------------------------------------

                //para finalizar asistencia de E3
                ctrlR->identificarse("ramon@mail.com", "pass");
                ctrlR->elegirClase(id6);
                DtFecha* fecha20 = new DtFecha(4, 5, 2020, 17, 0);
                reloj->setFecha(fecha20);
                ctrlR->confirmarFinalizacionAsistencia(true);

                //para finalizar C6
                ctrlC->identificarse("jorge@mail.com", "passw0rd");
                DtFecha* fecha12 = new DtFecha(4, 5, 2020, 17, 0);
                reloj->setFecha(fecha12);
                ctrlC->elegirClase(id6);
                ctrlC->confirmarFinalizacionDeClase(true);


                

                printf("\nDatos de Prueba Cargados\n");
                printf("\nLas contraseñas de los docentes son:");
                printf("\nJuan: 123, Maria: 1234, Jorge: passw0rd");
                printf("\nLas contraseñas de los estudiantes son:");
                printf("\nRoberto: pass, Ana: pass, Ramon: pass\n");
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
