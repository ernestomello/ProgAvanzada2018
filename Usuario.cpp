/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:30 AM
 */

#include <memory>

#include "Usuario.h"
#include "Fabrica.h"

void Usuario::addContacto(Usuario* u) {
    StringKey* ikey = new StringKey(u->GetCelular());
    this->contactos->add(u, ikey);
}

void Usuario::setIdConvGrupo(int id) {
    IIterator *it = tipo->iterator();
    Tipo *t = dynamic_cast<Tipo*> (it->getCurrent());
    t->getGrupo()->getConversacion()->setIdConv(id);

}

Usuario::Usuario(string nombre, string imagenPerfil, string descripcion, string numCel) {
    Fecha_Hora_sis* fechora;
    this->nombre = nombre;
    this->foto_Perfil = imagenPerfil;
    this->descripcion = descripcion;
    this->celular = numCel;
    this->fechaCreacion = fechora->getFecha();
    this->horaCreacion = fechora->getHora();
    this->SetUltima_conexion(fechora->getUltimaConexion());
}

//Usuario::Usuario(string celUsu,string nombre,string UrlImagen,string descripcion){
//    Fecha_Hora_sis* fechora;
//    this->nombre = nombre;
//    this->foto_Perfil = UrlImagen;
//    this->descripcion = descripcion;
//    this->celular = celUsu;
//    this->fechaCreacion = fechora->getFecha();
//    this->horaCreacion = fechora->getHora();
//    this->SetUltima_conexion(fechora->getUltimaConexion());
//}

ListDicc* Usuario::getListaContactos() {
    return this->contactos;
}

Usuario::Usuario(const Usuario& orig) {
}

Usuario::~Usuario() {
}

string Usuario::GetCelular() {
    return celular;
}

void Usuario::SetCelular(string celular) {
    this->celular = celular;
}

DtContacto* Usuario::GetContacto() {
    DtContacto* DtCont = new DtContacto(this->nombre, this->celular, this->foto_Perfil);
    DtCont->setDesc(this->descripcion);
    return DtCont;
}

void Usuario::SetContacto(Usuario * contacto) {
    StringKey * key = new StringKey(contacto->GetCelular());
    this->contactos->add(contacto, key);
}

string Usuario::GetDescripcion() {
    return descripcion;
}

void Usuario::SetDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Usuario::SetEstadoConv(EstadoConv* estado) {
    this->estadoConv->add(estado);
}

DtFecha* Usuario::GetFechaCreacion() {
    return fechaCreacion;
}

void Usuario::SetFechaCreacion(DtFecha *fechaCreacion) {
    this->fechaCreacion = fechaCreacion;
}

string Usuario::GetFoto_Perfil() {
    return foto_Perfil;
}

void Usuario::SetFoto_Perfil(string foto_Perfil) {
    this->foto_Perfil = foto_Perfil;
}

DtHora* Usuario::GetHoraCreacion() {
    return horaCreacion;
}

void Usuario::SetHoraCreacion(DtHora * horaCreacion) {
    this->horaCreacion = horaCreacion;
}

string Usuario::GetNombre() {
    return this->nombre;
}

void Usuario::SetNombre(string nombre) {
    this->nombre = nombre;
}

void Usuario::SetTipo(Tipo * tip) {
    tipo->add(tip);
}

DtUltCon* Usuario::GetUltima_conexion() {
    return ultima_conexion;
}

void Usuario::SetUltima_conexion(DtUltCon* ultima_conexion) {
    this->ultima_conexion = ultima_conexion;
}

Lista * Usuario::getConversaciones(string options) {
    if (estadoConv->isEmpty() == true && options.compare("enviarMensaje") != 0) {
        throw invalid_argument("No tiene conversaciones");
    }
    Lista *conversacionesAct = new Lista();
    IIterator *it = estadoConv->iterator();
    int cant = 0, cont = 0;

    while (it->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->ConvActiva() == true) {
            if (convGrupal(ec->getConversacion()->getIdConv()) == false) {
                DtConversacion * DtConv = new DtConversacion(ec->getConversacion()->getIdConv(), atoi(ec->getConversacion()->getCelContacto().c_str())); //constructor conv comun
                int celCont = atoi(ec->getConversacion()->getCelContacto().c_str());
                conversacionesAct->add(DtConv);
            }
            else {
                conversacionesAct->add(getConvGrupo(ec->getConversacion()->getIdConv()));
            }
        }
        else {
            cant++;
        }
        it->next();
    }
    DtConversacion * DtConv = new DtConversacion(cant); //constructor conv archivadas
    conversacionesAct->add(DtConv);
    return conversacionesAct;
}

