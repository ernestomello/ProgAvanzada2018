/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"intKey.h"

intKey::intKey() {
}

intKey::intKey(int value) {
    this->value = value;
}

int intKey::getInt() {
    return (this->value);
}

bool intKey::equals(IKey* key) {
    intKey* aux = (intKey*) (key);
    return (this->value == aux->value);
}

intKey::~intKey() {
}