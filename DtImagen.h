/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtImagen.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 03:33 AM
 */

#ifndef DTIMAGEN_H
#define DTIMAGEN_H


#include<iostream>

#include "DtMultimedia.h"
using namespace std;

class DtImagen : public DtMultimedia {
public:
    DtImagen();
    DtImagen(int Tamanio, string formato, string texto, string urlImagen, string desc);
    DtImagen(const DtImagen& orig);
    virtual ~DtImagen();

    int GetTamanio();
    string GetUrlImg();
    string GetTexto();
    string GetFormato();
    string getDesc();
    void SetFormato(string);
    void SetTamanio(int);
    void SetTexto(string);
    void SetUrlImg(string);
    void setDesc(string);

private:
    int Tamanio;
    string Formato;
    string Texto;
    string urlImg;
    string descripcion;
};

#endif /* DTIMAGEN_H */

