/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Imagen.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:32 AM
 */

#ifndef IMAGEN_H
#define IMAGEN_H

#include"Multimedia.h"
#include"DtImagen.h"

class Imagen : public Multimedia {
public:
    Imagen();
    Imagen(const Imagen& orig);
    virtual ~Imagen();

    int GetTamanio();
    string GetFormato();
    string GetUrlImg();
    string GetTexto();
    string getDesc();
    DtImagen * getMensaje();
    void setDesc(string);
    void SetTexto(string);
    void SetTamanio(int);
    void SetFormato(string);
    void SetUrlImg(string);

private:
    
    int Tamanio;
    string Formato;
    string Texto;
    string urlImg;
    string descripcion;
};

#endif /* IMAGEN_H */

