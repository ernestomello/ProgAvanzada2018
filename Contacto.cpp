/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contacto.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:32 AM
 */

#include "Contacto.h"

string Contacto::getDesc() {
    return this->desc;
}

string Contacto::getNombre() {
    return this->nombre;
}

string Contacto::getUrl() {
    return this->urlImagen;
}

void Contacto::setDesc(string descripcion) {
    this->desc = descripcion;
}

void Contacto::setNombre(string nombre) {
    this->nombre = nombre;
}

void Contacto::setUrl(string urlImagen) {
    this->urlImagen = urlImagen;
}




Contacto::Contacto() {
}

Contacto::Contacto(const Contacto& orig) {
}

Contacto::~Contacto() {
}

string Contacto::GetNumCel() {
    return this->numCel;
}

void Contacto::SetNumCel(string numCel) {
    this->numCel = numCel;
}

DtMContacto* Contacto::getMensaje() {
    DtMContacto* mC = new DtMContacto(this->numCel);
    mC->SetCodigo(this->GetCodigo());
    mC->SetFechaEnv(this->GetFechaEnv());
    mC->SetHoraEnv(this->GetHoraEnv());
    mC->setDesc(this->desc);
    mC->setNombre(this->nombre);
    mC->setNumCel(this->numCel);
    mC->setUrl(this->urlImagen);
    return mC;
}