bool Usuario::convGrupal(int idconv) {
    IIterator *it = tipo->iterator();
    while (it->hasNext()) {
        Tipo *tip = dynamic_cast<Tipo*> (it->getCurrent());
        if (tip->getGrupo()->getConversacion()->getIdConv() == idconv)return true;
        it->next();
    }
    return false;
}

DtConversacion* Usuario::getConvGrupo(int idconv) {
    IIterator *it = tipo->iterator();
    while (it->hasNext()) {
        Tipo *tip = dynamic_cast<Tipo*> (it->getCurrent());
        if (tip->getGrupo()->getConversacion()->getIdConv() == idconv) {
            DtConversacion * dtConv = new DtConversacion(tip->getGrupo()->GetNombre(), tip->getGrupo()->getConversacion()->getIdConv()); //copntructor grupo
            return dtConv;

        }
        it->next();

    }
}

Lista * Usuario::getConversacionesAr() {
    Lista *conversacionesArc = new Lista();
    IIterator * it = estadoConv->iterator();

    while (it->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->ConvActiva() == false) {
            if (convGrupal(ec->getConversacion()->getIdConv()) == false) {
                DtConversacion * DtConv = new DtConversacion(ec->getConversacion()->getIdConv(), atoi(ec->getConversacion()->getCelContacto().c_str())); //constructor conv comun
                conversacionesArc->add(DtConv);
            } else {
                conversacionesArc->add(getConvGrupo(ec->getConversacion()->getIdConv()));
            }
        }
        it->next();
    }
    return conversacionesArc;
}

Lista * Usuario::GetContactos(string fromFunction) {
    if (this->contactos->size() == 0 && fromFunction.compare("enviarMensaje") == 0) {
        throw invalid_argument("No tiene contactos\n");
    }
    Lista* Dtcontactos = new Lista();
    IIterator * it = contactos->getIteratorObj();
    while (it->hasNext()) {
        Usuario* cont = dynamic_cast<Usuario*> (it->getCurrent());
        Dtcontactos->add(cont->GetContacto());
        it->next();
    }
    return Dtcontactos;
}

void Usuario::crearConvGrupo(Conversacion *conv) {
}

Usuario * Usuario::seleccionarCont(string numCel) {
    StringKey *key = new StringKey(numCel);

    Usuario * cont = dynamic_cast<Usuario*> (contactos->find(key));
    return cont;
}

Lista * Usuario::seleccionarConversacion(int idconv) {
    Lista *lM = new Lista();
    lM = listarMensajes(idconv);
    return lM;
}

void Usuario::crearConversacion(Conversacion *conv) {
    EstadoConv *eC = new EstadoConv(true, conv);
    this->estadoConv->add(eC);
}

void Usuario::crearEstadoConv(Conversacion *conv, Usuario * cont, Usuario * usuAct) {
    EstadoConv *ec = new EstadoConv(usuAct, conv);
    cont->estadoConv->add(ec);
}

bool Usuario::sosElOtro(int idConv) {
    IIterator *it = estadoConv->iterator();
    while (it->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->getConversacion()->getIdConv() == idConv) return true;
        it->next();
    }
    return false;
}

Lista * Usuario::listarMensajes(int codConv) {
    Lista *listaMen = new Lista();
    IIterator *It = estadoConv->iterator();
    while (It->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (It->getCurrent());
        if (ec->getConversacion()->sosConversacion(codConv) == true) {
            listaMen = ec->getConversacion()->listarMensaje(NULL);
            return listaMen;
        }
        It->next();
    }
}

Lista * Usuario::listarVistos(int idMens, int idConv) {
    Lista *vistos = new Lista();
    IIterator *it = estadoConv->iterator();
    while (it->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->getConversacion()->getIdConv() == idConv) {
            vistos = ec->getConversacion()->listarVistos(idMens);
        }
        it->next();
    }

}

string Usuario::getNumContacto(int idConv) {
    IIterator *it = contactos->getIteratorObj();
    while (it->hasNext()) {
        Usuario* usu = dynamic_cast<Usuario*> (it->getCurrent());
        if (usu->sosElOtro(idConv) == true) {
            return usu->GetCelular();
        }
        it->next();
    }
    iContUsuario* cont= Fabrica::getInstance()->getContUsuario();
    return cont->getOtroContacto(idConv);
    
 }

