#ifndef CLIENT.H
#define CLIENT.H
#include "ContBancar.h";
class Client {
    private:
        string nume;
        string prenume;
        string adresa;
        unsigned nrconturi;
        ContBancar *conturi;
    public:
        Client(string nume, string prenume, string adresa, unsigned nrconturi, ContBancar *conturi);
        Client(const Client &client)
        void setNume(string nume);
        string getNume();
        void setPrenume(string prenume);
        string getPrenume();
        void setAdresa(string adresa);
        string getAdresa();
        void setNrconturi(unsigned nrconturi);
        unsigned getNrconturi();
        void setConturi(ContBancar *conturi);
        ContBancar *getConturi();
        void afisareDate();
};

#endif 
