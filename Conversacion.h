/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conversacion.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:30 AM
 */

#ifndef CONVERSACION_H
#define CONVERSACION_H

#include"Mensaje.h"
#include <string.h>
#include"Lista.h"
#include"ListaDicc.h"
#include"intKey.h"
#include<iostream>
#include"DtFechaHoraIng.h"
#include"DtMensajeVisto.h"
#include"DtMensaje.h"
#include"Fecha_Hora_sis.h"
#include"ICollectible.h"

using namespace std;

class Conversacion: public ICollectible {
    
public:
    Conversacion();
    Conversacion(int);
    Conversacion(const Conversacion& orig);
    virtual ~Conversacion();   
    void setMensaje(Mensaje *);
    bool sosConversacion(int);
    Mensaje* getMensaje(int);
    bool remueveMens(int Idmen);
    bool remueveMiVisto(int idMen, string idUsu);
    void eviarMensaje(Mensaje*);
    Lista* listarMensaje(DtFechaHoraIng* );
    Lista* listarVistos(int codMens);
    void setEstado(bool);
    void setIdConv(int);
    int getIdConv();
    string getCelContacto();
    string getNomGrupo();
    bool esReceptor(int idMen, string idUsu);
    bool esEmisor(int idMen, string idUsu);
    bool existeMensaje(int idMen);
    string primerReceptor();
private:
    ListDicc * mensajes=new ListDicc();
    int idConv;
    int idMensajeConv= 1;
};

#endif /* CONVERSACION_H */

