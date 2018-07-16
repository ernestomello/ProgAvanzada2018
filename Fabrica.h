/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fabrica.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:40 AM
 */




#ifndef FABRICA_H
#define FABRICA_H

#include"ContGrupo.h"
#include"ContMensaje.h"
#include"ContUsuario.h"
#include "ContFecha.h"
#include"DtConexion.h"
class Fabrica {
    //Fabrica es singleton
private:
    ContUsuario * cUsu;
    ContMensaje * cMens;
    ContGrupo * cGru;
    ContFecha* cFec;
    Fabrica();
    static Fabrica* fabrica;
    
public:
    void cargarDatosPrueba();
    static Fabrica* getInstance();
    iContUsuario* getContUsuario();
    iContMensaje* getContMensaje();
    iContGrupo* getContGrupo();
    iContFecha* getContFecha();
    //destructor
    virtual ~Fabrica();
    void cargarUsu();
    void cargarContactos();
    void cargaGrupo();
    void cargarConversaciones();
    void cargarMensajes();
    
private:

};

#endif /* FABRICA_H */

