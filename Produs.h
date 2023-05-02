//
// Created by USER on 02/05/2023.
//
#include <iostream>
#include <string.h>
#ifndef UNTITLED1_PRODUS_H
#define UNTITLED1_PRODUS_H


class Produs {
    int cantitate;
    double pret;
    char *nume;
public:
    Produs();
    Produs(int, double, char*);
    Produs(const Produs& );
    Produs(double);
    ~Produs();

    Produs& operator=(const Produs &);

    Produs& operator%=(int);
    operator int();

    Produs& operator++();
    Produs operator++(int);

    friend std::ostream& operator<<(std::ostream&, const Produs&);
    friend std::istream& operator>>(std::istream&, Produs&);

    friend Produs operator%(const Produs&, int);
    friend bool operator>(const Produs&, const Produs&);


};


#endif //UNTITLED1_PRODUS_H
