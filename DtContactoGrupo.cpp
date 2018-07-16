/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtContactoGrupo.cpp
 * Author: ernesto
 * 
 * Created on 26 de junio de 2018, 12:59 AM
 */

#include "DtContactoGrupo.h"
DtContactoGrupo::DtContactoGrupo(){
    
}
DtContactoGrupo::DtContactoGrupo(string celular,string nombre,string tipoEnGrupo,DtFecha* fecha,DtHora* hora) {
    this->celular = celular;
    this->nombre = nombre;
    this->tipoEnGrupo = tipoEnGrupo;
    this->fecha = fecha;
    this->hora = hora;

}

DtContactoGrupo::DtContactoGrupo(const DtContactoGrupo& orig) {
}

DtContactoGrupo::~DtContactoGrupo() {
}

string DtContactoGrupo::getCelular(){
    return this->celular;
}
string DtContactoGrupo::getipoEnGrupo(){
    return this->tipoEnGrupo;
}
string DtContactoGrupo::getnombre(){
    return this->nombre;
}
DtFecha* DtContactoGrupo::getFecha(){
    return this->fecha;
}
DtHora* DtContactoGrupo::getHora(){
    return this->hora;
}