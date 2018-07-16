/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContUsuario.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:47 AM
 */

#include "ContUsuario.h"
#include "Fabrica.h"

using namespace std;

int ContUsuario::getIdConv() {
    this->idConv = this->idConv + 1;
    return this->idConv;
}

string ContUsuario::getNumContacto(int idConv) {
    return this->usuLog->getNumContacto(idConv);
}

ContUsuario::ContUsuario() {
}

ContUsuario::ContUsuario(const ContUsuario& orig) {
}

ContUsuario::~ContUsuario() {
}

Lista* ContUsuario::listarInfoVisto(int idConv, int idMensaje) {
    Lista* lMen = new Lista();
    lMen = this->usuLog->listarVistos(idMensaje, idConv);
    return lMen;
}

bool ContUsuario::usuarioLogueado(string numCel) {
    if (usuLog->GetCelular() == numCel)return true;
    return false;
}

bool ContUsuario::ingresarCelular(string numCel) {
    StringKey* ikey = new StringKey(numCel);
    bool ok = this->usuario->member(ikey);
    setNumCel(numCel);
    return ok;
}

bool ContUsuario::altaUsuario(string nombre, string UrlImagen, string descripcion) {
    Usuario* nuevoUsu = new Usuario(nombre, UrlImagen, descripcion, this->getNumCel());
    StringKey* key = new StringKey(this->getNumCel());
    usuario->add(nuevoUsu, key); //Agrego al usuario a la lista de usuarios
    return true;
}

void ContUsuario::altaPrecargaUsuario(string celUsu, string nombre, string UrlImagen, string descripcion) {
    Usuario* nuevoUsu = new Usuario(nombre, UrlImagen, descripcion, celUsu);
    StringKey* key = new StringKey(celUsu);
    usuario->add(nuevoUsu, key); //Agrego al usuario a la lista de usuarios
    //    return true;
}

bool ContUsuario::cancelaIngreso() {
    StringKey *ikey = new StringKey(getNumCel());
    Usuario *usuR = dynamic_cast<Usuario*> (usuario->find(ikey));
    Usuario *aux1 = dynamic_cast<Usuario*> (usuario->removeObj(usuR));
    delete aux1;
    intKey *key = dynamic_cast<intKey*> (usuario->removeKey(ikey));
    delete(key);
}

DtConexion* ContUsuario::asignarSesion() {
    StringKey *ikey = new StringKey(this->numCel);
    Usuario * usU = dynamic_cast<Usuario*> (usuario->find(ikey));
    this->usuLog = usU;
    //Fecha_Hora_sis* a;
    usU->SetUltima_conexion(Fabrica::getInstance()->getContFecha()->getFechaHora()); // Esto tiene error y no tenog ni puta idea de que es!
    DtConexion* r = new DtConexion();
    return r;
}

Usuario* ContUsuario::getUsu() {
    return this->usuLog;
}

Usuario* ContUsuario::getUsuario(string celUsu) {
    StringKey *key = new StringKey(celUsu);
    Usuario * usu = dynamic_cast<Usuario*> (usuario->find(key));
    return usu;

}

//Lista *ContUsuario::listarContactos() {
//    Lista* listDtContacto = new Lista();
//    intKey* ikey = new intKey(this->numCel);
//    Usuario* u = dynamic_cast<Usuario*> (this->usuario->find(ikey));
//    Lista* contactos = u->GetContactos();
//    if (contactos->isEmpty()) {
//        return listDtContacto;
//    } else {
//        IIterator* i = contactos->iterator();
//        while (i->hasNext()) {
//            u = dynamic_cast<Usuario*> (i->getCurrent());
//            DtContacto* dtc = new DtContacto();
//            dtc = u->GetContacto();
//            listDtContacto->add(dtc);
//        }
//    }
//    return listDtContacto;
//}

Lista *ContUsuario::listarContactos(string fromFunction) {
    StringKey* ikey = new StringKey(this->numCel);
    Usuario* u = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    return u->GetContactos(fromFunction);
}

Lista * ContUsuario::listarConversacion() {
    Lista * listaConv = this->usuLog->getConversaciones();
    return listaConv;
}

Lista * ContUsuario::listarConversacion(string option) {
    Lista * listaConv = this->usuLog->getConversaciones(option);
    return listaConv;
}

Lista * ContUsuario::seleccionarConversacion(int idConv) {
    Lista * selecConv = this->usuLog->seleccionarConversacion(idConv);
    return selecConv;
}

