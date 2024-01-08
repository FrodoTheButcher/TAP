#include <iostream>
#include "Matrice.h"
using namespace std;


Matrice::Matrice() {
    this->linii = 0;
    this->coloane = 0;
    this->matrice = NULL;
}

Matrice::Matrice(int linii, int coloane) {
    this->linii = linii;
    this->coloane = coloane;
    this->matrice = new int*[linii];
    for (int i = 0; i < linii; ++i) {
        this->matrice[i] = new int[coloane];
    }
}



Matrice::Matrice(const Matrice &alta_matrice) {
    this->linii = alta_matrice.linii;
    this->coloane = alta_matrice.coloane;
    this->matrice = new int*[this->linii];
    for (int i = 0; i < this->linii; ++i) {
        this->matrice[i] = new int[this->coloane];
    }
    for (int i = 0; i < this->linii; ++i) {
        for (int j = 0; j < this->coloane; ++j) {
            this->matrice[i][j] = alta_matrice.matrice[i][j];
        }
    }
}

Matrice Matrice::operator+(const Matrice &alta_matrice) {
    if (this->linii != alta_matrice.linii || this->coloane != alta_matrice.coloane) {
        throw invalid_argument("Matricele nu au aceeasi dimensiune");
    }
    Matrice rezultat(this->linii, this->coloane);
    for (int i = 0; i < this->linii; ++i) {
        for (int j = 0; j < this->coloane; ++j) {
            rezultat.matrice[i][j] = this->matrice[i][j] + alta_matrice.matrice[i][j];
        }
    }
    return rezultat;
}

int* Matrice::operator[](int index) {
    if (index < 0 || index >= this->linii) {
        throw invalid_argument("Index invalid");
    }
    return this->matrice[index];
}


Matrice Matrice::operator-(const Matrice &alta_matrice) {
    if (this->linii != alta_matrice.linii || this->coloane != alta_matrice.coloane) {
        throw invalid_argument("Matricele nu au aceeasi dimensiune");
    }
    Matrice rezultat(this->linii, this->coloane);
    for (int i = 0; i < this->linii; ++i) {
        for (int j = 0; j < this->coloane; ++j) {
            rezultat.matrice[i][j] = this->matrice[i][j] - alta_matrice.matrice[i][j];
        }
    }
    return rezultat;
}

Matrice Matrice::operator*(const Matrice &alta_matrice) {
    if (this->coloane != alta_matrice.linii) {
        throw invalid_argument("Matricele nu au dimensiuni compatibile");
    }
    Matrice rezultat(this->linii, alta_matrice.coloane);
    for (int i = 0; i < this->linii; ++i) {
        for (int j = 0; j < alta_matrice.coloane; ++j) {
            rezultat.matrice[i][j] = 0;
            for (int k = 0; k < this->coloane; ++k) {
                rezultat.matrice[i][j] += this->matrice[i][k] * alta_matrice.matrice[k][j];
            }
        }
    }
    return rezultat;
}

Matrice Matrice::operator*(int scalar) {
    Matrice rezultat(this->linii, this->coloane);
    for (int i = 0; i < this->linii; ++i) {
        for (int j = 0; j < this->coloane; ++j) {
            rezultat.matrice[i][j] = this->matrice[i][j] * scalar;
        }
    }
    return rezultat;
}

Matrice Matrice::operator/(int scalar) {
    Matrice rezultat(this->linii, this->coloane);
    for (int i = 0; i < this->linii; ++i) {
        for (int j = 0; j < this->coloane; ++j) {
            rezultat.matrice[i][j] = this->matrice[i][j] / scalar;
        }
    }
    return rezultat;
}

bool Matrice::operator==(const Matrice &alta_matrice) {
    if (this->linii != alta_matrice.linii || this->coloane != alta_matrice.coloane) {
        return false;
    }
    for (int i = 0; i < this->linii; ++i) {
        for (int j = 0; j < this->coloane; ++j) {
            if (this->matrice[i][j] != alta_matrice.matrice[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrice::operator!=(const Matrice &alta_matrice) {
    for(int i = 0; i < this->linii; ++i) {
        for (int j = 0; j < this->coloane; ++j) {
            if (this->matrice[i][j] != alta_matrice.matrice[i][j]) {
                return true;
            }
        }
    }
    return false;
}

void Matrice::print() {
    for (int i = 0; i < this->linii; ++i) {
        for (int j = 0; j < this->coloane; ++j) {
            cout << this->matrice[i][j] << " ";
        }
        cout << endl;
    }
}

Matrice::~Matrice() {
    for (int i = 0; i < this->linii; ++i) {
        delete[] this->matrice[i];
    }
    delete[] this->matrice;
}

int main() {
   
    return 0;
}