/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtConexion.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 02:34 AM
 */

#include "DtConexion.h"

DtConexion::DtConexion() {
}

DtConexion::DtConexion(string FechaHora) {
    this->FechaHora = FechaHora;
}

DtConexion::DtConexion(const DtConexion& orig) {
    this->FechaHora = orig.FechaHora;
}

DtConexion::~DtConexion() {
}

string DtConexion::GetFechaHora() {
    return FechaHora;
}

void DtConexion::SetFechaHora(string FechaHora) {
    this->FechaHora = FechaHora;
}
