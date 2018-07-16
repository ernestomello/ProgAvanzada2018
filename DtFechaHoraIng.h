/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtFechaHoraIng.h
 * Author: esteban
 *
 * Created on 7 de junio de 2018, 01:52 AM
 */

#ifndef DTFECHAHORAING_H
#define DTFECHAHORAING_H

#include<iostream>
#include "DtHora.h"
#include "DtFecha.h"
using namespace std;

class DtFechaHoraIng {
public:
    DtFechaHoraIng();
    DtFechaHoraIng(DtFecha*, DtHora*);
    DtFechaHoraIng(const DtFechaHoraIng& orig);

    virtual ~DtFechaHoraIng();
    void SetHora(DtHora* hora);
    DtHora* GetHora() const;
    void SetFecha(DtFecha* fecha);
    DtFecha* GetFecha() const;

private:
    DtFecha *fecha;
    DtHora *hora;

};

#endif /* DTFECHAHORAING_H */

