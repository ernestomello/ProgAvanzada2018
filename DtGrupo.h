/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtGrupo.h
 * Author: esteban
 *
 * Created on 7 de junio de 2018, 01:52 AM
 */

#ifndef DTGRUPO_H
#define DTGRUPO_H

#include"DtHora.h"
#include"DtFecha.h"
#include"DtHora.h"
#include"DtContacto.h"

using namespace std;

class DtGrupo:public ICollectible {
public:
    DtGrupo(string);
    DtGrupo(string, DtContacto*, DtContacto*, DtFecha*, DtHora*);
    DtGrupo(const DtGrupo& orig);
    virtual ~DtGrupo();

    string GetImagenUrl();
    string GetNombre();
    DtHora *GetHoraCreacion();
    DtFecha *GetFechaCreacion();
    DtContacto *GetContactos();
    DtContacto* GetUsrCreador();

    void SetHoraCreacion(DtHora*);
    void SetContactos(DtContacto*);
    void SetFechaCreacion(DtFecha*);
    void SetImagenUrl(string);
    void SetNombre(string);
    void SetUsrCreador(DtContacto*);

private:
    string nombre;
    string imagenUrl;
    DtContacto *contactos;
    DtContacto *usrCreador;
    DtFecha *fechaCreacion;
    DtHora *HoraCreacion;
};

#endif /* DTGRUPO_H */

