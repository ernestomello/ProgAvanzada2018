/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtConexion.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 02:34 AM
 */

#ifndef DTCONEXION_H
#define DTCONEXION_H

#include<iostream>
#include<string.h>


using namespace std;

class DtConexion {
public:
    DtConexion();
    DtConexion(string);
    DtConexion(const DtConexion& orig);
    virtual ~DtConexion();
    string GetFechaHora();
    void SetFechaHora(string);   
    
private:
    string FechaHora;
};

#endif /* DTCONEXION_H */

