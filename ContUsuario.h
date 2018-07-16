/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContUsuario.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:47 AM
 */

#ifndef CONTUSUARIO_H
#define CONTUSUARIO_H

#include"iContUsuario.h"
#include"DtUltCon.h"
#include"DtContacto.h"
#include "DtContactoGrupo.h"
#include"DtConexion.h"
#include"DtFecha.h"
#include"DtHora.h"
#include"IDictionary.h"
//#include"Usuario.h"
#include"Lista.h"
#include "ListaDicc.h"
#include "ContMensaje.h"
#include "ContGrupo.h"
#include "StringKey.h"
#include "Fecha_Hora_sis.h"


using namespace std;

class ContUsuario : public iContUsuario {
private:
    ListDicc * usuario = new ListDicc();
    Usuario * usuLog;
    string numCel, contactoReceptor; 
    int idConv = 1;

public:
    ContUsuario();
    ContUsuario(const ContUsuario& orig);
    virtual ~ContUsuario();
    Lista * seleccionarConversacion(int idconv);
    bool usuarioLogueado(string);
    bool ingresarCelular(string); // Chequea que el celular esté en la lista de usuarios del sistema.
    bool altaUsuario(string, string, string);
    bool cancelaIngreso();
    DtConexion* asignarSesion();
    Lista * listarContactos(string);
    Lista * listarConversacion(string);
    Lista * listarConversacion();
    bool eliminarMensaje(int idMen,int idConv);
    DtContacto* ingContacto(string);
    void agregaContacto(DtContacto*);
    void cerrarSesion(DtConexion*);
    void modificarPerfil(string, string, string);
    void actualizarDatos();
    void setNumCel(string numCel);
    string getNumCel();
    Usuario* getUsu();
    void setUltimaCon(DtUltCon*);
    void setUsuLog(Usuario*);
    string getNumContacto(int idConv);
    string getNombreCont(string receptor);
    Lista* listaConversacion();
    Lista* listaConversacionArc();
    string getNumUsuLog();
    Lista*  listarInfoVisto(int idConv,int idMensaje);
    void crearTipoUsuario(Grupo*,string);
    int getIdConv();
    void elijeContacto(string celUsu);
    Conversacion* getConversacion(int idConv);
    string getReceptor();
    void setReceptor(string);
    Usuario* getUsuByCel(string);
    void setIdConvGrupo(string idUsu);

//    Conversacion* getConversacion(int idConv); 

    void altaPrecargaUsuario(string, string, string, string);
    void altaPrecargaContacto(string);
    void altaPrecargaConversacion();
    void setFechaHoraG(DtFecha* fech, DtHora * hora);
    int generarIdConv();
    //void setIdConvGrupo(int idConv);//precarga
    void cargarMensaje();
    Usuario* getUsuario(string celUsu);
    string getOtroContacto(int);
};

#endif /* CONTUSUARIO_H */

