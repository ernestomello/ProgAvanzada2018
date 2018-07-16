/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtContacto.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 02:34 AM
 */

#include "DtContacto.h"

string DtContacto::getDesc() {
    return this->descripcion;
}

void DtContacto::setDesc(string desc) {
    this->descripcion = desc;
}

DtContacto::DtContacto() {

}

DtContacto::DtContacto(string nombre, string numCel, string tipo, DtFecha* fechaIng, DtHora* horaIng) {
    this->fechaIng = fechaIng;
    this->horaIng = horaIng;
    this->nombre = nombre;
    this->numCel = numCel;
    this->tipo = tipo;
}

DtContacto::DtContacto(string nombre, string numCel, string urlImagen) {
    this->nombre = nombre;
    this->numCel = numCel;
    this->urlImagen = urlImagen;
}

DtContacto::DtContacto(const DtContacto& orig) {
}

DtContacto::~DtContacto() {
}

DtFecha* DtContacto::GetFechaIng() {
    return fechaIng;
}

void DtContacto::SetFechaIng(DtFecha* fechaIng) {
    this->fechaIng = fechaIng;
}

DtHora* DtContacto::GetHoraIng() {
    return horaIng;
}

void DtContacto::SetHoraIng(DtHora* horaIng) {
    this->horaIng = horaIng;
}

string DtContacto::GetNombre() {
    return nombre;
}

void DtContacto::SetNombre(string nombre) {
    this->nombre = nombre;
}

string DtContacto::GetNumCel() {
    return numCel;
}

void DtContacto::SetNumCel(string numCel) {
    this->numCel = numCel;
}

string DtContacto::GetTipo() {
    return tipo;
}

void DtContacto::SetTipo(string tipo) {
    this->tipo = tipo;
}

string DtContacto::getUrlImagen() {
    return this->urlImagen;
}

void DtContacto::setUrlImagen(string urlImagen) {
    this->urlImagen = urlImagen;
}