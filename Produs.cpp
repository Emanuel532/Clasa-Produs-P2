//
// Created by USER on 02/05/2023.
//

#include "Produs.h"
Produs::Produs() {
    cantitate = 0;
    pret = 0;
    nume = NULL;
}

Produs::Produs(int cantitate, double pret, char *nume) {
    this->cantitate = cantitate;
    this->pret = pret;
    if(nume != NULL) {
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
    } else {
        this->nume = NULL;
    }
}

Produs::Produs(const Produs& produs) {
    this->cantitate = produs.cantitate;
    this->pret = produs.pret;
    if(produs.nume != NULL) {
        this->nume = new char[strlen(produs.nume)+1];
        strcpy(this->nume, produs.nume);
    } else {
        this->nume = NULL;
    }
}

Produs::Produs(double d) {
    this->cantitate = 1;
    this->pret = d;
    this->nume = new char[strlen("necunoscut")+1];
    strcpy(this->nume, "necunoscut");
}

Produs::~Produs() {
    if(nume != NULL){
        delete []nume;
    }
}

Produs& Produs::operator++() {
    this->cantitate++;
    return *this;
}

Produs Produs::operator++(int) {
    Produs p(*this);
    this->cantitate++;
    return p;
}

Produs& Produs::operator=(const Produs &produs) {
    if(this == &produs)
        return *this;

    this->cantitate = produs.cantitate;
    this->pret = produs.pret;
    if(this->nume != NULL) {
        delete []this->nume;
    }
    if(produs.nume != NULL) {
        this->nume = new char[strlen(produs.nume)+1];
        strcpy(this->nume, produs.nume);
    } else {
        this->nume = NULL;
    }
    return *this;
}

Produs& Produs::operator%=(int procent) {
    this->pret = this->pret + ((this->pret * procent) / 100);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Produs &p) {
    out << p.nume << " " << p.pret << " " << p.cantitate;
    return out;
}

std::istream &operator>>(std::istream &in, Produs &p) {
    char denumire[100];
    in >> p.cantitate >> p.pret >> denumire;
    if(p.nume != NULL) {
        delete [] p.nume;
    }
    p.nume = new char [strlen(denumire)+1];
    strcpy(p.nume, denumire);
    return in;
}

Produs operator %(const Produs &p, int procent) {
    Produs produs = p;

    produs %= procent;

    return produs;
}

bool operator>(const Produs& p1, const Produs& p2) {
    return strcmp(p1.nume, p2.nume) > 0;
}

Produs::operator int() {
    return this->cantitate * this->pret;
}