/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtHora.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 02:38 AM
 */

#include "DtHora.h"

DtHora::DtHora() {
}

DtHora::DtHora(int hora, int minutos, int segundos) {
    this->hora = hora;
    this->minutos = minutos;
    this->segundo = segundos;
}

DtHora::DtHora(const DtHora& orig) {
    this->hora = orig.hora;
    this->minutos = orig.minutos;
    this->segundo = orig.segundo;
}

DtHora::~DtHora() {
}

int DtHora::GetHora() {
    return hora;
}

void DtHora::SetHora(int hora) {
    this->hora = hora;
}

int DtHora::GetMinutos() {
    return minutos;
}

void DtHora::SetMinutos(int minutos) {
    this->minutos = minutos;
}

int DtHora::GetSegundo() {
    return segundo;
}

void DtHora::SetSegundo(int segundo) {
    this->segundo = segundo;
}

