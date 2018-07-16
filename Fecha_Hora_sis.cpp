/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fecha_Hora_sis.cpp
 * Author: juan
 * 
 * Created on 12 de junio de 2018, 11:48 AM
 */

#include "Fecha_Hora_sis.h"

string Fecha_Hora_sis::currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof (buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

DtFecha * Fecha_Hora_sis::getFecha() {
}

DtHora * Fecha_Hora_sis::getHora() {
}

DtUltCon* Fecha_Hora_sis::getUltimaConexion() {
    string fecha_hora = currentDateTime();
    int anio = atoi(fecha_hora.substr(0, 4).c_str());
    int mes = atoi(fecha_hora.substr(5, 2).c_str());
    int dia = atoi(fecha_hora.substr(8, 2).c_str());
    int hhora = atoi(fecha_hora.substr(11, 2).c_str());
    int min = atoi(fecha_hora.substr(14, 2).c_str());
    int seg = atoi(fecha_hora.substr(17, 2).c_str());
    DtFecha* fecha = new DtFecha(dia, mes, anio);
    DtHora* hora = new DtHora(hhora, min, seg);
    DtUltCon* dtuc = new DtUltCon(fecha, hora);
    return dtuc;
}

Fecha_Hora_sis::Fecha_Hora_sis() {

}

Fecha_Hora_sis::Fecha_Hora_sis(int, int, int, int, int, int) {

}

int Fecha_Hora_sis::setFecha(int, int, int) {
}

int Fecha_Hora_sis::setHora(int, int, int) {
}

Fecha_Hora_sis::~Fecha_Hora_sis() {
}