/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simple.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:32 AM
 */

#include "Simple.h"
#include "Fabrica.h"

Simple::Simple(int idMensaje, string idEmi, string texto) {
    this->texto = texto;
    this->SetCodigo(idMensaje);
    this->setEmisor(idEmi);
}


Simple::Simple() {
    
}
Simple::Simple(int idMens,string mensaje) {
    this->texto = mensaje;
    this->SetCodigo(idMens);
    this->SetFechaEnv(Fabrica::getInstance()->getContFecha()->getFechaHora()->getFecha());    
    this->SetHoraEnv(Fabrica::getInstance()->getContFecha()->getFechaHora()->getHora());
}

Simple::Simple(const Simple& orig) {
}

Simple::~Simple() {
}

string Simple::getTexto() {
    return this->texto;
}

void Simple::setTexto(string texto) {
    this->texto = texto;
}

DtSimple* Simple::getMensaje() {
    DtSimple * mS = new DtSimple(this->texto);
    mS->SetEmisor(this->getEmisor());
    mS->SetCodigo(this->GetCodigo());
    mS->SetFechaEnv(this->GetFechaEnv());
    mS->SetHoraEnv(this->GetHoraEnv());
    return mS;
}