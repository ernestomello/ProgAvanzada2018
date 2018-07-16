/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fecha_Hora_sis.h
 * Author: juan
 *
 * Created on 12 de junio de 2018, 11:48 AM
 */

#ifndef FECHA_HORA_SIS_H
#define FECHA_HORA_SIS_H

#include"DtFecha.h"
#include"DtHora.h"
#include"DtUltCon.h"
#include<string>

class Fecha_Hora_sis {
private:

    int dia, mes, anio;
    int HH, MM, SS;

public:

    string currentDateTime();
    DtFecha * getFecha();
    DtHora * getHora();
    int setFecha(int, int, int);
    int setHora(int, int, int);
    Fecha_Hora_sis();
    Fecha_Hora_sis(int, int, int, int, int, int);
    virtual ~Fecha_Hora_sis();
    DtUltCon * getUltimaConexion();
};
#endif /* FECHA_HORA_SIS_H */
