/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iContMensaje.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:46 AM
 */

#ifndef ICONTMENSAJE_H
#define ICONTMENSAJE_H

#include"Mensaje.h"
#include "Lista.h"
#include "IKey.h"
#include "Lista.h"
#include "Mensaje.h"
#include "DtMensaje.h"
#include "DtSimple.h"
#include "DtImagen.h"
#include "DtContacto.h"
#include "DtConversacion.h"
#include"DtVideo.h"
#include"DtMContacto.h"
using namespace std;

class iContMensaje {
private:

public:

    virtual ~iContMensaje();
    virtual void enviarMensaje() = 0;
    virtual void crearConv(int, int) = 0;
    virtual void crear(DtSimple*) = 0;
    virtual void crearMensaje(DtMensaje*) = 0;
    virtual void seleccionarCont(int) = 0;
    virtual void selecConversacion(int) = 0;
    virtual void getContactos() = 0;
    virtual Lista* listarConv() = 0;
    virtual void seleccionarConv(int) = 0;
    virtual void archivarConv() = 0;
    virtual Lista* seleccionarConversacion(int) = 0;
    virtual void seleccionarMensaje(int) = 0;
    virtual void eliminarMensaje(int, DtMensaje*, int) = 0;
    virtual Lista* listarConvArchivadas() = 0;
    virtual void cuerpoMensaje(DtSimple*) = 0;
    virtual void cuerpoMensaje(DtImagen*) = 0;
    virtual void cuerpoMensaje(DtVideo*) = 0;
    virtual void cuerpoMensaje(DtMContacto*) = 0;
    virtual void crearMensaje() = 0;
    virtual void setMensaje(DtMensaje* mensaje) = 0;
    virtual DtMensaje *getMensaje() = 0;
    virtual void setIdConv(int id) = 0;
    virtual Lista * listarConversaciones() = 0;
    virtual Lista * listarConversacionesArch() = 0;
    virtual Lista* infromacionAdicional(int) = 0;
    virtual Mensaje* crearMensajeGrupo(string) = 0;
    virtual Lista* informacionAdicional(int idConv, int idMen) = 0;
    virtual void setIdMens(int id)= 0;
};

#endif /* ICONTMENSAJE_H */

