#include <iostream>
using namespace std;


class Angajat{
    private:
        double tarifOrar;
        int nrOre;
    public:
        Angajat(double tarifOrar, int nrOre)
        {
            this->tarifOrar = tarifOrar;
            this->nrOre = nrOre;
        }
        Angajat(const Angajat &angajat)
        {
            this->tarifOrar = angajat.tarifOrar;
            this->nrOre = angajat.nrOre;
        }
        double getSalar()
        {
            return this->tarifOrar*this->nrOre;
        }
        void setTarifOrar(double tarifOrar)
        {
            this->tarifOrar = tarifOrar;
        }
        double getTarifOrar()
        {
            return this->tarifOrar;
        }
        void setNrOre(int nrOre)
        {
            this->nrOre = nrOre;
        }
        ~Angajat()
        {
            cout<<"blabla";
        }
        bool operator==(const Angajat &angajat)
        {
            return this->tarifOrar == angajat.tarifOrar && this->nrOre == angajat.nrOre;
        }
        void operator>>(const Angajat &angajat)
        {
            this->tarifOrar = angajat.tarifOrar;
            this->nrOre = angajat.nrOre;
        }
        void operator<<(const Angajat &angajat)
        {
            cout<<"Tarif orar: "<<angajat.tarifOrar<<endl;
            cout<<"Numar ore: "<<angajat.nrOre<<endl;
        }
};


class Manager : public Angajat {
private:
    int numar_subordonati;
public:
    Manager(double tarifOrar, int nrOre) : Angajat(tarifOrar, nrOre) {}
    double getSalar() {
        return Angajat::getSalar() * 1.5;
    }
    ~Manager() {
        Angajat::~Angajat();
    }

    bool operator == (const Manager &manager) {
        return Angajat::operator==(manager) && this->numar_subordonati == manager.numar_subordonati;
    }
    void operator >> (const Manager &manager) {
        Angajat::operator>>(manager);
        this->numar_subordonati = manager.numar_subordonati;
    }
    void operator << (const Manager &manager) {
        Angajat::operator<<(manager);
        cout << "Numar subordonati: " << manager.numar_subordonati << endl;
    }
};
int main()
{
    Angajat a1(10, 20);
    cout<<a1.getTarifOrar()<<endl;
    return 0;
}