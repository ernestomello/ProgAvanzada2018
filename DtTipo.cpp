/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtTipo.cpp
 * Author: esteban
 * 
 * Created on 7 de junio de 2018, 01:53 AM
 */

#include "DtTipo.h"

DtTipo::DtTipo(string grupo) {
    this->grupo = grupo;
    
}

DtTipo::DtTipo(const DtTipo& orig) {
}

DtTipo::~DtTipo() {
}

//string DtTipo::getGrupo(){
//    return this->grupo;
//}