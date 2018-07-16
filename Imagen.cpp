/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Imagen.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:32 AM
 */

#include "Imagen.h"
#include "Fabrica.h"
void Imagen::setDesc(string desc) {
    this->descripcion = desc;
}

string Imagen::getDesc() {
    return this->descripcion;
}
Imagen::Imagen() {
}

Imagen::Imagen(const Imagen& orig) {
}

Imagen::~Imagen() {
}

string Imagen::GetFormato() {
    return Formato;
}

void Imagen::SetFormato(string Formato) {
    this->Formato = Formato;
}

int Imagen::GetTamanio() {
    return Tamanio;
}

void Imagen::SetTamanio(int Tamanio) {
    this->Tamanio = Tamanio;
}

string Imagen::GetTexto() {
    return Texto;
}

void Imagen::SetTexto(string Texto) {
    this->Texto = Texto;
}

string Imagen::GetUrlImg() {
    return urlImg;
}

void Imagen::SetUrlImg(string urlImg) {
    this->urlImg = urlImg;
}

DtImagen* Imagen::getMensaje() {
    DtImagen * mI = new DtImagen(this->Tamanio, this->Formato, "Una imagen", this->urlImg, this->descripcion);
    DtUltCon* dtu = Fabrica::getInstance()->getContFecha()->getFechaHora();
    mI->SetEmisor(this->getEmisor());
    mI->SetCodigo(this->GetCodigo());
    mI->SetFechaEnv(dtu->getFecha());
    mI->SetHoraEnv(dtu->getHora());
    return mI;
}