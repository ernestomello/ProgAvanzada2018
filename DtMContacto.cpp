/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtMContacto.cpp
 * Author: juan
 * 
 * Created on 12 de junio de 2018, 08:35 PM
 */

#include "DtMContacto.h"

string DtMContacto::getDesc() {
    return this->descripcion;
}

string DtMContacto::getNombre() {
    return this->nombre;
}

string DtMContacto::getUrl() {
    return this->url;
}

void DtMContacto::setDesc(string desc) {
    this->descripcion = desc;
}

void DtMContacto::setNombre(string nombre) {
    this->nombre = nombre;
}

void DtMContacto::setUrl(string url) {
    this->url = url;
}

DtMContacto::DtMContacto(const DtMContacto& orig) {
    this->numCel = orig.numCel;
}

DtMContacto::DtMContacto(string numCel) {
    this->numCel = numCel;
}

DtMContacto::DtMContacto() {
}

DtMContacto::~DtMContacto() {
}

string DtMContacto::getNumCel() {
    return this->numCel;
}

void DtMContacto::setNumCel(string num) {
    this->numCel = num;
}
