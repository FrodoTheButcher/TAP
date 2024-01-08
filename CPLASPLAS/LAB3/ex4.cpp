#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Actor{
    private:
        string nume;
        string prenume;
        int varsta;
        string rol;
        static int instante;
    public:
        Actor(string nume, string prenume, int varsta, string rol)
        {
            this->nume = nume;
            this->prenume = prenume;
            this->varsta = varsta;
            this->rol = rol;
            instante++;
        }
        void setNume(string nume)
        {
            this->nume=nume;
        }
        string getNume()
        {
            return this->nume;
        }
        void setPrenume(string prenume)
        {
            this->prenume=prenume;
        }
        string getPrenume()
        {
            return this->prenume;
        }
        void afisareDate()
        {
            cout<<"Nume: "<<this->nume<<endl;
            cout<<"Prenume: "<<this->prenume<<endl;
            cout<<"Varsta: "<<this->varsta<<endl;
            cout<<"Rol: "<<this->rol<<endl;
        }
        static int getInstante()
        {
            return instante;
        }
        ~Actor()
        {
            cout<<"blabla";
        }
};

class Film
{
    private:
        string titlu;
        string regizor;
        int an;
        float durata;
        static int instante;
        vector<Actor> actori;
        int budget;
    public:
        Film(string titlu,string regizor,int an,float durata,int budget,vector<Actor> actori)
        {
            this->titlu = titlu;
            this->regizor = regizor;
            this->an = an;
            this->durata = durata;
            instante++;
            this->actori=actori;
            this->budget=budget;
        }
        friend void sortForBudget(Film x);
       
        friend void sortAfterNumberOfActors(Film x);
        
        void addActor(Actor actor)
        {
            this->actori.push_back(actor);
        }
        void removeActor(Actor actor)
        {
            for(int i=0;i<this->actori.size();i++)
            {
                if(this->actori[i].getNume()==actor.getNume() && this->actori[i].getPrenume()==actor.getPrenume())
                {
                    this->actori.erase(this->actori.begin()+i);
                }
            }
        }
        friend void printCommonActors(Film x,Film y);
};
void printCommonActors(Film x,Film y)
{
    map<string,Actor> actorsFromX;
    for(auto actors:x.actori)
    {
        actorsFromX[actors.getNume()+actors.getPrenume()] = actors;
    }

    for(auto actors:y.actori)
    {
        if(actorsFromX.find(actors.getNume()+actors.getPrenume())!=actorsFromX.end())
        {
            cout<<actors.getNume()<<" "<<actors.getPrenume()<<endl;
        }
    }
}


void sortForBudget(Film x)
{
            //cred ca asta e ceva lambda la final
            sort(x.actori.begin(),x.actori.end(),[](Actor a,Actor b){return a.getNume()<b.getNume();});
}

 void sortAfterNumberOfActors(Film x)
{
            sort(x.actori.begin(),x.actori.end(),[](Actor a,Actor b){return a.getNume()<b.getNume();});
}
int main()
{

    Film film("BlablaTitle1","BlablaDirector1",2000,4.0,1000000,vector<Actor>(
        {
            Actor("BlablaFirstName1","BlablaLastName1",40,"BlablaRole1"),
            Actor("BlablaFirstName2","BlablaLastName2",40,"BlablaRole2")
        }
    ));
Film film2("BlablaTitle2","BlablaDirector2",2001,4.5,2000000,vector<Actor>(
        {
            Actor("BlablaFirstName3","BlablaLastName3",45,"BlablaRole3"),
            Actor("BlablaFirstName4","BlablaLastName4",45,"BlablaRole4")
        }
    ));
printCommonActors(film,film2);
cout<<Actor::getInstante();

    return 0;
}