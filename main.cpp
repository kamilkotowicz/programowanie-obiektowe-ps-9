#include <iostream>
#include <string>
#include<vector>
#include<ctime>
using namespace std;
const double PI = 3.14159265359;
const int LICZBA_FIGUR = 10;
const int MAXX=100;
const int MAXY=100;
const int MAXA=10;
const int MAXR=10;
const int MAXDX=30;
const int MAXDY=30;
const int SKALA=2;
class Figura
{
public:
    virtual void przesun(int dx, int dy){}
    virtual void skaluj(int skala){}
    virtual double pole(){}
    virtual double obwod(){}
};

class Kolo : public Figura
{
private:
    int x,y,r;
public:
    virtual void przesun(int dx, int dy){
        x+=dx;
        y+=dy;
    }
    virtual void skaluj(int skala){
        r*=skala;
    }
    virtual double pole(){
        return PI*r*r;
    }
    virtual double obwod(){
        return 2.0*PI*r;
    }
    Kolo(int x,int y,int r){
        this->x=x;
        this->y=y;
        this->r=r;
    }
};

class Kwadrat : public Figura
{
private:
    int x,y,a;
public:
    virtual void przesun(int dx, int dy){
        x+=dx;
        y+=dy;
    }
    virtual void skaluj(int skala){
        a*=skala;
    }
    virtual double pole(){
        return a*a;
    }
    virtual double obwod(){
        return 4.0*a;
    }
    Kwadrat(int x,int y,int a){
        this->x=x;
        this->y=y;
        this->a=a;
    }
};
vector<Figura*> stworz_figury(){
    vector<Figura*> figury;
    for(int i=0;i<LICZBA_FIGUR;++i){
        Figura *f;
        int x,y,a,r;
        x=rand()%MAXX;
        y=rand()%MAXY;
        if(rand()%2==0){
            r=rand()%MAXR+1;
            f = new Kolo(x,y,r);
        }
        else{
            a=rand()%MAXA+1;
            f = new Kwadrat(x,y,a);
        }
        figury.push_back(f);
    }
    return figury;
}

double laczne_pole(const vector<Figura*> & figury){
    double wyn=0;
    for(int i=0;i<figury.size();++i){
        double akt=figury[i]->pole();
        wyn+=akt;
    }
    return wyn;
}

double laczny_obwod(const vector<Figura*> & figury){
    double wyn=0;
    for(int i=0;i<figury.size();++i){
        double akt=figury[i]->obwod();
        wyn+=akt;
    }
    return wyn;
}

void przesun_figury(const vector<Figura*> & figury){
    for(int i=0;i<figury.size();++i){
        int dx=rand()%MAXDX;
        int dy=rand()%MAXDY;
        figury[i]->przesun(dx,dy);
    }
}

void skaluj_figury(const vector<Figura*> & figury){
    for(int i=0;i<figury.size();++i){
        figury[i]->skaluj(SKALA);
    }
}

void obwod_i_pole(const vector<Figura*> & figury){
    double pole=laczne_pole(figury);
    double obwod=laczny_obwod(figury);
    cout<<"Pole\t"<<pole<<"\tObwod\t"<<obwod<<"\n";
}

void zwolnij_pamiec(const vector<Figura*> & figury){
    for(int i=0;i<figury.size();++i){
        delete figury[i];
    }
}

int main(){
    srand(time(NULL));
    vector<Figura*>figury = stworz_figury();
    obwod_i_pole(figury);
    przesun_figury(figury);
    obwod_i_pole(figury);
    skaluj_figury(figury);
    obwod_i_pole(figury);
    zwolnij_pamiec(figury);
    return 0;
}

