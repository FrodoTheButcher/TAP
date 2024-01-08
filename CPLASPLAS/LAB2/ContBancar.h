#ifndef CONTBANCAR.H
#define CONTBANCAR.H
#include <string>
using namespace std;
#include "Operatiuni.h"

class ContBancar :: public Operatiuni{
    private:
        string numarCont;
        float suma;
        string moneda;
    public:
        ContBancar(string numarCont, float suma, string moneda);
        ContBancar(const ContBancar &cont);
        void setNumarCont(string numarCont);
        string getNumarCont();
        void setSuma(float suma);
        float getSuma();
        void setMoneda(string moneda);
        string getMoneda();
        void afisareDate();
};

#endif 
