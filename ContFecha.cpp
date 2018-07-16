/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContFecha.cpp
 * Author: kapo_
 * 
 * Created on 24 de junio de 2018, 05:44 PM
 */

#include "ContFecha.h"

DtUltCon* ContFecha::getFechaHora() {
    DtHora* horaa = new DtHora(this->hora, this->min, 1);
    DtFecha* fechaa = new DtFecha(this->dia, this->mes, this->anio);
    return new DtUltCon(fechaa, horaa);
}

void ContFecha::setFechaHoraSistema(int dia, int mes, int anio, int min, int hora) {
    this->anio = anio;
    this->dia = dia;
    this->hora = hora;
    this->mes = mes;
    this->min = min;
}
// FORMATO DD/MM/AAAA HH:MM

string ContFecha::getFechaHoraSistema() {
    string sFinal;
    if (this->dia < 10)
        sFinal = sFinal + "0";
    sFinal = sFinal + std::to_string(this->dia) + "/";
    
    if(this->mes < 10)
        sFinal = sFinal + "0";
    sFinal = sFinal + std::to_string(this->mes) + "/";
    
    sFinal = sFinal + std::to_string(this->anio) + " ";
    
    if(this->hora < 10)
        sFinal = sFinal + "0";
    sFinal = sFinal + std::to_string(this->hora) + ":";
    
    if(this->min < 10)
        sFinal = sFinal + "0";
    sFinal = sFinal + std::to_string(this->min) + "\n";
    
    return sFinal;
}

ContFecha::ContFecha() {
}

ContFecha::ContFecha(const ContFecha& orig) {
}

ContFecha::~ContFecha() {
}

