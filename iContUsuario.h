/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iContUsuario.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:47 AM
 */

#ifndef ICONTUSUARIO_H
#define ICONTUSUARIO_H

#include "IKey.h"
#include "Lista.h"
#include "DtFecha.h"
#include "DtHora.h"
#include "DtContacto.h"
#include "DtConexion.h"
#include "DtUltCon.h"
#include "Usuario.h"
//#include "DtContactoGrupo.h"

using namespace std;

class iContUsuario {
public:

    virtual ~iContUsuario();
    virtual void setUltimaCon(DtUltCon*) = 0;
    virtual void setUsuLog(Usuario*) = 0;
    virtual bool usuarioLogueado(string) = 0;
    virtual bool ingresarCelular(string) = 0;
    virtual bool altaUsuario(string, string, string) = 0;
    virtual bool eliminarMensaje(int idMen,int idConv)=0;
    virtual bool cancelaIngreso() = 0;
    virtual DtConexion* asignarSesion() = 0;
    virtual Lista * listarContactos(string) = 0;
    virtual Lista * listarConversacion()= 0;
    virtual Lista * seleccionarConversacion(int) = 0;
    virtual DtContacto* ingContacto(string) = 0;
    virtual void agregaContacto(DtContacto*) = 0;
    virtual void cerrarSesion(DtConexion*) = 0;
    virtual void modificarPerfil(string, string, string) = 0;
    virtual void actualizarDatos() = 0;
    virtual void setNumCel(string numCel) = 0;
    virtual string getNumCel() = 0;
    virtual Lista* listaConversacion() = 0;
    virtual Lista * listarConversacion(string) = 0;
    virtual Lista* listaConversacionArc() = 0;
    virtual string getNombreCont(string receptor) = 0;
    virtual string getNumContacto(int idConv) = 0;
    virtual string getNumUsuLog() = 0;
    virtual Usuario* getUsu() = 0;
    virtual Lista*  listarInfoVisto(int idConv,int idMensaje)=0;
    virtual void crearTipoUsuario(Grupo*,string)= 0;
    virtual int getIdConv() = 0;
    virtual void elijeContacto(string celUsu) = 0;
//    virtual Conversacion* getConversacion(int idConv) = 0;
    virtual string getReceptor() = 0;
    virtual void setReceptor(string)=0;
    virtual Usuario* getUsuByCel(string) = 0;
    virtual Conversacion* getConversacion(int idConv) = 0;
    virtual void altaPrecargaUsuario(string, string, string, string) = 0;
    virtual void altaPrecargaContacto(string) = 0;
    virtual void altaPrecargaConversacion() = 0;
    virtual void setFechaHoraG(DtFecha* fech, DtHora * hora)=0;
    virtual int generarIdConv()=0;
    virtual Usuario* getUsuario(string celUsu)=0;
//    virtual void altaPrecargaContacto(int numCelular)=0;
    virtual void setIdConvGrupo(string idUsu)=0;
    virtual string getOtroContacto(int idConv)=0;
private:

};


#endif /* ICONTUSUARIO_H */

