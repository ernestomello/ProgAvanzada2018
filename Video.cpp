/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Video.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:32 AM
 */

#include "Video.h"
#include "Fabrica.h"

Video::Video(int duracion, string url) {
    this->Duracion = duracion;
    this->url = url;
}

Video::Video() {
}

Video::Video(const Video& orig) {
}

Video::~Video() {
}

float Video::GetDuracion() {
    return Duracion;
}

void Video::SetDuracion(float Duracion) {
    this->Duracion = Duracion;
}

string Video::GetUrl() {
    return url;
}

void Video::SetUrl(string url) {
    this->url = url;
}

DtVideo* Video::getMensaje() {
    DtVideo *mV = new DtVideo(this->url, this->Duracion);
    mV->SetCodigo(this->GetCodigo());
    mV->SetEmisor(this->getEmisor());
    DtUltCon* dtu = Fabrica::getInstance()->getContFecha()->getFechaHora();
    mV->SetFechaEnv(dtu->getFecha());
    mV->SetHoraEnv(dtu->getHora());
    return mV;
}