/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   intKey.h
 * Author: juan
 *
 * Created on 12 de junio de 2018, 01:51 PM
 */

#ifndef INTKEY_H
#define INTKEY_H
#include"IKey.h"
using namespace std;

class intKey : public IKey {
public:

    intKey();
    intKey(int value);
    int getInt();
    bool equals(IKey* key);
    virtual ~intKey();


private:
    int value;
};


#endif /* INTKEY_H */

