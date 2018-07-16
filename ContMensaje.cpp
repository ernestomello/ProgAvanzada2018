/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContMensaje.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:47 AM
 */

#include"ContMensaje.h"
#include "iContUsuario.h"
#include "Fabrica.h"
#include "Imagen.h"
#include "DtVideo.h"
#include "Contacto.h"

using namespace std;

ContMensaje::ContMensaje() {
}

void ContMensaje::setMensaje(DtMensaje *mensaje) {
    this->mensaje = mensaje;
}

DtMensaje* ContMensaje::getMensaje() {
    return mensaje;
}

void ContMensaje::seleccionarConv(int idConv) {
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    Lista * retorno;
    retorno = usuLog->seleccionarConversacion(idConv);
}

ContMensaje::~ContMensaje() {
}

void ContMensaje::enviarMensaje() {
    IIterator *it;
    Visto* visto;
    int noGrupo = 0;
    if (Fabrica::getInstance()->getContUsuario()->getUsu()->convGrupal(this->idConv)) {
        Lista* usuariosGrupo = Fabrica::getInstance()->getContUsuario()->getUsu()->getContactosGrupo(this->idConv);
        it = usuariosGrupo->iterator();
    } else {
        
        visto = new Visto(Fabrica::getInstance()->getContUsuario()->getReceptor(), false);
        noGrupo = 1;
    }

    if (this->cuerpoSimple != NULL) {
        //if(!it->hasNext())
        if (noGrupo == 1)
            this->cuerpoSimple->SetVisto(visto);
        else {
            while (it->hasNext()) {
                visto = new Visto(dynamic_cast<Usuario*> (it->getCurrent())->GetCelular(), false);
                this->cuerpoSimple->SetVisto(visto);
                it->next();
            }
        }
        Conversacion * conv = dynamic_cast<Conversacion*> (Fabrica::getInstance()->getContUsuario()->getConversacion(this->idConv));
        conv->setMensaje(this->cuerpoSimple);
        //dynamic_cast<Conversacion*>(Fabrica::getInstance()->getContUsuario()->getConversacion(this->idConv))->setMensaje(this->cuerpoSimple);
    }
    if (this->cuerpoImagen != NULL) {
        if (noGrupo == 1)
            //        if(!it->hasNext())
            this->cuerpoImagen->SetVisto(visto);
        else {
            while (it->hasNext()) {
                visto = new Visto(dynamic_cast<Usuario*> (it->getCurrent())->GetCelular(), false);
                this->cuerpoImagen->SetVisto(visto);
                it->next();
            }
        }
        Conversacion * conv = dynamic_cast<Conversacion*> (Fabrica::getInstance()->getContUsuario()->getConversacion(this->idConv));
        conv->setMensaje(this->cuerpoImagen);
        //dynamic_cast<Conversacion*>(Fabrica::getInstance()->getContUsuario()->getConversacion(this->idConv))->setMensaje(this->cuerpoImagen);
    }
    if (this->cuerpoVideo != NULL) {
        if (noGrupo == 1)
            //        if(!it->hasNext())
            this->cuerpoVideo->SetVisto(visto);
        else {
            while (it->hasNext()) {
                visto = new Visto(dynamic_cast<Usuario*> (it->getCurrent())->GetCelular(), false);
                this->cuerpoVideo->SetVisto(visto);
                it->next();
            }
        }
        Conversacion * conv = dynamic_cast<Conversacion*> (Fabrica::getInstance()->getContUsuario()->getConversacion(this->idConv));
        conv->setMensaje(this->cuerpoVideo);
        //dynamic_cast<Conversacion*>(Fabrica::getInstance()->getContUsuario()->getConversacion(this->idConv))->setMensaje(this->cuerpoVideo);
    }
    if (this->cuerpoContacto != NULL) {
        //        if(!it->hasNext())
        if (noGrupo == 1)
            this->cuerpoContacto->SetVisto(visto);
        else {
            while (it->hasNext()) {
                visto = new Visto(dynamic_cast<Usuario*> (it->getCurrent())->GetCelular(), false);
                this->cuerpoContacto->SetVisto(visto);
                it->next();
            }
        }
        Conversacion * conv = dynamic_cast<Conversacion*> (Fabrica::getInstance()->getContUsuario()->getConversacion(this->idConv));
        conv->setMensaje(this->cuerpoContacto);
        //dynamic_cast<Conversacion*>(Fabrica::getInstance()->getContUsuario()->getConversacion(this->idConv))->setMensaje(this->cuerpoContacto);
    }
    this->cuerpoImagen = NULL;
    this->cuerpoSimple = NULL;
    this->cuerpoVideo = NULL;
    this->cuerpoContacto = NULL;
}

void ContMensaje::crearConv(int, int) {
}

void ContMensaje::crear(DtSimple*) {
}

void ContMensaje::crearMensaje(DtMensaje*) {
}

void ContMensaje::selecConversacion(int idConv) {
    iContUsuario * ContUsu = Fabrica::getInstance()->getContUsuario();
    if (ContUsu->seleccionarConversacion(idConv) == NULL)
        throw invalid_argument("Esta conversacion no existe\n");
   // ContUsu->setReceptor(->getCelContacto());
   // ContUsu->setReceptor(ContUsu->getConversacion(idConv)->primerReceptor()) ;
    this->idConv = idConv;
}

void ContMensaje::getContactos() {
}

void ContMensaje::archivarConv() {
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    usuLog->getUsu()->archivaConversacion(this->idConv);
}

void ContMensaje::seleccionarMensaje(int) {
}

Lista* ContMensaje::listarConvArchivadas() {
}

void ContMensaje::seleccionarCont(int) {
}

