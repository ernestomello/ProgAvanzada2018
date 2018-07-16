/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtImagen.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 03:33 AM
 */

#include "DtImagen.h"

string DtImagen::getDesc() {
    return this->descripcion;
}

void DtImagen::setDesc(string desc) {
    this->descripcion = desc;
}

DtImagen::DtImagen() {
}

DtImagen::DtImagen(int Tamanio, string formato, string texto, string urlImagen,string descripcion) {
    this->Tamanio = Tamanio;
    this->Formato = formato;
    this->Texto = texto;
    this->urlImg = urlImagen;
    this->descripcion = descripcion;
}

DtImagen::DtImagen(const DtImagen& orig) {
    this->Formato = orig.Formato;
    this->Tamanio = orig.Tamanio;
    this->Texto = orig.Texto;
    this->urlImg = orig.urlImg;
}

DtImagen::~DtImagen() {
}

string DtImagen::GetFormato() {
    return Formato;
}

void DtImagen::SetFormato(string Formato) {
    this->Formato = Formato;
}

int DtImagen::GetTamanio() {
    return Tamanio;
}

void DtImagen::SetTamanio(int Tamanio) {
    this->Tamanio = Tamanio;
}

string DtImagen::GetTexto() {
    return Texto;
}

void DtImagen::SetTexto(string Texto) {
    this->Texto = Texto;
}

string DtImagen::GetUrlImg() {
    return urlImg;
}

void DtImagen::SetUrlImg(string urlImg) {
    this->urlImg = urlImg;
}