/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conversacion.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:30 AM
 */

#include <memory>

#include "Conversacion.h"
#include "Fabrica.h"
#include "Simple.h"
#include "Contacto.h"
#include "Imagen.h"
#include "Video.h"
//#include "iContUsuario.h"

Conversacion::Conversacion() {
    iContUsuario* contU =Fabrica::getInstance()->getContUsuario();
    this->idConv = contU->getIdConv();
}
Conversacion::Conversacion(int conv) {
    this->idConv = conv;
}

Conversacion::Conversacion(const Conversacion& orig) {
}

Conversacion::~Conversacion() {

}

bool Conversacion::sosConversacion(int idConv) {
    if (this->idConv == idConv)return true;
    return false;
}

Mensaje* Conversacion::getMensaje(int idMensaje) {
    intKey *key = new intKey(idMensaje);
    Mensaje *men = (dynamic_cast<Mensaje*> (mensajes->find(key)));
    return men;
}



bool Conversacion::remueveMens(int Idmen) {
    intKey * Mkey=new intKey(Idmen);
    Mensaje * men=dynamic_cast<Mensaje*>(mensajes->find(Mkey));
    if(men->remueveVistos()==true){
        mensajes->removeKey(Mkey);
        mensajes->removeObj(men);
        delete men;
    }
    return true;
}
bool Conversacion::remueveMiVisto(int idMen, string idUsu){
intKey * Mkey=new intKey(idMen);
Mensaje * mens= dynamic_cast<Mensaje*>(mensajes->find(Mkey));
return mens->remueveMiVisto(idUsu);
}
bool Conversacion::esEmisor(int idMen, string idUsu){
    intKey *key=new intKey(idMen);
    Mensaje * men=dynamic_cast<Mensaje*>(mensajes->find(key));
    if(men->getEmisor()==idUsu){return true;}else return false;
}
bool Conversacion::existeMensaje(int idMen){
    intKey * key = new intKey(idMen);
    return mensajes->member(key);
}
bool Conversacion::esReceptor(int idMen,string idUsu){
    intKey * mKey=new intKey(idMen);
    Mensaje *men = dynamic_cast<Mensaje*>(mensajes->find(mKey));
    return men->esReceptor(idUsu);
}
void Conversacion::eviarMensaje(Mensaje* m) {
}

