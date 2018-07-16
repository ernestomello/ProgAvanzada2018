/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Multimedia.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:32 AM
 */

#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include"Mensaje.h"

class Multimedia : public Mensaje {
public:
    Multimedia();
    Multimedia(const Multimedia& orig);
    virtual ~Multimedia();

private:

};

#endif /* MULTIMEDIA_H */

