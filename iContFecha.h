/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iContFecha.h
 * Author: kapo_
 *
 * Created on 24 de junio de 2018, 05:36 PM
 */

#ifndef ICONTFECHA_H
#define ICONTFECHA_H

#include"DtUltCon.h"
#include<string>

using namespace std;

class iContFecha{
public:
    virtual string getFechaHoraSistema() = 0;
    virtual void setFechaHoraSistema(int dia, int mes, int anio, int min, int hora) = 0;
    virtual DtUltCon* getFechaHora() = 0;
};

#endif /* ICONTFECHA_H */

