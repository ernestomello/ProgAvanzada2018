/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:33 AM
 */

#ifndef ESTADO_H
#define ESTADO_H

#include "DtHora.h"
#include "DtFecha.h"
class Estado {
public:
    Estado();
    Estado(const Estado& orig);
    virtual ~Estado();
private:
    string texto;
    DtFecha* fecha;
    DtHora* hora;
};

#endif /* ESTADO_H */

