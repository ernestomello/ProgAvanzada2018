/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Video.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:32 AM
 */

#ifndef VIDEO_H
#define VIDEO_H

#include"Multimedia.h"
#include "DtVideo.h"

class Video : public Multimedia {
public:
    Video(int, string);
    Video();
    Video(const Video& orig);
    virtual ~Video();
    DtVideo* getMensaje();
    float GetDuracion();
    string GetUrl();
    void SetDuracion(float);
    void SetUrl(string);

private:
    float Duracion;
    string url;

};

#endif /* VIDEO_H */

