/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtFechaHoraVisto.h
 * Author: esteban
 *
 * Created on 7 de junio de 2018, 01:51 AM
 */

#ifndef DTFECHAHORAVISTO_H
#define DTFECHAHORAVISTO_H

#include"DtHora.h"
#include"DtFecha.h"

class DtFechaHoraVisto {
public:
    DtFechaHoraVisto();
    DtFechaHoraVisto(DtFecha*, DtHora*);
    DtFechaHoraVisto(const DtFechaHoraVisto& orig);
    virtual ~DtFechaHoraVisto();

    DtFecha* GetFecha();
    DtHora* GetHora();

    void SetFecha(DtFecha*);
    void SetHora(DtHora*);

private:
    DtFecha *fecha;
    DtHora *hora;

};

#endif /* DTFECHAHORAVISTO_H */