bool ContUsuario::eliminarMensaje(int idMen, int idConv) {
    if (usuLog->existeConversacion(idConv) == true) {
        if (usuLog->getConversacion(idConv)->existeMensaje(idMen) == true) {
            if (usuLog->esReceptor(idMen, idConv) == true) {
                //usuLog->getConversacion(idConv)->remueveMiVisto(idMen, usuLog->GetCelular());
                return usuLog->getConversacion(idConv)->remueveMens(idMen);
            } else {
                if (usuLog->getConversacion(idConv)->esEmisor(idMen, usuLog->GetCelular()) == true) {

                    return usuLog->getConversacion(idConv)->remueveMens(idMen);
                }
            }
        }
        throw invalid_argument("No existe el mensaje");
    }
    throw invalid_argument("No existe la conversacion");

}

DtContacto* ContUsuario::ingContacto(string numCelular) {
    StringKey* ikey = new StringKey(numCelular);
    Usuario* usu = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    DtContacto* dtc = NULL;
    if (usu != NULL) {
        dtc = new DtContacto();
        dtc = usu->GetContacto();
    }
    return dtc;
}

//void ContUsuario::altaPrecargaContacto(int numCelular) {
//    intKey* ikey = new intKey(numCelular);
//    Usuario* usu = dynamic_cast<Usuario*> (this->usuario->find(ikey));
//    if (usu != NULL) {
//        if (numCelular == 90123654) {
//            usu->addContacto(usu->seleccionarCont(90765432));
//            usu->addContacto(usu->seleccionarCont(90246810));
//            usu->addContacto(usu->seleccionarCont(90666777));
//        }
//        if (numCelular == 90765432) {
//            usu->addContacto(usu->seleccionarCont(90123654));
//            usu->addContacto(usu->seleccionarCont(90246810));
//        }
//        if (numCelular == 90246810) {
//            usu->addContacto(usu->seleccionarCont(90123654));
//            usu->addContacto(usu->seleccionarCont(90765432));
//            usu->addContacto(usu->seleccionarCont(90666777));
//        }
//        if (numCelular == 90666777) {
//            usu->addContacto(usu->seleccionarCont(90123654));
//            usu->addContacto(usu->seleccionarCont(90246810));
//        }
//    }
//}

//void ContUsuario::altaPrecargaConversacion(){
//    
//}

void ContUsuario::agregaContacto(DtContacto* dtc) {
    StringKey* ikey = new StringKey(dtc->GetNumCel());
    Usuario* usu = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    this->usuLog->addContacto(usu);
}

void ContUsuario::cerrarSesion(DtConexion*) {
    Fecha_Hora_sis* fhs;
    DtUltCon* ultc = fhs->getUltimaConexion();
    this->usuLog->SetUltima_conexion(ultc);
    this->usuLog = NULL;
}

string ContUsuario::getNumUsuLog() {
    return this->usuLog->GetCelular();
}

void ContUsuario::modificarPerfil(string, string, string) {
}

void ContUsuario::actualizarDatos() {
}

void ContUsuario::setNumCel(string numCel) {
    this->numCel = numCel;
}

string ContUsuario::getNumCel() {
    return numCel;
}

void ContUsuario::setUltimaCon(DtUltCon*) {

}

void ContUsuario::setUsuLog(Usuario * usu) {
    this->usuLog = usu;

}

string ContUsuario::getNombreCont(string receptor) {
    return usuLog->nombreUsu(receptor); //tre el nombre del receptor

}

Lista* ContUsuario::listaConversacion() {
    Usuario* usuLog = getUsu();
    Lista *listConv;
    listConv = usuLog->getConversaciones("p");
    return listConv;
}

Lista* ContUsuario::listaConversacionArc() {
    Usuario* usuLog = getUsu();
    Lista* listConvArch;
    listConvArch = usuLog->getConversacionesAr();
    if (listConvArch == NULL)
        throw invalid_argument("\nNo existen Conversaciones Archivadas\n");
    return listConvArch;
}

void ContUsuario::crearTipoUsuario(Grupo* grupo, string celular) {
    DtUltCon* fecha = Fabrica::getInstance()->getContFecha()->getFechaHora();
    StringKey *ikey = new StringKey(celular);
    Usuario * usU = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    if (usU != NULL) {
        //crea el Tipo y le setea el grupo
        if (usU->GetCelular() == this->usuLog->GetCelular()) {
            usU->crearTipo(grupo, "Admin", fecha);
        } else {
            usU->crearTipo(grupo, "Usuario", fecha);
        }
    }

}

