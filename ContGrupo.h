/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContGrupo.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:47 AM
 */

#ifndef CONTGRUPO_H
#define CONTGRUPO_H
#include"iContGrupo.h"
#include"Grupo.h"
using namespace std;

class ContGrupo : public iContGrupo {
private:
    Lista* ltElegidos = new Lista();
    ListDicc* lUsuarios = new ListDicc();
    Lista * listaUsuPart = new Lista();
    Grupo* grupo;
public:
    ContGrupo();
    virtual ~ContGrupo();
    void crearTipoGrupo(DtTipo*, string);
    void createTipo(DtTipo*, string);
    void crearConvGrupo(string);
    void getUsuario(int);
    void getContactos();
    void getDtContacto();
    Lista* listarGrupos();
    Lista* seleccionarGrupo(string);
    DtContacto* seleccionarPart(int);
    bool agregarNuevoAdmin(int);
    Lista* listarContactos();
    DtContacto *seleccionarContacto(int);
    void agregarParticipante(DtContacto*);
    Lista* listarParticipantes();
    DtContacto *seleccionarParticipante(int);
    void eliminarParticipante(DtContacto*);
    void cancelar();
    DtGrupo* altaGrupo(string, string);
    void Salir();
    bool estaElegido(string);
    void vaciaListaParticipantes();
    void agregarParticipanteGrupo();
    void setGrupo(string);
};
#endif /* CONTGRUPO_H */

