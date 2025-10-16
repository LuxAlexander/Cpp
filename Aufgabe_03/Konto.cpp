//
// Created by Alex on 16.10.2025.
//

#include "Konto.h"

#include <iostream>
#include <ostream>
#include <stdexcept>

std::string Konto::get_name() const {
    return this->_name;
}

double Konto::get_kontostand() const {
    return this->_kontostand;
}

bool Konto::einzahlen(double betrag) {
    if (betrag > 0) {
        this->_kontostand += betrag;
        return true;
    }else {
        //throw std::runtime_error("Einzahlen kann nicht negativ sein");
        return false;
    }
}

bool Konto::auszahlen(double betrag) {
    if (this->_kontostand-betrag >= 0) {
        this->_kontostand -= betrag;
        return true;
    }
    return false;
}

void Konto::print() {
    std::cout << "Name: " << this->get_name() <<" Stand: "<<this->get_kontostand() <<std::endl;
}
