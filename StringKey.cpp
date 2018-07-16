/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringKey.cpp
 * Author: juan
 * 
 * Created on 22 de junio de 2017, 09:56 PM
 */

#include "StringKey.h"

StringKey::StringKey() {
}

StringKey::StringKey(string value) {
    this->value = value;
}

string StringKey::getString() {
    return (this->value);
}

bool StringKey::equals(IKey* key) {
    StringKey* aux = (StringKey*) (key);
    return (this->value == aux->value);
}

StringKey::~StringKey() {
}

