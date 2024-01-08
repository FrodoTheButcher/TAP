#include <iostream>
#include <vector>
using namespace std;

class Carte{
    private:
        string titlu;
        string autor;
        int ISBN;
        float pret;
        static int instante;
    public:
        Carte(string titlu, string autor, int ISBN, float pret)
        {
            this->titlu = titlu;
            this->autor = autor;
            this->ISBN = ISBN;
            this->pret = pret;
            instante++;
        }
        Carte(const Carte &carte)
        {
            this->titlu = carte.titlu;
            this->autor = carte.autor;
            this->ISBN = carte.ISBN;
            this->pret = carte.pret;
        }
        static inline int getInstante()
        {
            cout<<instante;
        }
        inline void setTitlu(string titlu)
        {
            this->titlu = titlu;
        }
        inline string getTitlu() const
        {
            return this->titlu;
        }
        inline void setAutor(string autor)
        {
            this->autor = autor;
        }
        inline string getAutor() const
        {
            return this->autor;
        }
        inline void setISBN(int ISBN)
        {
            this->ISBN = ISBN;
        }
        inline int getISBN() const
        {
            return this->ISBN;
        }
        inline void setPret(float pret)
        {
            this->pret = pret;
        }
        inline float getPret() const
        {
            return this->pret;
        }
        ~Carte()
        {
            cout<<"blabla";
        }
};
int Carte::instante = 0;
int main()
{
    int n;
    cin>>n;
    vector<Carte> carti;
    for(int i=0;i<n;i++)
    {
        string titlu, autor;
        int ISBN;
        float pret;
        cin>>titlu>>autor>>ISBN>>pret;
        carti.push_back(Carte(titlu, autor, ISBN, pret));
    }
    cout<<Carte::getInstante();

    return 0;
}