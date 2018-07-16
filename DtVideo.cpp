/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtVideo.cpp
 * Author: juan
 * 
 * Created on 12 de junio de 2018, 08:43 PM
 */

#include "DtVideo.h"

DtVideo::DtVideo(string url, float duracion) {
    this->duracion = duracion;
    this->url = url;
}

DtVideo::DtVideo() {

}

DtVideo::~DtVideo() {
}

void DtVideo::SetDuracion(float duracion) {
    this->duracion = duracion;
}

float DtVideo::GetDuracion() const {
    return duracion;
}

void DtVideo::SetUrl(string url) {
    this->url = url;
}

string DtVideo::GetUrl() const {
    return url;
}
