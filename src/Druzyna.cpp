#include "Druzyna.h"


void Druzyna::wczytaj(int is,string n,int p,int me,int zw,int r,int po,int bz,int bs,int bi){
        this->indeks=is;
        this->nazwa=n;
        this->pkt=p;
        this->mecze=me;
        this->zwyciestwa=zw;
        this->remisy=r;
        this->porazki=po;
        this->bramki_zdobyte=bz;
        this->bramki_stracone=bs;
        this->bilans=bi;
    }
void Druzyna::oblicz_bilans(int ba,int bb ){
        bilans+=(ba-bb);
    }
void Druzyna::mecz(int ba,int bb,int pk){
        bramki_zdobyte+=ba;
        bramki_stracone+=bb;
        oblicz_bilans(ba,bb);
        mecze++;
        pkt+=pk;
        if(pk==3) zwyciestwa++;
        else if(pk==1) remisy++;
        else porazki++;


    }
int Druzyna::losowanie_z_prawdopodobienstwem(){
    int wylosowana;
    int status;
    status=this->status_druzyny;
    wylosowana=(rand()%100)+1;

    if(wylosowana <=(10/status)){
        return 1;
    }
    else if(wylosowana <=(20/status)){
        return 2;
    }
    else if(wylosowana <=(30/status)){
        return 3;
    }
    else if(wylosowana<=(40/status)){
        return 4;

    }
    else if(wylosowana<=(50/status)){
        return 5;
    }
    else if(wylosowana<=(60/status)){
        return 6;
    }
    else if(wylosowana<=(70/status)){
        return 7;
    }
    else if(wylosowana<=(80/status)){
        return 8;

    }
    else if(wylosowana <=(90/status)){
        return 9;
    }
    else return 10;

    }
int Druzyna::wczytanie(int zakres){
    int liczba;
    do{
        cin>>liczba;
    }while(liczba<1 || liczba>zakres);
    return liczba;
    }
void Druzyna::wczytanie_na_mecz(){
        int zm,wyb;
        do{
            cout<<"Podaj sile defensywna "<<this->nazwa<<endl;
            this->sila_defensywy=wczytanie(10);
            cout<<"Podaj sile ofensywna druzyny "<<this->nazwa<<endl;
            this->sila_ofensywy=wczytanie(10);
            cout<<"Podaj status druzyny "<<this->nazwa<<endl;
            this->status_druzyny=wczytanie(5);
        cout<<"Czy zatwierdzasz wybory,czy moze chcesz powtorzyc wczytanie ?"<<endl;
        cout<<"1-Przejdz dalej"<<endl<<"2-Wczytaj jeszcze raz "<<endl;
        do{
            cin>>wyb;
        }while(wyb!=1 && wyb!=2);
        }while(wyb!=1);

    }
void Druzyna::losowanie_zmiennych(){
        this->forma_defensywy=losowanie_z_prawdopodobienstwem();
        this->forma_ofensywy=losowanie_z_prawdopodobienstwem();
        this->mobilizacja_zespolu=losowanie_z_prawdopodobienstwem();
        this->pomysl_taktyczny=losowanie_z_prawdopodobienstwem();




    }
int Druzyna::sumowanie(){
    int suma;
    suma=forma_defensywy+forma_ofensywy+mobilizacja_zespolu+pomysl_taktyczny+sila_defensywy+sila_ofensywy;
    return suma;

    }
void Druzyna::wcztywanie_zmiennych(){
        cout<<"Podaj forme defensywna "<<this->nazwa<<endl;
        this->forma_defensywy=wczytanie(10);
        cout<<"Podaj forme ofensywna "<<this->nazwa<<endl;
        this->forma_ofensywy=wczytanie(10);
        cout<<"Podaj mobilizacje zespolu "<<this->nazwa<<endl;
        this->mobilizacja_zespolu=wczytanie(10);
        cout<<"Podaj pomysl taktyczny "<<this->nazwa<<endl;
        this->pomysl_taktyczny=wczytanie(10);



    }
