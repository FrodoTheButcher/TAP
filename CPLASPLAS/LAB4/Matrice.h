#ifndef MATRICE.H
#define MATRICE.H

class Matrice{
private:
    int linii;
    int coloane;
    int **matrice;
public:
    Matrice();
    Matrice(int linii, int coloane);
    Matrice(const Matrice &alta_matrice);
    ~Matrice();
    Matrice operator=(const Matrice &alta_matrice);
    Matrice operator+(const Matrice &alta_matrice);
    Matrice operator-(const Matrice &alta_matrice);
    Matrice operator*(const Matrice &alta_matrice);
    Matrice operator*(int scalar);
    Matrice operator/(int scalar);
    bool operator==(const Matrice &alta_matrice);
    bool operator!=(const Matrice &alta_matrice);
    int* operator[](int index);
    void print();
};


#endif 
