/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContMensaje.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:47 AM
 */

#ifndef CONTMENSAJE_H
#define CONTMENSAJE_H
#include"iContMensaje.h"
#include"ContUsuario.h"
#include"DtFecha.h"
#include"DtImagen.h"
#include"DtMensaje.h"
#include"DtHora.h"
#include"DtSimple.h"
#include"DtContacto.h"
#include"DtConversacion.h"
#include"Lista.h"
#include"Mensaje.h"
#include"Simple.h"
#include "DtMContacto.h"
#include "Contacto.h"
#include"Imagen.h"
#include"Video.h"

using namespace std;

class ContMensaje : public iContMensaje {
private:
    DtMensaje *mensaje;
    int idConv;
    int idMensaje= 0;
    Simple* cuerpoSimple;
    Imagen* cuerpoImagen;
    Video* cuerpoVideo;
    Contacto * cuerpoContacto;

public:
    ContMensaje();
    ContMensaje(const ContMensaje& orig);
    virtual ~ContMensaje();
    void enviarMensaje();
    void crearConv(int, int);
    void crear(DtSimple*);
    void crearMensaje(DtMensaje*);
    void seleccionarCont(int);
    void selecConversacion(int);
    void getContactos();
    Lista* listarConv(); //otro listar es
    void seleccionarConv(int);
    void archivarConv();
    Lista* seleccionarConversacion(int idConv);
    void seleccionarMensaje(int);
    void eliminarMensaje(int, DtMensaje*,int);
    Lista* listarConvArchivadas();
    void cuerpoMensaje(DtSimple*);
    void cuerpoMensaje(DtImagen*);
    void cuerpoMensaje(DtMContacto*);
    void cuerpoMensaje(DtVideo*);
    void crearMensaje();
    void setMensaje(DtMensaje *mensaje);
    DtMensaje *getMensaje();
    void setIdConv(int id);
    Lista *infromacionAdicional(int idMens);
    Lista * listarConversaciones();
    Lista * listarConversacionesArch();
    Mensaje* crearMensajeGrupo(string);
    Lista* informacionAdicional(int idConv, int idMen);
    void setIdMens(int id);
};

#endif /* CONTMENSAJE_H */

