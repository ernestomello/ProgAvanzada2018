/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringKey.h
 * Author: juan
 *
 * Created on 22 de junio de 2017, 09:56 PM
 */

#ifndef STRINGKEY_H
#define STRINGKEY_H
#include <string>
#include "IKey.h"
using namespace std;

class StringKey : public IKey {
public:

    StringKey();
    StringKey(string value);
    string getString();
    bool equals(IKey* key);
    virtual ~StringKey();

private:
    string value;
};

#endif /* STRINGKEY_H */

