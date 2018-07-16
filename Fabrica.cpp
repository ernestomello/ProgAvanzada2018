/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fabrica.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:40 AM
 */

#include "Fabrica.h"
#include "Video.h"
#include "Contacto.h"

Fabrica* Fabrica::fabrica = NULL;

Fabrica::Fabrica() {
}

Fabrica::~Fabrica() {
}

Fabrica* Fabrica::getInstance() {
    if (fabrica == NULL) {
        fabrica = new Fabrica();
    }
    return fabrica;
}

iContUsuario* Fabrica::getContUsuario() {
    if (cUsu == NULL)
        this->cUsu = new ContUsuario();
    return this->cUsu;
}

iContMensaje* Fabrica::getContMensaje() {
    if (this->cMens == NULL)
        this->cMens = new ContMensaje();
    return this->cMens;
}

iContGrupo* Fabrica::getContGrupo() {
    if (cGru == NULL)
        this->cGru = new ContGrupo();
    return this->cGru;
}

iContFecha* Fabrica::getContFecha(){
    if(this->cFec == NULL)
        this->cFec = new ContFecha();
    return this->cFec;
}
void Fabrica::cargarDatosPrueba(){

    cargarUsu();
    cargarContactos();
    cargaGrupo();
    cargarConversaciones();
    cargarMensajes();

}
void Fabrica::cargarUsu(){
        
        iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
        string nombre, imagenPerfil, descripcion;
        string numCel;
        
        //USU1
        numCel = "090123654";//90123654
        nombre = "Juan Perez";
        imagenPerfil = "home/img/perfil/juan.png";
        descripcion = "Cómo andan?";
        usuLog->altaPrecargaUsuario(numCel,nombre,imagenPerfil,descripcion);
        
        //USU2
        numCel = "090765432";//90765432
        nombre = "María Fernández";
        imagenPerfil = "home/img/perfil/maria.png";
        descripcion = "Disponible";
        usuLog->altaPrecargaUsuario(numCel,nombre,imagenPerfil,descripcion);
        
        //USU3
        numCel = "090246810";//90246810
        nombre = "Pablo Iglesias";
        imagenPerfil = "home/img/perfil/pablo.png";
        descripcion = "En el Gym";
        usuLog->altaPrecargaUsuario(numCel,nombre,imagenPerfil,descripcion);
        
        //USU4
        numCel = "090666777";//90666777
        nombre = "Sara Ruiz";
        imagenPerfil = "home/img/perfil/sara.png";
        descripcion = "Estoy usando TeleTIP";
        usuLog->altaPrecargaUsuario(numCel,nombre,imagenPerfil,descripcion);
    }
    
void Fabrica::cargarContactos(){
        iContUsuario * usuLog = Fabrica::getContUsuario();
        
        //TANDA DE CONTACTOS 1
        usuLog->altaPrecargaContacto("090123654");
        //TANDA DE CONTACTOS 2
        usuLog->altaPrecargaContacto("090765432");
        //TANDA DE CONTACTOS 3
        usuLog->altaPrecargaContacto("090246810");
        //TANDA DE CONTACTOS 4
        usuLog->altaPrecargaContacto("090666777");
    }
    
void Fabrica::cargaGrupo(){
    iContUsuario* ContUsu=Fabrica::getContUsuario();
    iContGrupo* ContGru=Fabrica::getContGrupo();
    if (ContUsu->getUsu() != NULL)
        ContUsu->cerrarSesion(NULL);
    
        ContUsu->setNumCel("090123654");
        ContUsu->asignarSesion();
        Lista * ContP=new Lista();
        ContP=ContUsu->getUsu()->GetContactos();
        IIterator *it=ContP->iterator();
        while(it->hasNext()){
            ContGru->agregarParticipante(dynamic_cast<DtContacto*>(it->getCurrent()));
            it->next();
        }
        //22/05/2017 15:35
        ContGru->altaGrupo("home/img/amigos.png", "Amigos");
        DtFecha* fecha=new DtFecha(22,5,2017);
        DtHora* hora=new DtHora(15,35,0);
        ContUsu->setFechaHoraG(fecha,hora);
        ContUsu->setIdConvGrupo("090123654");
    }
  
void Fabrica::cargarConversaciones(){
        iContUsuario * ContUsu = Fabrica::getContUsuario();
        ContUsu->altaPrecargaConversacion();
    }
    
