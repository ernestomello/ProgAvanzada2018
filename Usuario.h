/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:30 AM
 */

#ifndef USUARIO_H
#define USUARIO_H

#include"DtFechaHoraIng.h"
#include "DtFecha.h"
#include "DtHora.h"
#include "DtUltCon.h"
#include "ICollectible.h"
#include "Lista.h"
#include "DtTipo.h"
#include "EstadoConv.h"
#include "DtContacto.h"
#include "ListaDicc.h"
#include "Tipo.h"
#include "Fecha_Hora_sis.h"
#include "DtConversacion.h"
#include "DtContactoGrupo.h"
#include <iostream>

using namespace std;

class Usuario : public ICollectible {
public:
    //constructores:
    Usuario();
    Usuario(string nombre, string imagenPerfil, string descripcion, string numCel);
//    Usuario(string celUsu,string nombre,string UrlImagen,string descripcion);
    Usuario(const Usuario& orig);
    virtual ~Usuario();

    //Setter atributos
    void SetCelular(string);
    void SetContacto(Usuario * contacto);
    void SetDescripcion(string);
    void SetNombre(string);
    void SetFoto_Perfil(string);
    void SetEstadoConv(EstadoConv *);
    void SetFechaCreacion(DtFecha *);
    void SetHoraCreacion(DtHora *);
    void SetTipo(Tipo *);
    void SetUltima_conexion(DtUltCon*);
    void addContacto(Usuario*);

    //Getters atributos
    string GetCelular();
    string GetDescripcion();
    string GetFoto_Perfil();
    string GetNombre();
    DtFecha* GetFechaCreacion();
    DtFecha* GetFecha_Registro();
    DtHora* GetHoraCreacion();
    DtUltCon* GetUltima_conexion();
    DtContacto* GetContacto();

    //Operaciones
    Lista * getConversaciones(string);
    Lista * getConversacionesAr();
    Lista * GetContactos(string);
    Lista * getConversaciones();
    Lista* GetContactos();
    ListDicc* getListaContactos();
    void crearConvGrupo(Conversacion *);
    Usuario * seleccionarCont(string);
    Lista * seleccionarConversacion(int);
    void crearConversacion( Conversacion *); //para el usuario actual
    void crearEstadoConv(Conversacion *conv, Usuario * usu, Usuario * usu2); //para el contacto
    bool eliminarMensConv(int idMen,int idConv);
   
    bool convGrupal(int);
    DtConversacion * getConvGrupo(int);
    bool sosElOtro(int idConv);
    Lista * listarMensajes(int codConv);
    Lista * listarVistos(int idMens,int idConv);
    string nombreUsu(string numCel);
    string getNumContacto(int);
    void crearTipo(Grupo*,string,DtUltCon*);
    void crearEstadoConversacion(Conversacion *conv);
    Lista * getTipos();
    Lista * getContactosGrupo(string);
//    Conversacion* getConversacion(int idConv);
    Lista *getContactosGrupo(int idConv);

    Grupo* getGrupo(string grupo);
    void archivaConversacion(int);
    Conversacion* getConversacion(int idConv);

    void setFechaHoraG(DtFecha* fecha, DtHora* hora);
    void setIdConvGrupo(int id);
    void setMensaje(Mensaje*,int idConv);
    bool esReceptor(int idMen, int idConv);
    bool soyEmisor(int idMen, int idConv);
    bool existeConversacion(int idConv);
private:

    ListDicc* contactos = new ListDicc();
    Lista * estadoConv = new Lista();
    Lista * tipo = new Lista();
    string celular;
    string nombre;
    string foto_Perfil;
    string descripcion;
    DtUltCon * ultima_conexion;
    DtFecha * fechaCreacion;
    DtHora * horaCreacion;

};

#endif /* USUARIO_H */