Lista* Conversacion::listarMensaje(DtFechaHoraIng *fecha_hora) {
    iContUsuario *contUsu = Fabrica::getInstance()->getContUsuario();
    iContFecha *contFecha = Fabrica::getInstance()->getContFecha();
    IIterator *it = mensajes->getIteratorObj(), *itt;
    Lista* listDtMensaje = new Lista();
    string celUsuLog = contUsu->getUsu()->GetCelular();
    DtHora* hora = contFecha->getFechaHora()->getHora();
    DtFecha* fecha = contFecha->getFechaHora()->getFecha();
    if (fecha_hora == NULL) {
        while (it->hasNext()) {
            if (dynamic_cast<Simple*> (it->getCurrent())) {
                Mensaje *men = dynamic_cast<Simple*> (it->getCurrent());
                IIterator *itt = men->getListaVistos()->iterator();
                
                while (itt->hasNext()) {
                    Visto *v = dynamic_cast<Visto*> (itt->getCurrent());
                    if (v->getEstado() == false && celUsuLog == v->getReceptor()) {
                        v->SetEstado(true);
                        v->SetFechaV(fecha);
                        v->SetHoraV(hora);
                    }
                    itt->next();
                }
                listDtMensaje->add(dynamic_cast<Simple*> (men)->getMensaje());
            }
            if (dynamic_cast<Contacto*> (it->getCurrent())) {
                Mensaje *men = dynamic_cast<Contacto*> (it->getCurrent());
//                int celUsuLog = contUsu->getUsu()->GetCelular();
                IIterator *itt = men->getListaVistos()->iterator();
                while (itt->hasNext()) {
                    Visto *v = dynamic_cast<Visto*>(itt->getCurrent());
                    if (!v->getEstado() && celUsuLog == v->getReceptor()) {
                        v->SetEstado(true);
                        v->SetFechaV(fecha);
                        v->SetHoraV(hora);
                    }
                    itt->next();
                }
                listDtMensaje->add(dynamic_cast<Contacto*> (men)->getMensaje());
            }
            if (dynamic_cast<Imagen*> (it->getCurrent())) {
                Mensaje *men = dynamic_cast<Imagen*> (it->getCurrent());
//                int celUsuLog = contUsu->getUsu()->GetCelular();
                IIterator *itt = men->getListaVistos()->iterator();
                while (itt->hasNext()) {
                    Visto *v = dynamic_cast<Visto*> (itt->getCurrent());
                    if (v->getEstado() == false && celUsuLog == v->getReceptor()) {
                        v->SetEstado(true);
                        v->SetFechaV(fecha);
                        v->SetHoraV(hora);
                    }
                    itt->next();
                }
                listDtMensaje->add(dynamic_cast<Imagen*> (men)->getMensaje());
                //it->next();
            }
            if (dynamic_cast<Video*> (it->getCurrent())) {
                Mensaje *men = dynamic_cast<Video*> (it->getCurrent());
//                int celUsuLog = contUsu->getUsu()->GetCelular();
                IIterator *itt = men->getListaVistos()->iterator();
                while (itt->hasNext()) {
                    Visto *v = dynamic_cast<Visto*> (itt->getCurrent());
                    if (!v->getEstado() && celUsuLog == v->getReceptor()) {
                        v->SetEstado(true);
                        v->SetFechaV(fecha);
                        v->SetHoraV(hora);
                    }
                    itt->next();
                }
                listDtMensaje->add(dynamic_cast<Video*> (men)->getMensaje());
                //it->next();
            }
            it->next();
        }
    } else {
        while (it->hasNext()) {
            if (dynamic_cast<Video*> (it->getCurrent())) {
                Mensaje *m = dynamic_cast<Video*> (it->getCurrent());
                if (m->GetFechaEnv()->GetAnio() >= fecha_hora->GetFecha()->GetAnio() && m->GetFechaEnv()->GetDia() >= fecha_hora->GetFecha()->GetDia()
                        && m->GetFechaEnv()->GetMes() >= fecha_hora->GetFecha()->GetMes() && m->GetHoraEnv()->GetHora() >= fecha_hora->GetHora()->GetHora() && m->GetHoraEnv()->GetMinutos() >=
                        fecha_hora->GetHora()->GetMinutos() && m->GetHoraEnv()->GetSegundo() >= fecha_hora->GetHora()->GetSegundo()) {
                    listDtMensaje->add(m->getMensaje());
                    IIterator *itt = m->getListaVistos()->iterator();
//                    int celUsuLog = contUsu->getUsu()->GetCelular();
                    while(itt->hasNext()) {
                        Visto *v = dynamic_cast<Visto*>(itt->getCurrent());
                        if(!v->getEstado() && celUsuLog == v->getReceptor()) {
                            v->SetEstado(true);
                            v->SetFechaV(fecha);
                            v->SetHoraV(hora);
                        }
                        itt->next();
                    }
                }
            }
            if (dynamic_cast<Imagen*> (it->getCurrent())) {
                Mensaje *m = dynamic_cast<Imagen*> (it->getCurrent());
                if (m->GetFechaEnv()->GetAnio() >= fecha_hora->GetFecha()->GetAnio() && m->GetFechaEnv()->GetDia() >= fecha_hora->GetFecha()->GetDia()
                        && m->GetFechaEnv()->GetMes() >= fecha_hora->GetFecha()->GetMes() && m->GetHoraEnv()->GetHora() >= fecha_hora->GetHora()->GetHora() && m->GetHoraEnv()->GetMinutos() >=
                        fecha_hora->GetHora()->GetMinutos() && m->GetHoraEnv()->GetSegundo() >= fecha_hora->GetHora()->GetSegundo()) {
                    listDtMensaje->add(m->getMensaje());
                    IIterator *itt = m->getListaVistos()->iterator();
//                    int celUsuLog = contUsu->getUsu()->GetCelular();
                    while(itt->hasNext()) {
                        Visto *v = dynamic_cast<Visto*>(itt->getCurrent());
                        if(!v->getEstado() && celUsuLog == v->getReceptor()) {
                            v->SetEstado(true);
                            v->SetFechaV(fecha);
                            v->SetHoraV(hora);
                        }
                        itt->next();
                    }
                }
            }
            if (dynamic_cast<Simple*> (it->getCurrent())) {
                Mensaje *m = dynamic_cast<Simple*> (it->getCurrent());
                if (m->GetFechaEnv()->GetAnio() >= fecha_hora->GetFecha()->GetAnio() && m->GetFechaEnv()->GetDia() >= fecha_hora->GetFecha()->GetDia()
                        && m->GetFechaEnv()->GetMes() >= fecha_hora->GetFecha()->GetMes() && m->GetHoraEnv()->GetHora() >= fecha_hora->GetHora()->GetHora() && m->GetHoraEnv()->GetMinutos() >=
                        fecha_hora->GetHora()->GetMinutos() && m->GetHoraEnv()->GetSegundo() >= fecha_hora->GetHora()->GetSegundo()) {
                    listDtMensaje->add(m->getMensaje());
                    IIterator *itt = m->getListaVistos()->iterator();
//                    int celUsuLog = contUsu->getUsu()->GetCelular();
                    while(itt->hasNext()) {
                        Visto *v = dynamic_cast<Visto*>(itt->getCurrent());
                        if(!v->getEstado() && celUsuLog == v->getReceptor()) {
                            v->SetEstado(true);
                            v->SetFechaV(fecha);
                            v->SetHoraV(hora);
                        }
                        itt->next();
                    }
                }
            }
            if (dynamic_cast<Contacto*> (it->getCurrent())) {
                Mensaje *m = dynamic_cast<Contacto*> (it->getCurrent());
                if (m->GetFechaEnv()->GetAnio() >= fecha_hora->GetFecha()->GetAnio() && m->GetFechaEnv()->GetDia() >= fecha_hora->GetFecha()->GetDia()
                        && m->GetFechaEnv()->GetMes() >= fecha_hora->GetFecha()->GetMes() && m->GetHoraEnv()->GetHora() >= fecha_hora->GetHora()->GetHora() && m->GetHoraEnv()->GetMinutos() >=
                        fecha_hora->GetHora()->GetMinutos() && m->GetHoraEnv()->GetSegundo() >= fecha_hora->GetHora()->GetSegundo()) {
                    listDtMensaje->add(m->getMensaje());
                    IIterator *itt = m->getListaVistos()->iterator();
//                    int celUsuLog = contUsu->getUsu()->GetCelular();
                    while(itt->hasNext()) {
                        Visto *v = dynamic_cast<Visto*>(itt->getCurrent());
                        if(!v->getEstado() && celUsuLog == v->getReceptor()) {
                            v->SetEstado(true);
                            v->SetFechaV(fecha);
                            v->SetHoraV(hora);
                        }
                        itt->next();
                    }
                }
            }
            it->next();
        }

    }
    return listDtMensaje;
}