void Fabrica::cargarMensajes(){

 //U1 90123654;
    //U2 90765432
    //U3 90246810
    //U4 90666777
    //conv1 id=1
    //conv2 id=2
    
     /////////////////Mensaje1//////////////////////
        DtHora *hora;
        DtFecha *fecha;
        Visto *v;
        Mensaje* men1 = new Simple();
        v=new Visto("090123654");//90123654
        v->SetEstado(true);
        men1->SetVisto(v);
        v=new Visto("090765432");//90765432
        men1->SetVisto(v);
        v=new Visto("090246810");//90246810
        v->SetEstado(true);
        men1->SetVisto(v);
        dynamic_cast<Simple*> (men1)->setTexto("¡Mira que bueno este video!");
        men1->SetCodigo(2);
        men1->setEmisor("090666777");//66777
        fecha=new DtFecha(22,5,2017);
        hora=new DtHora(18,4,0);
        men1->SetFechaEnv(fecha);
        men1->SetHoraEnv(hora);
        Usuario* u=cUsu->getUsuario("090666777");//90666777
        u->setMensaje(men1,1);
      
       
         ////////////////mensaje2//////////////////
        Mensaje* men2 = new Video();
        dynamic_cast<Video*>(men2)->SetDuracion(5);
        men2->SetCodigo(3);
        men2->setEmisor("090666777");//65432
        v=new Visto("090123654"); //90123654
        //v->SetEstado(true);
        men2->SetVisto(v);
        v=new Visto("090765432"); //90765432
        men2->SetVisto(v);
        v=new Visto("090246810"); //90246810
        //v->SetEstado(true);
        men2->SetVisto(v);
        fecha=new DtFecha(22,5,2018);
        hora=new DtHora(18,5,0);
        men2->SetFechaEnv(fecha);
        men2->SetHoraEnv(hora);
        Usuario* u2=cUsu->getUsuario("090666777"); //90666777
        u2->setMensaje(men2,1);
       

   ////////////////////mensaje3//////////////////////     
        Mensaje* men3 = new Simple();
        dynamic_cast<Simple*>(men3)->setTexto("¡Muy gracioso!");
        men3->SetCodigo(4);
        men3->setEmisor("090123654");//90123654
        v=new Visto("090666777");//90666777
        //v->SetEstado(true);
        men3->SetVisto(v);
        v=new Visto("090765432");//90765432
        men3->SetVisto(v);
        v=new Visto("090246810");//90246810
        //v->SetEstado(true);
        men3->SetVisto(v);
        fecha=new DtFecha(22,5,2018);
        hora=new DtHora(18,12,0);
        men3->SetFechaEnv(fecha);
        men3->SetHoraEnv(hora);
        Usuario * u3=cUsu->getUsuario("090123654");//90123654
        u3->setMensaje(men3,1);
     
    //////////////////mensaje4////////////////7    
        Mensaje* men4 = new Simple();
        dynamic_cast<Simple*>(men4)->setTexto("¡Excelente!");
        men4->SetCodigo(5);
        men4->setEmisor("090246810");//90246810
        v=new Visto("090123654");//u1 90123654
        //v->SetEstado(true);
        men4->SetVisto(v);
        v=new Visto("090765432");//u2 90765432
        men4->SetVisto(v);
        v=new Visto("090666777");//u4 90666777
        men4->SetVisto(v);      
        fecha=new DtFecha(22,5,2018);
        hora=new DtHora(18,13,0);
        men4->SetFechaEnv(fecha);
        men4->SetHoraEnv(hora);
        Usuario * u4= cUsu->getUsuario("090246810"); //90246810
        u4->setMensaje(men4,1);
      
    /////////////////mensaje5////////////////////    
        Mensaje* men5 = new Simple();
        dynamic_cast<Simple*>(men5)->setTexto("Hola, me pasas el contacto de Sara que no lo tengo");
        men5->SetCodigo(6);
        men5->setEmisor("090765432"); //90765432
        v=new Visto("090123654");//u1 90123654
        //v->SetEstado(true);
        men5->SetVisto(v);
        fecha=new DtFecha(23,5,2018);
        hora=new DtHora(12,23,0);
        men5->SetFechaEnv(fecha);
        men5->SetHoraEnv(hora);
        Usuario * u5= cUsu->getUsuario("090765432"); //90765432
        u5->setMensaje(men5,2);
     
    ///////////////mensaje6//////////////////////    
        Mensaje* men6 = new Contacto();
        dynamic_cast<Contacto*>(men6)->SetNumCel("090666777"); //90666777
        men6->SetCodigo(7);
        men6->setEmisor("090123654"); //90123654
        v=new Visto("090765432"); //90765432
        //v->SetEstado(true);
        men6->SetVisto(v);
        fecha=new DtFecha(23,5,2018);
        hora=new DtHora(12,25,0);
        men6->SetFechaEnv(fecha);
        men6->SetHoraEnv(hora);
        Usuario * u6=cUsu->getUsuario("090123654"); //90123654
        u6->setMensaje(men6,2);

        
        ////////////////mensaje7////////////////////    
        Mensaje* men7 = new Simple();
        dynamic_cast<Simple*>(men7)->setTexto("Gracias!");
        men7->SetCodigo(8);
        men7->setEmisor("090765432"); //90765432
        v=new Visto("090123654"); //90123654
        //v->SetEstado(true);
        men7->SetVisto(v);
        fecha=new DtFecha(23,5,2018);
        hora=new DtHora(12,26,0);
        men7->SetFechaEnv(fecha);
        men7->SetHoraEnv(hora);
        Usuario * u7= cUsu->getUsuario("090765432"); //90765432
        u7->setMensaje(men7,2);

        
    //////////////mensaje8//////////////////////    
        Mensaje* men8 = new Simple();
        dynamic_cast<Simple*>(men8)->setTexto("Hola Pablo, cómo estas?");
        men8->SetCodigo(9);
        men8->setEmisor("090666777"); //90666777
        v=new Visto("090246810"); //90246810
        //v->SetEstado(true);
        men8->SetVisto(v);
        fecha=new DtFecha(23,5,2018);
        hora=new DtHora(12,26,0);
        men8->SetFechaEnv(fecha);
        men8->SetHoraEnv(hora);
        Usuario * u8=cUsu->getUsuario("090666777"); //90666777
        u8->setMensaje(men8,2);
        this->getContMensaje()->setIdMens(9);
 }

