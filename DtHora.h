/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtHora.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 02:38 AM
 */

#ifndef DTHORA_H
#define DTHORA_H

class DtHora {
public:

    DtHora();
    DtHora(int, int, int);
    DtHora(const DtHora& orig);
    virtual ~DtHora();

    int GetHora();
    int GetMinutos();
    int GetSegundo();

    void SetHora(int);
    void SetMinutos(int);
    void SetSegundo(int);

private:
    int hora;
    int minutos;
    int segundo;
};

#endif /* DTHORA_H */

