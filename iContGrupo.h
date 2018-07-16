/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iContGrupo.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:45 AM
 */

#ifndef ICONTGRUPO_H
#define ICONTGRUPO_H

#include"IKey.h"
#include"Lista.h"
#include"DtGrupo.h"
#include"DtTipo.h"
#include"DtContacto.h"

using namespace std;

class iContGrupo {
public:

    virtual ~iContGrupo();
    virtual void crearTipoGrupo(DtTipo*, string) = 0;
    virtual void createTipo(DtTipo*, string) = 0;
    virtual void crearConvGrupo(string) = 0;
    virtual void getUsuario(int) = 0;
    virtual void getContactos() = 0;
    virtual void getDtContacto() = 0;
    virtual Lista* listarGrupos() = 0;
    virtual Lista* seleccionarGrupo(string) = 0;
    virtual DtContacto* seleccionarPart(int) = 0;
    virtual bool agregarNuevoAdmin(int) = 0;
    virtual Lista* listarContactos() = 0;
    virtual DtContacto* seleccionarContacto(int) = 0;
    virtual void agregarParticipante(DtContacto*) = 0;
    virtual Lista* listarParticipantes() = 0;
    virtual DtContacto* seleccionarParticipante(int) = 0;
    virtual void eliminarParticipante(DtContacto*) = 0;
    virtual void cancelar() = 0;
    virtual DtGrupo* altaGrupo(string, string) = 0;
    virtual void Salir() = 0;
    virtual bool estaElegido(string )=0;
    virtual void vaciaListaParticipantes()= 0;
    virtual void agregarParticipanteGrupo()=0;
    virtual void setGrupo(string)= 0;

private:

};

#endif /* ICONTGRUPO_H */

