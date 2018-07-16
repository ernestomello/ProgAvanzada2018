/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtUltCon.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 02:39 AM
 */

#include "DtUltCon.h"

DtUltCon::DtUltCon() {
}

DtUltCon::DtUltCon(const DtUltCon& orig) {
}

DtUltCon::~DtUltCon() {
}

DtFecha* DtUltCon::getFecha() {
    return this->fecha;
}

void DtUltCon::setFecha(DtFecha* fecha) {
    this->fecha = fecha;
}

DtHora* DtUltCon::getHora() {
    return this->hora;
}

void DtUltCon::setHora(DtHora* hora) {
    this->hora = hora;
}

DtUltCon::DtUltCon(DtFecha* fecha, DtHora* hora) {
    this->hora = hora;
    this->fecha = fecha;
}


