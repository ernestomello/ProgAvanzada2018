/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtFecha.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 02:36 AM
 */

#ifndef DTFECHA_H
#define DTFECHA_H

using namespace std;

class DtFecha {
public:
    DtFecha();
    DtFecha(int, int, int);
    DtFecha(const DtFecha& orig);
    virtual ~DtFecha();

    int GetAnio();
    int GetDia();
    int GetMes();

    void SetAnio(int);
    void SetDia(int);
    void SetMes(int);

private:
    int dia, mes, anio;

};

#endif /* DTFECHA_H */

