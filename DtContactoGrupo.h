/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtContactoGrupo.h
 * Author: ernesto
 *
 * Created on 26 de junio de 2018, 12:59 AM
 */

#ifndef DTCONTACTOGRUPO_H
#define DTCONTACTOGRUPO_H
#include<iostream>
#include"ICollectible.h" 
#include"DtFecha.h"
#include"DtHora.h"

using namespace std;

class DtContactoGrupo: public ICollectible {
public:
    DtContactoGrupo();
    DtContactoGrupo(string,string,string,DtFecha*,DtHora*);
    DtContactoGrupo(const DtContactoGrupo& orig);
    virtual ~DtContactoGrupo();
    string getCelular();
    string getipoEnGrupo();
    string getnombre();
    DtFecha* getFecha();
    DtHora* getHora();
    
private:
    string celular;
    string nombre; 
    string tipoEnGrupo;
    DtFecha * fecha;
    DtHora* hora;
    
    
};

#endif /* DTCONTACTOGRUPO_H */

