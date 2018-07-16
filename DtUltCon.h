/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtUltCon.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 02:39 AM
 */

#ifndef DTULTCON_H
#define DTULTCON_H
#include"DtFecha.h"
#include"DtHora.h"

class DtUltCon {
public:

    DtUltCon();
    DtUltCon(DtFecha*, DtHora*);
    DtUltCon(const DtUltCon& orig);
    virtual ~DtUltCon();

    DtFecha* getFecha();
    DtHora* getHora();
    void setHora(DtHora*);
    void setFecha(DtFecha*);
    
private:

    DtFecha* fecha;
    DtHora* hora;
};

#endif /* DTULTCON_H */

