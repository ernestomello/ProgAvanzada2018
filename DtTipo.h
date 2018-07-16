/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtTipo.h
 * Author: esteban
 *
 * Created on 7 de junio de 2018, 01:53 AM
 */

#ifndef DTTIPO_H
#define DTTIPO_H
#include <iostream>
#include"DtGrupo.h"
#include"DtHora.h"
#include"DtFecha.h"
class DtTipo : public ICollectible {
    
public:
    DtTipo(string);
    DtTipo(const DtTipo& orig);
    virtual ~DtTipo();
    string getGrupo();
    
private:
    string grupo;
    string tipo;
    DtFecha *fechaIng;
    DtHora *horaIng;
    
};

#endif /* DTTIPO_H */

