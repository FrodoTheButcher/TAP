#include <iostream>
#include "Fractie.h"
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

Fractie Fractie::operator+(Fractie alta_fractie) {return Fractie( this->numarator * alta_fractie.numitor + alta_fractie.numarator * this->numitor, this->numitor * alta_fractie.numitor);}

Fractie Fractie::operator-(Fractie alta_fractie) {return Fractie(this->numarator * alta_fractie.numitor - alta_fractie.numarator * this->numitor, this->numitor * alta_fractie.numitor);}

Fractie Fractie::operator*(Fractie alta_fractie) {return Fractie(this->numarator * alta_fractie.numarator, this->numitor * alta_fractie.numitor);}

Fractie Fractie::operator/(Fractie alta_fractie) {return Fractie(this->numarator * alta_fractie.numitor, this->numitor * alta_fractie.numarator);}

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

bool Fractie::operator=(const Fractie &alta_fractie) {
    this->numarator = alta_fractie.numarator;
    this->numitor = alta_fractie.numitor;
    return true;
}

bool Fractie::egal(Fractie alta_fractie) {return this->numarator * alta_fractie.numitor == this->numitor * alta_fractie.numarator;}

void Fractie::print() {
    cout << this->numarator << "/" << this->numitor << endl;
}

int main() {
    Fractie f1(1, 2);
    Fractie f2(1, 3);
    Fractie f3 = f1 + f2;
    f3.print();
    Fractie f4 = f1 - f2;
    f4.print();
    Fractie f5 = f1 * f2;
    f5.print();
    Fractie f6 = f1 / f2;
    f6.print();
    f1 = f2;
    f1.print();
    cout << f1.egal(f2) << endl;
    return 0;
}