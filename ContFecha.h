/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContFecha.h
 * Author: kapo_
 *
 * Created on 24 de junio de 2018, 05:44 PM
 */

#ifndef CONTFECHA_H
#define CONTFECHA_H
#include"DtUltCon.h"
#include"DtHora.h"
#include"DtFecha.h"
#include "iContFecha.h"

class ContFecha : public iContFecha{
    private:
        int hora;
        int min;
        int anio;
        int dia;
        int mes;
public:
    ContFecha();
    ContFecha(const ContFecha& orig);
    virtual ~ContFecha();
    void setFechaHoraSistema(int dia, int mes, int anio, int min, int hora);
    string getFechaHoraSistema();
    DtUltCon* getFechaHora();
private:

};

#endif /* CONTFECHA_H */

