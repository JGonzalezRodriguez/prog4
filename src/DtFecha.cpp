#include "../include/dt/dtfecha.h"

DtFecha::DtFecha(int dia, int mes, int anio, int hora, int min){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->min = min;
}

DtFecha::~DtFecha(){}

int DtFecha::getDia(){
    return this->dia;
}

int DtFecha::getMes(){
    return this->mes;
}

int DtFecha::getAnio(){
    return this->anio;
}

int DtFecha::getHora(){
    return this->hora;
}

int DtFecha::getMin(){
    return this->min;
}

