/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtFecha.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 02:36 AM
 */

#include "DtFecha.h"

DtFecha::DtFecha() {
}

DtFecha::DtFecha(const DtFecha& orig) {
    this->anio = orig.anio;
    this->dia = orig.dia;
    this->mes = orig.mes;
}

DtFecha::DtFecha(int dia, int mes, int anio) {
    this->anio = anio;
    this->dia = dia;
    this->mes = mes;
}

DtFecha::~DtFecha() {
}

int DtFecha::GetAnio() {
    return anio;
}

void DtFecha::SetAnio(int anio) {
    this->anio = anio;
}

int DtFecha::GetDia() {
    return dia;
}

void DtFecha::SetDia(int dia) {
    this->dia = dia;
}

int DtFecha::GetMes() {
    return mes;
}

void DtFecha::SetMes(int mes) {
    this->mes = mes;
}
