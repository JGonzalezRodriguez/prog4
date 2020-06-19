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
        msj->recursivePrint();
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
                            for (std::set<DtNotificacion*>::iterator it=coldtnot.begin(); it!=coldtnot.end(); ++it) {
                                std::cout << std::endl << **it << std::endl;
                            }

                            ctrl->eliminarNotificaciones();

                        }else{
                            printf("\nEl email o la contraseña son incorrectos");
                            printf("\n");
                        }

                        break;
                    }
                   
                    case 5: {
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
                            for (std::set<DtNotificacion*>::iterator it=coldtnot.begin(); it!=coldtnot.end(); ++it) {
                                std::cout << std::endl << **it << std::endl;
                            }

                            ctrl->eliminarNotificaciones();

                        }else{
                            printf("\nEl email o la contraseña son incorrectos");
                            printf("\n");
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
            case 4: {
             
                //Cargar Controladores
                Fabrica* f = Fabrica::getInstancia();
                IAsignatura* ctrlA = f->getIAsignatura();
                IUsuario* ctrlU = f->getIUsuario();
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
                ctrlU->altaEstudiante("Ana Rodriguez", "ana@mail.com", "p4ss", "fotito.com/4", "23456789");
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

                ctrlA->elegirdocente(practico, "maria@mail.com");
                ctrlA->elegirAsignaturaAdmin("P1");
                ctrlA->confirmarAsignacionDocenteAsignatura(true);

                ctrlA->elegirdocente(monitoreo, "jorge@mail.com");
                ctrlA->elegirAsignaturaAdmin("P1");
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

                printf("\nDatos de Prueba Cargados\n");
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
