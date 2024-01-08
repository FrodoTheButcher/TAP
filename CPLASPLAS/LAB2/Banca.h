#ifndef BANCA.H
#define BANCA.H
using namespace std;
#include "Client.h"
class Banca{
    private:
        string codBancar;
        unsigned nrClienti;
        Client *clienti;
    public:
        Banca(string codBancar, unsigned nrClienti, Client *clienti);
        Banca(const Banca &banca);
        void setCodBancar(string codBancar);
        string getCodBancar();
        void setNrClienti(unsigned nrClienti);
        unsigned getNrClienti();
        void setClienti(Client *clienti);
        Client *getClienti();

        void addClient(Client client);
        void removeClient(Client client);
        void printClienti();
        void transfer(ContBancar cont, float suma);
        void afisareDate();
};


#endif 
