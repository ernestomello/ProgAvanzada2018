/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tipo.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:31 AM
 */

#include "Tipo.h"

Tipo::Tipo(Grupo* grupo,string estipo,DtUltCon* fecha) {
    this->grupo = grupo;
    this->tipo = estipo;
    this->fechaIng = fecha->getFecha();
    this->horaIng = fecha->getHora();
}

Tipo::Tipo(const Tipo& orig) {
}

Tipo::~Tipo() {
}

DtFecha* Tipo::GetFechaIng() {
    return fechaIng;
}

void Tipo::SetFechaIng(DtFecha* fechaIng) {
    this->fechaIng = fechaIng;
}

DtHora* Tipo::GetHoraIng() {
    return horaIng;
}

void Tipo::SetHoraIng(DtHora* horaIng) {
    this->horaIng = horaIng;
}

string Tipo::GetTipo() {
    return tipo;
}

void Tipo::SetTipo(string tipo) {
    this->tipo = tipo;
}

Grupo * Tipo::getGrupo() {
    return this->grupo;
}

DtFechaHoraIng* Tipo::getFechaHoraIng() {
    DtFechaHoraIng *dtFech = new DtFechaHoraIng(this->fechaIng, this->horaIng);
    return dtFech;
}

DtGrupo* Tipo::getGrupos(){
    
    DtGrupo* dtGrupo= new DtGrupo(this->grupo->GetNombre());
    return dtGrupo;
}
