/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSimple.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 03:31 AM
 */

#ifndef DTSIMPLE_H
#define DTSIMPLE_H

#include "DtMensaje.h"
#include<iostream>

class DtSimple : public DtMensaje {
    
public:
    DtSimple();
    DtSimple(string);
    DtSimple(const DtSimple& orig);
    virtual ~DtSimple();
    void SetTexto(string texto);
    string GetTexto();
    
private:
    string texto;
};

#endif /* DTSIMPLE_H */

