/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtGrupo.cpp
 * Author: esteban
 * 
 * Created on 7 de junio de 2018, 01:52 AM
 */

#include "DtGrupo.h"

DtGrupo::DtGrupo(string nombre) {
    this->nombre = nombre;
}

DtGrupo::DtGrupo(string imagenUrl, DtContacto* contactos, DtContacto* usrCreador, DtFecha* fechaCreacion, DtHora* horaCreacion) {
    this->imagenUrl = imagenUrl;
    this->contactos = contactos;
    this->usrCreador = usrCreador;
    this->fechaCreacion = fechaCreacion;
    this->HoraCreacion = horaCreacion;
}

DtGrupo::DtGrupo(const DtGrupo& orig) {
    this->imagenUrl = orig.imagenUrl;
    this->contactos = orig.contactos;
    this->usrCreador = orig.usrCreador;
    this->fechaCreacion = orig.fechaCreacion;
    this->HoraCreacion = orig.HoraCreacion;
}

DtGrupo::~DtGrupo() {
}

DtHora* DtGrupo::GetHoraCreacion() {
    return HoraCreacion;
}

void DtGrupo::SetHoraCreacion(DtHora* HoraCreacion) {
    this->HoraCreacion = HoraCreacion;
}

DtContacto* DtGrupo::GetContactos() {
    return contactos;
}

void DtGrupo::SetContactos(DtContacto* contactos) {
    this->contactos = contactos;
}

DtFecha* DtGrupo::GetFechaCreacion() {
    return fechaCreacion;
}

void DtGrupo::SetFechaCreacion(DtFecha* fechaCreacion) {
    this->fechaCreacion = fechaCreacion;
}

string DtGrupo::GetImagenUrl() {
    return imagenUrl;
}

void DtGrupo::SetImagenUrl(string imagenUrl) {
    this->imagenUrl = imagenUrl;
}

string DtGrupo::GetNombre() {
    return nombre;
}

void DtGrupo::SetNombre(string nombre) {
    this->nombre = nombre;
}

DtContacto *DtGrupo::GetUsrCreador() {
    return usrCreador;
}

void DtGrupo::SetUsrCreador(DtContacto* usrCreador) {
    this->usrCreador = usrCreador;
}