/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtConversacion.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 03:18 AM
 */

#include "DtConversacion.h"

DtConversacion::DtConversacion() {
}

DtConversacion::DtConversacion(int idConversa, int Cel_Cantidad, string nombre) {
    this->Cel_Cantidad = Cel_Cantidad;
    this->Nombre = nombre;
    this->idConversa = idConversa;
}

DtConversacion::DtConversacion(const DtConversacion& orig) {
    this->Cel_Cantidad = orig.Cel_Cantidad;
    this->Nombre = orig.Nombre;
    this->idConversa = orig.idConversa;
}

DtConversacion::DtConversacion(string nombre, int idconv) {
    this->Nombre = nombre;
    this->idConversa = idconv;
    this->Cel_Cantidad = 0;
}

DtConversacion::DtConversacion(int idconv, int cel_cant) {
    this->idConversa = idconv;
    this->Cel_Cantidad = cel_cant;
}

DtConversacion::DtConversacion(int cel_cant) {
    this->Nombre = "Conversaciones Archivadas";
    this->Cel_Cantidad = cel_cant;
}

DtConversacion::~DtConversacion() {
}

int DtConversacion::GetCel_Cantidad() {
    return Cel_Cantidad;
}

void DtConversacion::SetCel_Cantidad(int Cel_Cantidad) {
    this->Cel_Cantidad = Cel_Cantidad;
}

string DtConversacion::GetNombre() {
    return Nombre;
}

void DtConversacion::SetNombre(string Nombre) {
    this->Nombre = Nombre;
}

int DtConversacion::GetIdConversa() {
    return idConversa;
}

void DtConversacion::SetIdConversa(int idConversa) {
    this->idConversa = idConversa;
}