string Usuario::nombreUsu(string numCel) {
    StringKey *iKey = new StringKey(numCel);
    Usuario *us = dynamic_cast<Usuario*> (this->contactos->find(iKey));
    return us->GetNombre();
}

void Usuario::crearTipo(Grupo* grupo, string estipo, DtUltCon* fecha) {
    Tipo * tipos = new Tipo(grupo, estipo, fecha);
    this->tipo->add(tipos);
}

void Usuario::crearEstadoConversacion(Conversacion *conv) {
    EstadoConv *eC = new EstadoConv(false, conv);
    this->estadoConv->add(eC);
}

Lista * Usuario::getTipos() {

    Lista* dtTipo = new Lista();
    IIterator * it = tipo->iterator();
    while (it->hasNext()) {
        Tipo* cont = dynamic_cast<Tipo*> (it->getCurrent());
        dtTipo->add(cont->getGrupos());
        it->next();
    }
    return dtTipo;
}

Lista * Usuario::getContactosGrupo(string grupo) { //aca trae la lista de contactos viend cuales son los contactos , entrando a la lita de tipos y ahí al grupo
    Lista* Dtcontactos = new Lista();
    DtContactoGrupo * contGrup;
    IIterator * ita = tipo->iterator();
    while (ita->hasNext()) {
        Tipo* Tip = dynamic_cast<Tipo*> (ita->getCurrent());
        if (Tip->getGrupo()->GetNombre() == grupo) {
            contGrup = new DtContactoGrupo(this->celular, this->nombre, Tip->GetTipo(), Tip->GetFechaIng(), Tip->GetHoraIng());
            Dtcontactos->add(contGrup);
            break;
        }
        ita->next();
    }
    IIterator * it = contactos->getIteratorObj();
    while (it->hasNext()) {
        Usuario* cont = dynamic_cast<Usuario*> (it->getCurrent());

        //Lista* listaTipo = cont->tipo;
        IIterator * itt = cont->tipo->iterator();
        while (itt->hasNext()) {
            Tipo* tip = dynamic_cast<Tipo*> (itt->getCurrent());
            if (tip->getGrupo()->GetNombre() == grupo) {
                contGrup = new DtContactoGrupo(cont->celular, cont->nombre, tip->GetTipo(), tip->GetFechaIng(), tip->GetHoraIng());
                Dtcontactos->add(contGrup);
                break;
            }
            itt->next();
        }
        it->next();
    }
    return Dtcontactos;
}

Lista* Usuario::getContactosGrupo(int idConv) {
    Lista* usuarios = new Lista();
    IIterator *it = this->contactos->getIteratorObj();
    while (it->hasNext()) {
        Usuario *cont = dynamic_cast<Usuario*> (it->getCurrent());
        IIterator *itt = cont->tipo->iterator();
        while (itt->hasNext()) {
            Tipo* tip = dynamic_cast<Tipo*> (itt->getCurrent());
            if (tip->getGrupo()->getConversacion()->getIdConv() == idConv) {
                usuarios->add(cont);
            }
            itt->next();
        }
        it->next();
    }
    return usuarios;
}

//Conversacion* Usuario::getConversacion(int idConv) {
//    IIterator *it = this->estadoConv->iterator();
//    while(it->hasNext()){
//        EstadoConv* ec = dynamic_cast<EstadoConv*>(it->getCurrent());
//        if(ec->getConversacion()->getIdConv() == idConv)
//            return ec->getConversacion();
//        it->next();
//    }
//    return NULL;
//}

Conversacion* Usuario::getConversacion(int idConv) {
    IIterator *it = this->estadoConv->iterator();
    while (it->hasNext()) {
        EstadoConv* ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->getConversacion()->getIdConv() == idConv)
            return ec->getConversacion();
        it->next();
    }
    return NULL;
}

Grupo* Usuario::getGrupo(string grupo) {
    Grupo* devGrupo = NULL;
    IIterator * itt = this->tipo->iterator();
    while (itt->hasNext()) {
        Tipo* tip = dynamic_cast<Tipo*> (itt->getCurrent());
        if (tip->getGrupo()->GetNombre() == grupo) {
            devGrupo = tip->getGrupo();
            break;
        }
        itt->next();
    }
    if (devGrupo == NULL)
        throw invalid_argument("El Grupo Ingresado no Existe!!\n");
    return devGrupo;
}

