/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSimple.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 03:31 AM
 */

#include "DtSimple.h"

DtSimple::DtSimple(string texto) {
    this->texto = texto;
}

DtSimple::DtSimple() {
}

DtSimple::DtSimple(const DtSimple& orig) {
    this->texto = orig.texto;
}

DtSimple::~DtSimple() {
}

void DtSimple::SetTexto(string texto) {
    this->texto = texto;
}

string DtSimple::GetTexto() {
    return texto;
}

