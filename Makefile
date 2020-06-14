
# --------------------------------------------------------------------
# Makefile de tarea 
# Basado en los makefiles del laboratorio de P2
# --------------------------------------------------------------------

# Objetivo predeterminado (no se necesita especificarlo al invocar `make').
all: principal

# directorios
HDIR    = include
CPPDIR  = src
ODIR    = obj

MODULOS = asignatura asistenciavivo clase claseestudiante ctrlasignatura ctrlclase ctrlmensaje 
MODULOS += ctrlreproduccion ctrlsubscripcion ctrlusuario dicta docente estudiante handlerasignaturas 
MODULOS += handlerusuarios mensaje monitoreo notificacion practico reloj srespuesta teorico usuario
MODULOS += dt/dtasignatura dt/dtasignaturaext dt/dtclase dt/dtdocente dt/dtestudiante dt/dtfecha 
MODULOS += dt/dtmensaje dt/dtmonitoreo dt/dtnotificacion dt/dtpractico dt/dtpromasistencia dt/dtteorico
MODULOS += dt/dttiempoasignatura dt/dtusuario fabrica

# IMPORTANTE hay que poner como "modulos" todos los archivos de src a compilar

# cadena de archivos, con directorio y extensión
HS   = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS   = $(MODULOS:%=$(ODIR)/%.o)

PRINCIPAL=main
EJECUTABLE=principal

# compilador
CC = g++
# opciones de compilación
CCFLAGS = -Wall -Werror -I$(HDIR) -g -DNDEBUG
# -DNDEBUG
# se agrega esta opción para que las llamadas a assert no hagan nada.

$(ODIR)/$(PRINCIPAL).o:$(CPPDIR)/$(PRINCIPAL).cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# cada .o depende de su .cpp
# $@ se expande para tranformarse en el objetivo
# $< se expande para tranformarse en la primera dependencia	
$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@	

# $^ se expande para tranformarse en todas las dependencias
$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@

.PHONY: clean
clean:
	@rm obj/*.o principal

