/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtFechaHoraIng.cpp
 * Author: esteban
 * 
 * Created on 7 de junio de 2018, 01:52 AM
 */

#include "DtFechaHoraIng.h"
#include "DtFecha.h"
#include "DtHora.h"

DtFechaHoraIng::DtFechaHoraIng() {
}

DtFechaHoraIng::DtFechaHoraIng(const DtFechaHoraIng& orig) {
    this->fecha = orig.fecha;
    this->hora = orig.hora;
}

DtFechaHoraIng::DtFechaHoraIng(DtFecha* fecha, DtHora* hora) {
    this->fecha = fecha;
    this->hora = hora;
}

DtFechaHoraIng::~DtFechaHoraIng() {
}

void DtFechaHoraIng::SetHora(DtHora* hora) {
    this->hora = hora;
}

DtHora *DtFechaHoraIng::GetHora() const {
    return hora;
}

void DtFechaHoraIng::SetFecha(DtFecha* fecha) {
    this->fecha = fecha;
}

DtFecha *DtFechaHoraIng::GetFecha() const {
    return fecha;
}

