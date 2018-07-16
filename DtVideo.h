/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtVideo.h
 * Author: juan
 *
 * Created on 12 de junio de 2018, 08:43 PM
 */

#ifndef DTVIDEO_H
#define DTVIDEO_H

#include<iostream>
#include "DtMultimedia.h"

class DtVideo : public DtMultimedia {
private:
    string url;
    float duracion;
    
public:
    
    DtVideo();
    DtVideo(string, float);
    virtual ~DtVideo();
    void SetDuracion(float duracion);
    float GetDuracion() const;
    void SetUrl(string url);
    string GetUrl() const;
};
#endif /* DTVIDEO_H */
