/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtMensaje.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 03:32 AM
 */

#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include"DtFecha.h"
#include"DtHora.h"
#include "ICollectible.h"
#include <iostream>

class DtMensaje : public ICollectible{
public:
    DtMensaje();
    DtMensaje(int, DtFecha*, DtHora*,string);
    DtMensaje(const DtMensaje& orig);
    virtual ~DtMensaje();

    int GetCodigo();
    DtHora* GetHoraEnv();
    DtFecha *GetFechaEnv();
    string getEmisor();

    void SetCodigo(int);
    void SetFechaEnv(DtFecha*);
    void SetHoraEnv(DtHora*);
    void SetEmisor(string);

private:
    int codigo;
    string emisor;
    DtFecha *fechaEnv;
    DtHora *horaEnv;
};

#endif /* DTMENSAJE_H */

