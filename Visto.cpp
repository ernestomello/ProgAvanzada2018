/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visto.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:31 AM
 */

#include "Visto.h"

Visto::Visto(string receptor, bool estado) {
    this->Receptor = receptor;
    this->estado = estado;
    this->fechaV = new DtFecha(0,0,0);
    this->horaV = new DtHora(0,0,0);
}

Visto::Visto() {
    
}
Visto::Visto(string celular) {
    this->Receptor = celular;
    this->estado = false;
    this->fechaV = new DtFecha();
    this->horaV = new DtHora();
}

Visto::Visto(const Visto& orig) {
}

Visto::~Visto() {
}


bool Visto::getEstado() {
    return estado;
}

void Visto::SetEstado(bool estado) {
    this->estado = estado;
}

DtFecha * Visto::GetFechaV() {
    return fechaV;
}

void Visto::SetFechaV(DtFecha * fechaV) {
    this->fechaV = fechaV;
}

DtHora * Visto::GetHoraV() {
    return horaV;
}

void Visto::SetHoraV(DtHora * horaV) {
    this->horaV = horaV;
}

bool Visto::esReceptor(string recep){
    if (recep==this->Receptor) return true;
} 
string Visto::getReceptor(){
    return Receptor;
}
DtFechaHoraVisto * Visto::getFechaHoraVisto(){
    DtFechaHoraVisto* dtFecha=new DtFechaHoraVisto(this->fechaV,this->horaV);
    return dtFecha;
}
void Visto::setReceptor(string rec){this->Receptor=rec;}