void Usuario::archivaConversacion(int conversa) {

    IIterator * itt = this->estadoConv->iterator();
    while (itt->hasNext()) {
        EstadoConv* tip = dynamic_cast<EstadoConv*> (itt->getCurrent());
        if (tip->getConversacion()->getIdConv() == conversa) {
            tip->setEstado(true);
            break;
        }
        itt->next();
    }
}

void Usuario::setFechaHoraG(DtFecha* fecha, DtHora* hora) {
    IIterator *it = tipo->iterator();
    while (it->hasNext()) {
        Tipo *t = dynamic_cast<Tipo*> (it->getCurrent());
        if (t->getGrupo()->GetCreador() == this->celular) {
            t->getGrupo()->SetFecha(fecha);
            t->getGrupo()->SetHora(hora);

        }
        it->next();
    }
}

void Usuario::setMensaje(Mensaje* m, int idConv) {
    IIterator* it = estadoConv->iterator();

    while (it->hasNext()) {
        EstadoConv* ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->getConversacion()->getIdConv() == idConv) {
            ec->getConversacion()->setMensaje(m);
        }
        it->next();
    }

}

Lista * Usuario::GetContactos() {
    Lista * Dtcontactos = new Lista();
    IIterator * it = contactos-> getIteratorObj();
    while (it-> hasNext()) {
        Usuario * cont = dynamic_cast<Usuario *> (it-> getCurrent());
        Dtcontactos-> add(cont-> GetContacto());
        it-> next();
    }
    return Dtcontactos;
}

Lista * Usuario::getConversaciones() {
    if (estadoConv->isEmpty() == true) {
        throw invalid_argument("No tiene conversaciones");
    }
    Lista *conversacionesAct = new Lista();
    IIterator *it = estadoConv->iterator();
    int cant = 0, cont = 0;

    while (it->hasNext()) {
        EstadoConv* ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->ConvActiva() == true) {
            if (convGrupal(ec->getConversacion()->getIdConv()) == false) {
                DtConversacion * DtConv = new DtConversacion(ec->getConversacion()->getIdConv(), atoi(ec->getConversacion()->getCelContacto().c_str())); //constructor conv comun
                conversacionesAct->add(DtConv);
                //            it->next();
            } else {
                conversacionesAct->add(getConvGrupo(ec->getConversacion()->getIdConv()));
                //                it->next();
            }
            it->next();
        } else {
            cant++;
            it->next();
        }
    }
    DtConversacion * DtConv = new DtConversacion(cant); //constructor conv archivadas
    conversacionesAct->add(DtConv);
    return conversacionesAct;
}

bool Usuario::existeConversacion(int idConv) {
    IIterator *it = estadoConv->iterator();
    while (it->hasNext()) {
        EstadoConv * ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->getConversacion()->getIdConv() == idConv) {
            return true;
        }
        it->next();
    }
    return false;
}

bool Usuario::esReceptor(int idMen, int idConv) {
    IIterator *it = estadoConv->iterator();

    while (it->hasNext()) {
        EstadoConv * ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->getConversacion()->getIdConv() == idConv) {
            return ec->getConversacion()->esReceptor(idMen, this->celular);
        }
        it->next();
    }
    return false;
}

//Lista * Usuario::listarMensajes(int codConv) {
//    Lista *listaMen = new Lista();
//    IIterator *it = tipo->iterator();
//    while(it->hasNext()){
//        Tipo * ti= dynamic_cast<Tipo*>(it->getCurrent());
//        if(ti->getGrupo()->getConversacion()->sosConversacion(codConv)==true){
//           listaMen= ti->getGrupo()->getConversacion()->listarMensaje(ti->getFechaHoraIng());
//           return listaMen;
//        }
//        
//        it->next();
//    }
//    it= estadoConv->iterator();
//    while(it->hasNext()){
//        EstadoConv * ec= dynamic_cast<EstadoConv*>(it->getCurrent());
//        if(ec->getConversacion()->sosConversacion(codConv)==true){
//            listaMen=ec->getConversacion()->listarMensaje(NULL);
//            return listaMen;
//        }
//        
//        it->next();
//    }
//    
//}
