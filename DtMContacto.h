/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtMContacto.h
 * Author: juan
 *
 * Created on 12 de junio de 2018, 08:35 PM
 */

#ifndef DTMCONTACTO_H
#define DTMCONTACTO_H

#include "DtMensaje.h"
#include<iostream>
class DtMContacto : public DtMensaje {
private:
    string numCel;
    string nombre, url, descripcion;
public:
    void setNombre(string nombre);
    void setUrl(string url);
    void setDesc(string desc);
    
    string getNombre();
    string getUrl();
    string getDesc();
    
    DtMContacto();
    DtMContacto(string);
    DtMContacto(const DtMContacto& orig);
    virtual ~DtMContacto();
    void setNumCel(string);
    string getNumCel();
};
#endif /* DTMCONTACTO_H */
