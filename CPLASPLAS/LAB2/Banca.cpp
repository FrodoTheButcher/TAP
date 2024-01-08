#include <iostream>
#include "Banca.h"
#include "Client.h"
#include "ContBancar.h"
using namespace std;

Banca::Banca(string codBancar, unsigned nrClienti, Client *clienti) {
    this.codBancar = codBancar;
    this.nrClienti = nrClienti;
    this.clienti = clienti;
};

Banca::Banca(const Banca &banca) {
    this.codBancar = banca.codBancar;
    this.nrClienti = banca.nrClienti;
    this.clienti = banca.clienti;
};
Banca::setCodBancar(string codBancar) {
    this.codBancar = codBancar;
};

class Banca::getCodBancar() {
    return this.codBancar;
};

class Banca::setNrClienti(unsigned nrClienti) {
    this.nrClienti = nrClienti;
};

class Banca::getNrClienti() {
    return this.nrClienti;
};

class Banca::setClienti(Client *clienti) {
    this.clienti = clienti;
};

class Banca::getClienti() {
    return this.clienti;
};

class Client::Client(string nume, string prenume, string adresa, unsigned nrconturi, ContBancar *conturi) {
    this.nume = nume;
    this.prenume = prenume;
    this.adresa = adresa;
    this.nrconturi = nrconturi;
    this.conturi = conturi;
};

class Client::Client(const Client &client) {
    this.nume = client.nume;
    this.prenume = client.prenume;
    this.adresa = client.adresa;
    this.nrconturi = client.nrconturi;
    this.conturi = client.conturi;
};

class Client::setNume(string nume) {
    this.nume = nume;
};

class Client::getNume() {
    return this.nume;
};

class Client::setPrenume(string prenume) {
    this.prenume = prenume;
};

class Client::getPrenume() {
    return this.prenume;
};

class Client::setAdresa(string adresa) {
    this.adresa = adresa;
};

class Client::getAdresa() {
    return this.adresa;
};

class Client::setNrconturi(unsigned nrconturi) {
    this.nrconturi = nrconturi;
};

class Client::getNrconturi() {
    return this.nrconturi;
};

class Client::setConturi(ContBancar *conturi) {
    this.conturi = conturi;
};

class Client::getConturi() {
    return this.conturi;
};

class ContBancar::ContBancar(string numarCont, float suma, string moneda) {
    this.numarCont = numarCont;
    this.suma = suma;
    this.moneda = moneda;
};

class ContBancar::ContBancar(const ContBancar &cont) {
    this.numarCont = cont.numarCont;
    this.suma = cont.suma;
    this.moneda = cont.moneda;
};

class ContBancar::afisareDate() {
    cout << this.numarCont << " " << this.suma << " " << this.moneda << endl;
};

class ContBancar::setNumarCont(string numarCont) {
    this.numarCont = numarCont;
};

class ContBancar::getNumarCont() {
    return this.numarCont;
};

class ContBancar::setSuma(float suma) {
    this.suma = suma;
};

class ContBancar::getSuma() {
    return this.suma;
};

class ContBancar::setMoneda(string moneda) {
    if(moneda == "RON" || moneda == "EUR")
     this.moneda = moneda;
};

class ContBancar::getMoneda() {
    return this.moneda;
};


class Banca::addClient(Client client) {
    this.clienti[this.nrClienti] = client;
    this.nrClienti++;
};

class Banca::afisareDate() {
    cout << this.codBancar << " " << this.nrClienti << endl;
};

class Banca::removeClient(Client client) {
    for(int i = 0; i < this.nrClienti; i++) {
        if(this.clienti[i] == client) {
            for(int j = i; j < this.nrClienti - 1; j++) {
                this.clienti[j] = this.clienti[j + 1];
            }
            this.nrClienti--;
            break;
        }
    }
};

class Banca::printClienti() {
    for(int i = 0; i < this.nrClienti; i++) {
        cout << this.clienti[i].getNume() << " " << this.clienti[i].getPrenume() << " " << this.clienti[i].getAdresa() << endl;
    }
};

class Banca::transfer(ContBancar cont, float suma) {
    if(this.moneda == "RON") {
        this.suma -= suma;
        cont.suma += suma;
        cont.suma += suma * 0.003;
    } else if(this.moneda == "EUR") {
        this.suma -= suma;
        cont.suma += suma;
        cont.suma += suma * 0.008;
    }
};

class ContBancar::depunere(float suma) {
    if(this.moneda == "RON") {
        this.suma += suma;
        this.suma -= suma * 0.003;
    } else if(this.moneda == "EUR") {
        this.suma += suma;
        this.suma -= suma * 0.008;
    }
};

class ContBancar::afisareDate() {
    cout << this.numarCont << " " << this.suma << " " << this.moneda << endl;
};

class ContBancar::extragere(float suma) {
    if(this.moneda == "RON") {
        this.suma -= suma;
        this.suma -= suma * 0.003;
    } else if(this.moneda == "EUR") {
        this.suma -= suma;
        this.suma -= suma * 0.008;
    }
};

class ContBancar::getSumaTotala() {
    return this.suma;
};

int main()
{
    Banca b1("RO123", 2, new Client[2]);
    b1.afisareDate();
    b1.addClient(Client("blabla", "Ion", "Strada 1", 2, new ContBancar[2]));
    b1.addClient(Client("blabla2", "Ion", "Strada 2", 2, new ContBancar[2]));
    b1.afisareDate();
    b1.printClienti();
    b1.removeClient(Client("blabla", "Ion", "Strada 1", 2, new ContBancar[2]));
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "RON"), 50);
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "EUR"), 50);
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "RON"), 50);
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "EUR"), 50);
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "RON"), 50);
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "EUR"), 50);
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "RON"), 50);
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "EUR"), 50);
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "RON"), 50);
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "EUR"), 50);
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "RON"), 50);
    b1.printClienti();
    b1.transfer(ContBancar("RO123", 100, "EUR"), 50);
    b1.afisareDate();
    return 0;
}