void ContMensaje::cuerpoMensaje(DtVideo* dtv) {
    this->idMensaje++;
    DtUltCon* dtu = Fabrica::getInstance()->getContFecha()->getFechaHora();
    Video* v = new Video(dtv->GetDuracion(), dtv->GetUrl());
    v->SetFechaEnv(dtu->getFecha());
    v->SetHoraEnv(dtu->getHora());
    v->setEmisor(Fabrica::getInstance()->getContUsuario()->getNumUsuLog());
    this->cuerpoVideo = v;
}

void ContMensaje::cuerpoMensaje(DtSimple* dts) {
    this->idMensaje++;
    DtUltCon* dtu = Fabrica::getInstance()->getContFecha()->getFechaHora();
    Simple *s = new Simple(this->idMensaje, Fabrica::getInstance()->getContUsuario()->getNumUsuLog(), dts->GetTexto());
    s->SetFechaEnv(dtu->getFecha());
    s->SetHoraEnv(dtu->getHora());
    this->cuerpoSimple = s;
    

}

void ContMensaje::cuerpoMensaje(DtImagen* dti) {
    DtUltCon* dtu = Fabrica::getInstance()->getContFecha()->getFechaHora();
    this->idMensaje++;
    Imagen *i = new Imagen();
    i->SetCodigo(this->idMensaje);
    i->SetFormato(dti->GetFormato());
    i->SetHoraEnv(dtu->getHora());
    i->SetFechaEnv(dtu->getFecha());
    i->SetTamanio(dti->GetTamanio());
    i->setDesc(i->getDesc());
    i->SetUrlImg(dti->GetUrlImg());
    i->setEmisor(Fabrica::getInstance()->getContUsuario()->getNumUsuLog());
    this->cuerpoImagen = i;
}

void ContMensaje::cuerpoMensaje(DtMContacto* dtmc) {
    DtUltCon* dtu = Fabrica::getInstance()->getContFecha()->getFechaHora();
    this->idMensaje++;
    Contacto* c = new Contacto();
    DtContacto* u = Fabrica::getInstance()->getContUsuario()->getUsuByCel(dtmc->getNumCel())->GetContacto();
    c->SetCodigo(this->idMensaje);
    c->SetFechaEnv(dtu->getFecha());
    c->SetHoraEnv(dtu->getHora());
    c->SetNumCel(dtmc->getNumCel());
    c->setEmisor(Fabrica::getInstance()->getContUsuario()->getNumUsuLog());
    c->setNombre(u->GetNombre());
    c->setUrl(u->getUrlImagen());
    c->setDesc(u->getDesc());
    this->cuerpoContacto = c;
}

void ContMensaje::crearMensaje() {
}

Lista * ContMensaje::infromacionAdicional(int idMens) {
}

void ContMensaje::setIdConv(int id) {
    this->idConv = id;
}

Lista * ContMensaje::listarConversacionesArch() {
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    Lista * retorno;
    return retorno = usuLog->listaConversacionArc();
}

Lista* ContMensaje::listarConv() {
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    Lista * retorno;
    return retorno = usuLog->listarConversacion("p");
}

Lista* ContMensaje::seleccionarConversacion(int idConv) {
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    Lista * retorno;
    retorno = usuLog->getUsu()->listarMensajes(idConv);
    return retorno;
}

void ContMensaje::eliminarMensaje(int idConv, DtMensaje* dtMen, int celUsu) {
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    //    usuLog->eliminarMensConv(idConv, dtMen->GetCodigo(), celUsu);
}

Lista * ContMensaje::listarConversaciones() {
    iContUsuario* contUsu = Fabrica::getInstance()->getContUsuario();
    Lista * convAct;
    convAct = contUsu->listaConversacion();
    return convAct;
}

Mensaje* ContMensaje::crearMensajeGrupo(string mensaje) {
    this->idMensaje++;
    Mensaje* mens = new Simple(this->idMensaje, mensaje);
    return mens;
}

Lista* ContMensaje::informacionAdicional(int idConv, int idMen) {
    Conversacion* conv = Fabrica::getInstance()->getContUsuario()->getConversacion(idConv);
    Mensaje *m = NULL;
    if (dynamic_cast<Simple*> (conv->getMensaje(idMen)))
        m = dynamic_cast<Simple*> (conv->getMensaje(idMen));

    if (dynamic_cast<Imagen*> (conv->getMensaje(idMen)))
        m = dynamic_cast<Imagen*> (conv->getMensaje(idMen));

    if (dynamic_cast<Video*> (conv->getMensaje(idMen)))
        m = dynamic_cast<Video*> (conv->getMensaje(idMen));

    if (dynamic_cast<Contacto*> (conv->getMensaje(idMen)))
        m = dynamic_cast<Contacto*> (conv->getMensaje(idMen));
    if (m == NULL)
        throw invalid_argument("Este Mensaje no existe\n");
    DtMensajeVisto *dtmv;
    if (m->getEmisor().compare(Fabrica::getInstance()->getContUsuario()->getUsu()->GetCelular())!= 0)
        throw invalid_argument("Usted no ha enviado este mensaje\n");
    Lista* ltVistos = m->getListaVistos(), *ltReturn = new Lista();

    IIterator *it = ltVistos->iterator();
    while (it->hasNext()) {
        Visto* v = dynamic_cast<Visto*> (it->getCurrent());
        Usuario* usu = Fabrica::getInstance()->getContUsuario()->getUsuByCel(v->getReceptor());
//        if (v->getEstado()) {
            dtmv = new DtMensajeVisto(usu->GetNombre(), usu->GetCelular(), v->getFechaHoraVisto(), v->getEstado());
            ltReturn->add(dtmv);
//        }
        it->next();
    }
    return ltReturn;
    
}

void ContMensaje::setIdMens(int id) {
    this->idMensaje = id;
}