// enum modosubscripcion {subasignatura, subclase, subrespuesta}; // deprecado no?
enum instituto {IMERL, IIE, IA, DISI, IF, INCO};
enum modalidad {teorico, practico, monitoreo};
//recordar que los enums se mapean a numeros, para q dps los podamos imprimir etc, tenemos q interpretarlos ej: if(instituto == 3){cout << "IA"}