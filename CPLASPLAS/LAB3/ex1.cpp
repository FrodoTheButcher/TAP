#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Dreapta{
    private:
        int m;
        int n;
    public:
        Dreapta(int m, int n)
        {
            this->m = m;
            this->n = n;
        }
        Dreapta(const Dreapta &dreapta)
        {
            this->m = dreapta.m;
            this->n = dreapta.n;
        }
        void setM(int m)
        {
            this->m = m;
        }
        int getM()
        {
            return this->m;
        }
        void setN(int n)
        {
            this->n = n;
        }
        int getN()
        {
            return this->n;
        }
        ~Dreapta()
        {
            cout<<"blabla";
        }
};

class Punct{
    private:
        int x, y;
    public:
         static int semiplanPozitiv;
        static int semiplanNegativ;
        static int semiplanDreapta;
        Punct(int x, int y)
        {
            this->x = x;
            this->y = y;
              if (x > 0 || (x == 0 && y > 0)) {
            semiplanPozitiv++;
        } else if (x < 0 || (x == 0 && y < 0)) {
            semiplanNegativ++;
        } else {
            semiplanDreapta++;
        }
        }
        Punct(const Punct &punct)
        {
            this->x = punct.x;
            this->y = punct.y;
        }
        static Dreapta *dreapta;
        void setX(int x)
        {
            this->x = x;
        }
        int getX()
        {
            return this->x;
        }
        void setY(int y)
        {
            this->y = y;
        }
        int getY()
        {
            return this->y;
        }
        ~Punct()
        {
            cout<<"blabla2";
        }
        friend float distanta(Punct p1, Punct p2);
        friend class Dreapta;
        
};
Dreapta* Punct::dreapta = nullptr;

float distanta(Punct p1, Punct p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

 float centruDeGreutateAlPunctelor(vector<Punct> puncte)
   {
        float x = 0, y = 0;
        for (auto pct:puncte) {
            x +=pct.getX();
            y +=pct.getY();
        }
        x /= puncte.size();
        y /= puncte.size();
        return distanta(Punct(x, y), Punct(0, 0));
   };
int main()
{
   int n;
   cin>>n;
   //din fisier era f>>n unde f este ifstream f("text.in");
   vector<Punct> puncte;
   cout<<centruDeGreutateAlPunctelor(puncte);
}