void ContUsuario::elijeContacto(string celUsu) {

    StringKey *ikey = new StringKey(celUsu);
    if (!this->usuario->member(ikey))
        throw invalid_argument("\nNo es un contacto del Usuario \n");
    Usuario* u = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    this->contactoReceptor = celUsu;
    Conversacion *conv = new Conversacion();
   // EstadoConv *ec1 = new EstadoConv(false, conv), *ec2 = new EstadoConv(false, conv);
    this->usuLog->crearEstadoConversacion(conv);
    u->crearEstadoConversacion(conv);
    Fabrica::getInstance()->getContMensaje()->selecConversacion(conv->getIdConv());
}

Conversacion* ContUsuario::getConversacion(int idConv) {
    return this->usuLog->getConversacion(idConv);
}

string ContUsuario::getReceptor() {
    return this->contactoReceptor;
}
void ContUsuario::setReceptor(string celular) {
    this->contactoReceptor = celular;
}

Usuario* ContUsuario::getUsuByCel(string celUsu) {
    StringKey *ikey = new StringKey(celUsu);
    return dynamic_cast<Usuario*> (this->usuario->find(ikey));
}
//Conversacion* ContUsuario::getConversacion(int idConv) {
//    return this->usuLog->getConversacion(idConv);
//}

void ContUsuario::altaPrecargaContacto(string numCelular) {
    StringKey* ikey = new StringKey(numCelular);
    Usuario* usu = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    if (usu != NULL) {
        if (numCelular.compare("090123654") == 0) {//90123654
            StringKey* key = new StringKey("090765432"); //90765432
            StringKey* key1 = new StringKey("090246810"); //90246810
            StringKey* key2 = new StringKey("090666777"); //90666777
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key1)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key2)));
            delete(key);
            delete(key1);
            delete(key2);
        }

        if (numCelular == "090765432") {//90765432
            StringKey* key3 = new StringKey("090123654"); //90123654
            StringKey* key4 = new StringKey("090246810"); //90246810
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key3)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key4)));
            delete(key3);
            delete(key4);
        }
        if (numCelular == "090246810") { //90246810
            StringKey* key5 = new StringKey("090123654"); //90123654
            StringKey* key6 = new StringKey("090765432"); //90765432
            StringKey* key7 = new StringKey("090666777"); //90666777
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key5)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key6)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key7)));
            delete(key5);
            delete(key6);
            delete(key7);
        }
        if (numCelular == "090666777") { //90666777
            StringKey* key8 = new StringKey("090123654"); //90123654
            StringKey* key9 = new StringKey("090246810"); //90246810
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key8)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key9)));
            delete(key8);
            delete(key9);
        }
    }

}

void ContUsuario::altaPrecargaConversacion() {
    Conversacion * conv1 = new Conversacion(2);
    Conversacion * conv2 = new Conversacion(3);
    StringKey * key1 = new StringKey("090123654"); //90123654
    StringKey * key2 = new StringKey("090765432"); //90765432
    StringKey * key3 = new StringKey("090246810"); //90246810
    StringKey * key4 = new StringKey("090666777"); //90666777

    Usuario* u1 = dynamic_cast<Usuario*> (usuario->find(key1));
    u1->crearEstadoConversacion(conv1);
    Usuario* u2 = dynamic_cast<Usuario*> (usuario->find(key2));
    u2->crearEstadoConversacion(conv1);
    Usuario* u3 = dynamic_cast<Usuario*> (usuario->find(key3));
    u3->crearEstadoConversacion(conv2);
    Usuario* u4 = dynamic_cast<Usuario*> (usuario->find(key4));
    u4->crearEstadoConversacion(conv2);
    this->idConv = 3;
}

void ContUsuario::setFechaHoraG(DtFecha* fech, DtHora * hora) {
    usuLog->setFechaHoraG(fech, hora);
}

int ContUsuario::generarIdConv() {
    Conversacion* conversa = new Conversacion();
    return conversa->getIdConv();
}

void ContUsuario::setIdConvGrupo(string idUsu) {
    StringKey *key = new StringKey(idUsu);
    Usuario *us = dynamic_cast<Usuario*> (usuario->find(key));
    us->setIdConvGrupo(1);
    this->idConv = 2;
}


string ContUsuario::getOtroContacto(int idConv){
    IIterator* it = usuario->getIteratorObj();
    while(it->hasNext()){
        Usuario * usu = dynamic_cast<Usuario *>(it->getCurrent());
        if (usu->existeConversacion(idConv) == true){
            return usu->GetCelular();
        }
        
        
        it->next();
    }
}