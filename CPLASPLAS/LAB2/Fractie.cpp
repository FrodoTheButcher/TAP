#include "Fractie.h"
#include <iostream>
using namespace std;

Fractie::Fractie() {
    this->numarator = 0;
    this->numitor = 1;
}
Fractie::Fractie(int numarator, int numitor) {
    this->numarator = numarator;
    this->numitor = numitor;
}

Fractie::Fractie(int numarator) {
    this->numarator = numarator;
    this->numitor = 1;
}

Fractie::Fractie(const Fractie &alta_fractie) {
    this->numarator = alta_fractie.numarator;
    this->numitor = alta_fractie.numitor;
}

Fractie Fractie::adunare(Fractie alta_fractie) {return Fractie( this->numarator * alta_fractie.numitor + alta_fractie.numarator * this->numitor, this->numitor * alta_fractie.numitor);}

Fractie Fractie::scadere(Fractie alta_fractie) {return Fractie(this->numarator * alta_fractie.numitor - alta_fractie.numarator * this->numitor, this->numitor * alta_fractie.numitor);}

Fractie Fractie::inmultire(Fractie alta_fractie) {return Fractie(this->numarator * alta_fractie.numarator, this->numitor * alta_fractie.numitor);}

Fractie Fractie::impartire(Fractie alta_fractie) {return Fractie(this->numarator * alta_fractie.numitor, this->numitor * alta_fractie.numarator);}

int Fractie::cmmdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return cmmdc(b, a % b);
}

void Fractie::simplificare() {
    int cmmdc = Fractie::cmmdc(this->numarator, this->numitor);
    this->numarator /= cmmdc;
    this->numitor /= cmmdc;
}

bool Fractie::egal(Fractie alta_fractie) {return this->numarator * alta_fractie.numitor == this->numitor * alta_fractie.numarator;}

void Fractie::print() {
    cout << this->numarator << "/" << this->numitor << endl;
}