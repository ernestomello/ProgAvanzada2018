/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simple.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:32 AM
 */

#ifndef SIMPLE_H
#define SIMPLE_H

#include"Mensaje.h"
#include"DtSimple.h"

class Simple : public Mensaje {
public:
    Simple(int idMensaje, string idEmi, string texto);
    Simple();
    Simple(int,string);
    Simple(const Simple& orig);
    virtual ~Simple();
    string getTexto();
    void setTexto(string);
    DtSimple *getMensaje();


private:
    string texto;

};

#endif /* SIMPLE_H */

