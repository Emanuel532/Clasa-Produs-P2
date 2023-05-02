#include <iostream>
#include "Produs.h"

using std::cout;
using std::endl;
int main() {
    Produs p1;
    Produs p2(5, 4000, "calculator");
    Produs p3 = p2;
    Produs p4(p2);
    //std::cin >> p2;
    Produs tab[3];
    tab[0] = p2;
    tab[1] = Produs(3, 1500, "tastatura");
    tab[2] = Produs(10, 150, "incarcator");
    int n =3;
    /*
    for(int i =0; i < n; i++) {
        cout << tab[i] << endl;
    }

    for(int i =0; i < n; i++) {
        for(int j =0; j < n; j++) {
            if(tab[i] > tab[j]) {
                Produs aux;
                aux = tab[i];
                tab[i] = tab[j];
                tab[j] = aux;
            }
        }
    }
    cout << endl;
    for(int i =0; i < n; i++) {
        cout << tab[i] << endl;
    }*/
    Produs p5(8.7);
    //cout << p5 << endl;
    Produs p6 = 1.4;
    p6++;
    cout << p6 << endl;

    return 0;
}
