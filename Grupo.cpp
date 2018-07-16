/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grupo.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:31 AM
 */

#include "Grupo.h"
#include "Fabrica.h"

Grupo::Grupo() {
    this->conv = new Conversacion();
    this->fecha = Fabrica::getInstance()->getContFecha()->getFechaHora()->getFecha();
    this->hora = Fabrica::getInstance()->getContFecha()->getFechaHora()->getHora();
    
}

Grupo::Grupo(const Grupo& orig) {
   
}

Grupo::~Grupo() {
}

string Grupo::GetCreador() {
    return creador;
}

void Grupo::SetCreador(string creador) {
    this->creador = creador;
}

DtFecha* Grupo::GetFecha() {
    return fecha;
}

void Grupo::SetFecha(DtFecha* fecha) {
    this->fecha = fecha;
}

DtHora* Grupo::GetHora() {
    return hora;
}

void Grupo::SetHora(DtHora* hora) {
    this->hora = hora;
}

string Grupo::GetImagen() {
    return imagen;
}

void Grupo::SetImagen(string imagen) {
    this->imagen = imagen;
}

string Grupo::GetNombre() {
    return nombre;
}

void Grupo::SetNombre(string nombre) {
    this->nombre = nombre;
}

Conversacion * Grupo::getConversacion() {
    return this->conv;
}


void Grupo::setConversacion(Conversacion* conv){
    this->conv = conv;
}