Lista *Conversacion::listarVistos(int idMen) {
    Lista *listaMensVisto=new Lista();
    
    intKey *key = new intKey(idMen);
    
    Mensaje *men = dynamic_cast<Mensaje*> (mensajes->find(key));
    
    listaMensVisto = men->GetVistos();
    
    return listaMensVisto;
}

int Conversacion::getIdConv() {
    return idConv;
}

void Conversacion::setIdConv(int idConv) {
    this->idConv = idConv;
}

void Conversacion::setMensaje(Mensaje* mensaje) {
    intKey *key = new intKey(mensaje->GetCodigo());
    mensajes->add(mensaje, key);
}

string Conversacion::getCelContacto() {
    iContUsuario *contusu = Fabrica::getInstance()->getContUsuario();
    return contusu->getNumContacto(this->idConv);
}

string Conversacion::primerReceptor(){
    IIterator* it = this->mensajes->getIteratorObj();
    while (it->hasNext()){
        Lista* lVist = dynamic_cast<Mensaje*>(it->getCurrent())->getListaVistos();
        IIterator* itt = lVist->iterator();
        while (itt->hasNext()){
            return dynamic_cast<Visto*>(itt->getCurrent())->getReceptor();
        }
    }
}
//Lista* Conversacion::listarMensaje(DtFechaHoraIng *fecha_hora) {
//    iContUsuario *contUsu = Fabrica::getInstance()->getContUsuario();
//    IIterator *it = mensajes->getIteratorObj();
//    Lista* listDtMensaje = new Lista();
//    if (fecha_hora == NULL) {
//        while (it->hasNext()) {
//            if (dynamic_cast<Simple*> (it->getCurrent())) {
//                Mensaje *men = dynamic_cast<Simple*> (it->getCurrent());
//                men->esReceptor(contUsu->getNumUsuLog());
//                
//                listDtMensaje->add(dynamic_cast<Simple*>(men)->getMensaje());
//                //it->next();
//            }
//            if (dynamic_cast<Contacto*> (it->getCurrent())) {
//                Mensaje *men = dynamic_cast<Contacto*> (it->getCurrent());
//                men->esReceptor(contUsu->getNumUsuLog());
//                listDtMensaje->add(dynamic_cast<Contacto*>(men)->getMensaje());
//                //it->next();
//            }
//            if (dynamic_cast<Imagen*> (it->getCurrent())) {
//                Mensaje *men = dynamic_cast<Imagen*> (it->getCurrent());
//                men->esReceptor(contUsu->getNumUsuLog());
//                listDtMensaje->add(dynamic_cast<Imagen*>(men)->getMensaje());
//                //it->next();
//            }
//            if (dynamic_cast<Video*> (it->getCurrent())) {
//                Mensaje *men = dynamic_cast<Video*> (it->getCurrent());
//                men->esReceptor(contUsu->getNumUsuLog());
//                listDtMensaje->add(dynamic_cast<Video*>(men)->getMensaje());
//                //it->next();
//            }
//            it->next();
//        }
//    } else {
//        while (it->hasNext()) {
//            if (dynamic_cast<Video*> (it->getCurrent())) {
//                Mensaje *m = dynamic_cast<Video*> (it->getCurrent());
//            if (m->GetFechaEnv()->GetAnio() >= fecha_hora->GetFecha()->GetAnio() && m->GetFechaEnv()->GetDia() >= fecha_hora->GetFecha()->GetDia()
//                    && m->GetFechaEnv()->GetMes() >= fecha_hora->GetFecha()->GetMes() && m->GetHoraEnv()->GetHora() >= fecha_hora->GetHora()->GetHora() && m->GetHoraEnv()->GetMinutos() >=
//                    fecha_hora->GetHora()->GetMinutos() && m->GetHoraEnv()->GetSegundo() >= fecha_hora->GetHora()->GetSegundo()) {
//                listDtMensaje->add(m->getMensaje());
//                m->esReceptor(contUsu->getNumUsuLog());
//            }}
//             if (dynamic_cast<Imagen*> (it->getCurrent())) {
//                  Mensaje *m = dynamic_cast<Imagen*> (it->getCurrent());
//              if (m->GetFechaEnv()->GetAnio() >= fecha_hora->GetFecha()->GetAnio() && m->GetFechaEnv()->GetDia() >= fecha_hora->GetFecha()->GetDia()
//                    && m->GetFechaEnv()->GetMes() >= fecha_hora->GetFecha()->GetMes() && m->GetHoraEnv()->GetHora() >= fecha_hora->GetHora()->GetHora() && m->GetHoraEnv()->GetMinutos() >=
//                    fecha_hora->GetHora()->GetMinutos() && m->GetHoraEnv()->GetSegundo() >= fecha_hora->GetHora()->GetSegundo()) {
//                listDtMensaje->add(m->getMensaje());
//                m->esReceptor(contUsu->getNumUsuLog());
//            }}
//             if (dynamic_cast<Simple*> (it->getCurrent())) {
//                       Mensaje *m = dynamic_cast<Simple*> (it->getCurrent());
//              if (m->GetFechaEnv()->GetAnio() >= fecha_hora->GetFecha()->GetAnio() && m->GetFechaEnv()->GetDia() >= fecha_hora->GetFecha()->GetDia()
//                    && m->GetFechaEnv()->GetMes() >= fecha_hora->GetFecha()->GetMes() && m->GetHoraEnv()->GetHora() >= fecha_hora->GetHora()->GetHora() && m->GetHoraEnv()->GetMinutos() >=
//                    fecha_hora->GetHora()->GetMinutos() && m->GetHoraEnv()->GetSegundo() >= fecha_hora->GetHora()->GetSegundo()) {
//                listDtMensaje->add(m->getMensaje());
//                m->esReceptor(contUsu->getNumUsuLog());
//            }
//            }
//            if (dynamic_cast<Contacto*> (it->getCurrent())) {
//                      Mensaje *m = dynamic_cast<Contacto*> (it->getCurrent());
//              if (m->GetFechaEnv()->GetAnio() >= fecha_hora->GetFecha()->GetAnio() && m->GetFechaEnv()->GetDia() >= fecha_hora->GetFecha()->GetDia()
//                    && m->GetFechaEnv()->GetMes() >= fecha_hora->GetFecha()->GetMes() && m->GetHoraEnv()->GetHora() >= fecha_hora->GetHora()->GetHora() && m->GetHoraEnv()->GetMinutos() >=
//                    fecha_hora->GetHora()->GetMinutos() && m->GetHoraEnv()->GetSegundo() >= fecha_hora->GetHora()->GetSegundo()) {
//                listDtMensaje->add(m->getMensaje());
//                m->esReceptor(contUsu->getNumUsuLog());
//            }
//            }
//            it->next();
//        }
//
//    }
//    return listDtMensaje;
//}