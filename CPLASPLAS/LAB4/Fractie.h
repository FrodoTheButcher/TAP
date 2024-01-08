#ifndef FRACTIE.H
#define FRACTIE.H

class Fractie
{
private:
    int numarator;
    int numitor;
public:
    Fractie();
    Fractie(int numarator, int numitor);
    Fractie(int numarator);
    Fractie(const Fractie &alta_fractie);
    bool operator=(const Fractie &alta_fractie);
    Fractie operator+(Fractie alta_fractie);
    Fractie operator-(Fractie alta_fractie);
    Fractie operator*(Fractie alta_fractie);
    Fractie operator/(Fractie alta_fractie);
    static int cmmdc(int a, int b);
    void simplificare();
    bool egal(Fractie alta_fractie);
    void print();
};


#endif 
