#include "Kolejka.h"
Druzyna d[20];
Kolejka::Kolejka(string Sciezka)
{
int zat;
ifstream plik;
string linia;
string nazwa;
int is,p,m,w,r,po,bz,bs,bi;
plik.open(Sciezka);
if(!plik.good()){
    cout<<"Nie udalo sie otworzyc pliku !"<<endl;
    Sleep(1000);
    cout<<"Tworzenie ligi"<<endl;
    cout<<"Podaj rozmiar ligi"<<endl;
    nr_kolejki=0;
    do{
    cin>>wielkosc;
    cout<<wielkosc<<"-czy zatwierdzasz ? 1-Tak"<<endl;
    cin>>zat;
    }while(zat!=1);
    for(int i=0;i<wielkosc;i++){
        cout<<"Podaj nazwe zespolu"<<endl;
        cin>>nazwa;
        is=i+1;
        d[i].wczytaj(is,nazwa,0,0,0,0,0,0,0,0);
    }
}
else{
    getline(plik,linia);
    istringstream ss(linia);
    ss>>wielkosc>>nr_kolejki;
    for(int i=0;i<wielkosc;i++){
        getline(plik,linia);
        istringstream ss(linia);
        ss>>is>>nazwa>>p>>m>>w>>r>>po>>bz>>bs>>bi;
        d[i].wczytaj(is,nazwa,p,m,w,r,po,bz,bs,bi);

    }
}
plik.close();
//cout<<d[19].nazwa<<endl;
}
int Kolejka::wybor_druzyny(int ind){
int i=0;
while(ind!=d[i].indeks) i++;
return i;

};
void Kolejka::wyswietlanie_tabeli(){
    cout.width(3);
    cout<<"Poz";
    cout.width(20);
    cout<<"Druzyna";
    cout.width(5);
    cout<<"Pkt";
    cout.width(5);
    cout<<"M";
    cout.width(5);
    cout<<"W";
    cout.width(5);
    cout<<"R";
    cout.width(5);
    cout<<"P";
    cout.width(5);
    cout<<"+";
    cout.width(5);
    cout<<"-";
    cout.width(7);
    cout<<"bilans";
    cout<<endl;
    for(int i=0;i<wielkosc;i++){
        cout.width(3);
        cout<<i+1;
        cout.width(26);
        cout<<d[i].nazwa;
        cout.width(5);
        cout<<d[i].pkt;
        cout.width(5);
        cout<<d[i].mecze;
        cout.width(5);
        cout<<d[i].zwyciestwa;
        cout.width(5);
        cout<<d[i].remisy;
        cout.width(5);
        cout<<d[i].porazki;
        cout.width(5);
        cout<<d[i].bramki_zdobyte;
        cout.width(5);
        cout<<d[i].bramki_stracone;
        cout.width(7);
        if(d[i].bilans>0) cout <<"+";
        cout<<d[i].bilans;
        cout<<endl;

        cout.width(5);

    }


}
void Kolejka::remis(Druzyna a,Druzyna b,int &bramka,int &bramkb){
    int atrackyjnosc=(a.forma_ofensywy+b.forma_ofensywy)/2;
    int sklonnosc_do_bledow=10-((a.forma_defensywy+b.forma_defensywy)/2);
    if(atrackyjnosc>7 && sklonnosc_do_bledow>7){
                bramka=(rand()%2)+3;

            }
            else if(atrackyjnosc<4 && sklonnosc_do_bledow<4) bramka=(rand()%2);
            else{
               bramka=(rand()%2)+1;
            }
    bramkb=bramka;
};
void Kolejka::zwyciestwo(Druzyna a,Druzyna b,int &bramka,int &bramkb){
    int atrackyjnosc,sklonnosc_do_bledow;
    int roznica=a.overall-b.overall;
    atrackyjnosc=(a.forma_ofensywy+b.forma_ofensywy)/2;
    sklonnosc_do_bledow=10-((a.forma_defensywy+b.forma_defensywy)/2);
    if(roznica <10){
            if(atrackyjnosc>5 && sklonnosc_do_bledow>5){
                bramkb=(rand()%4)+2;

            }
            else{
               bramkb=(rand()%2)+0;
            }
    bramka=bramkb+1;
}
    else if (roznica <15){
        if(atrackyjnosc>5 && sklonnosc_do_bledow>5){
                bramkb=(rand()%3)+3;

            }
            else{
               bramkb=(rand()%2)+0;
            }
    bramka=bramkb+2;
}
 else if (roznica <25){
        if(atrackyjnosc>5 && sklonnosc_do_bledow>5){
                bramkb=(rand()%4)+3;

            }
            else{
               bramkb=(rand()%3)+0;
            }
    bramka=bramkb+3;
}


            else{

            int ws=((10-a.forma_defensywy)+b.forma_ofensywy)/2;
            if(ws!=0) bramkb=(rand()%ws)+0;
            else bramkb=0;

            int wsi=((10-b.forma_defensywy)+a.forma_ofensywy)/2;
            wsi=wsi-bramkb;
            if(wsi<=0) wsi=1;
               bramka=(rand()%wsi)+(bramkb+3);

    }

}
void Kolejka::rozgrywka(Druzyna &a,Druzyna &b,int &bramka,int &bramkb){
int wyb3;

    a.wczytanie_na_mecz();
    b.wczytanie_na_mecz();
    do{
    int wyb;
    cout<<"Podaj czy chcesz wczytac zmienne, czy wylosowac ?"<<endl
        <<"1-Wczytaj"<<endl<<"2-Wylosuj"<<endl;
    do{
        cin>>wyb;
    }while(wyb!=1 && wyb!=2);
    if(wyb==1){
        a.wcztywanie_zmiennych();
        b.wcztywanie_zmiennych();
    }
    else{
        a.losowanie_zmiennych();
        b.losowanie_zmiennych();
    }
    a.overall=a.sumowanie();
    b.overall=b.sumowanie();
    int roznica=abs(a.overall-b.overall);
    cout<<roznica<<endl;

if(roznica<4){
    remis(a,b,bramka,bramkb);

}
else if(a.overall>b.overall){
    zwyciestwo(a,b,bramka,bramkb);


}
else{
    zwyciestwo(b,a,bramkb,bramka);

}

cout<<a.nazwa<<"-"<<b.nazwa<<" "<<bramka<<":"<<bramkb<<endl;
cout<<"Czy zatwierdzasz wynik?"<<endl<<"1-Tak"<<endl<<"2-Nie"<<endl;
do{
cin>>wyb3;
}while(wyb3!=1 && wyb3!=2);
}while(wyb3!=1);



}
void Kolejka::wypisywanie_meczy(){
int i=1;
int czsezonu=1;
int gosp,gosc;
if(nr_kolejki>=(wielkosc-1)){
        czsezonu=2;
    }
while(i<=(wielkosc/2)){
    if(i==1){
            if((nr_kolejki+1)%2==0){
                gosp=wybor_druzyny(i);
                gosc=wybor_druzyny(wielkosc+1-i);
            }
            else{
                gosc=wybor_druzyny(i);
                gosp=wybor_druzyny(wielkosc+1-i);
            }
        }
        else{
            if(i%2==0){
               gosp=wybor_druzyny(i);
               gosc=wybor_druzyny(wielkosc+1-i);
            }
            else{
                gosc=wybor_druzyny(i);
                gosp=wybor_druzyny(wielkosc+1-i);
            }
        }
        //cout<<gosp<<" "<<gosc<<endl;
        cout<<d[gosp].nazwa<<"-"<<d[gosc].nazwa<<endl;
        if(czsezonu==2 && i!=1) swap(gosp,gosc);
        //cout<<gosp<<" "<<gosc<<endl;
        //cout<<d[gosp].nazwa<<"-"<<d[gosc].nazwa<<endl;
    i++;
}


}
void Kolejka::zmiana_kolejki(){
for(int i=0;i<wielkosc;i++){
    if(d[i].indeks!=wielkosc){
        d[i].indeks--;
        if(d[i].indeks<1) d[i].indeks=(wielkosc-1);
    }
}


};
void Kolejka::dzien_meczowy(){

    int i=1;
    int gosp,gosc,wyb,bramka,bramkb;
    int czsezonu=1;
    nr_kolejki++;
    if(nr_kolejki>(wielkosc-1)){
        czsezonu=2;
    }
    while(i<=(wielkosc/2)){
        if(i==1){
            if(nr_kolejki%2==0){
                gosp=wybor_druzyny(i);
                gosc=wybor_druzyny(wielkosc+1-i);
            }
            else{
                gosc=wybor_druzyny(i);
                gosp=wybor_druzyny(wielkosc+1-i);
            }
        }
        else{
            if(i%2==0){
               gosp=wybor_druzyny(i);
               gosc=wybor_druzyny(wielkosc+1-i);
            }
            else{
                gosc=wybor_druzyny(i);
                gosp=wybor_druzyny(wielkosc+1-i);
            }
        }
        if(czsezonu==2 && i!=1) swap(gosp,gosc);
        cout<<"Mecz nr"<<i<<endl<<d[gosp].nazwa<<"-"<<d[gosc].nazwa<<endl;
        cout<<"Wybierz czy chcesz wprowadzic wynik recznie, czy zasymulowac mecz"<<endl
            <<"1-Recznie"<<endl<<"2-Symulacja"<<endl;
        do{
            cin>>wyb;
        }while(wyb!=1 && wyb!=2);
        if(wyb==1){
            int wyb2;
            do{
                cout<<"Podaj bramki strzelone przez gospodarzy:"<<endl;
                cin>>bramka;
                cout<<"Podaj bramki strzelone przez gosci:"<<endl;
                cin>>bramkb;
                cout<<"Czy zatwierdzasz wybor?"<<endl<<"1-Tak"<<endl<<"2-Nie"<<endl;
                do{
                    cin>>wyb2;
                }while(wyb2!=1 && wyb2!=2);

            }while(wyb2!=1);
        }
         else{
            int wyb3;
            rozgrywka(d[gosp],d[gosc],bramka,bramkb);

    }

            if(bramka>bramkb){
                d[gosp].mecz(bramka,bramkb,3);
                d[gosc].mecz(bramkb,bramka,0);
            }
            else if(bramka==bramkb){
                d[gosp].mecz(bramka,bramkb,1);
                d[gosc].mecz(bramkb,bramka,1);
            }
            else{
                d[gosp].mecz(bramka,bramkb,0);
                d[gosc].mecz(bramkb,bramka,3);
            }


    string wynik=d[gosp].nazwa+"-"+d[gosc].nazwa+" "+to_string(bramka)+":"+to_string(bramkb);
    tab[i]=wynik;
    cout<<tab[i]<<endl;
    i++;

}

        sortowanie_tabeli(d,0,wielkosc-1);

}
void Kolejka::wypisywanie_wynikow(){
    cout<<"Wyniki meczow "<<d[0].mecze<<" kolejki:"<<endl;
    for(int i=0;i<wielkosc;i++){
        cout<<tab[i]<<endl;
    }



}
int Kolejka::porownanie(Druzyna a,Druzyna b){
    if(a.nazwa==b.nazwa) return 3;
    else{
    if(a.pkt>b.pkt) return 1;
    else if(a.pkt<b.pkt) return 2;
    else {
        if(a.bilans>b.bilans) return 1;
        else if(a.bilans<b.bilans) return 2;
        else {
            if(a.bramki_zdobyte>b.bramki_zdobyte) return 1;
            else if(a.bramki_zdobyte<b.bramki_zdobyte) return 2;
            else {
                int wyb;
                cout<<"Ktory klub ma byc wyzej?"<<endl
                <<"1-"<<a.nazwa<<endl<<"2-"<<b.nazwa<<endl;
                do{
                    cin>>wyb;
                }while(wyb!=1 && wyb!=2);
                return wyb;
            }
        }
    }
    }

}
void Kolejka::sortowanie_tabeli(Druzyna tab[],int left,int right){
    int i = left;
    int j = right;
    Druzyna x = tab[( left + right ) / 2 ];
    do
    {
        while( porownanie(tab[i],x)==1 )
             i++;

        while( porownanie(tab[j],x)==2  )
             j--;

        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );

            i++;
            j--;
        }
    } while( i <= j );

    if( left < j ) sortowanie_tabeli( tab, left, j );

    if( right > i ) sortowanie_tabeli( tab, i, right );



};
void Kolejka::zapis_do_pliku(string Sciezka){
ofstream plik;
string linia;
plik.open(Sciezka+".txt");
if(!plik.good()){
    cout<<"Nie udalo sie otworzyc pliku !"<<endl;

}
else{
    plik<<wielkosc<<" "<<nr_kolejki<<endl;
   for(int i=0;i<wielkosc;i++){
        plik<<d[i].indeks<<" "<<d[i].nazwa<<" "<<d[i].pkt<<" "<<d[i].mecze<<" "<<d[i].zwyciestwa<<" "<<d[i].remisy<<" "<<d[i].porazki
        <<" "<<d[i].bramki_zdobyte<<" "<<d[i].bramki_stracone<<" "<<d[i].bilans<<endl;


   }
}
plik.close();
}
void Kolejka::zapis_tabeli(string Sciezka){
    string Sciezka2=Sciezka+"Kolejka_nr"+to_string(d[0].mecze)+".txt";
    ofstream plik;
    string linia;
    plik.open(Sciezka2);
if(!plik.good()){
    cout<<"Nie udalo sie otworzyc pliku !"<<endl;

}
else{
    plik<<"Tabela "<<Sciezka<<" po kolejce nr"<<nr_kolejki<<endl;
    plik.width(3);
    plik<<"Poz";
    plik.width(26);
    plik<<"Druzyna";
    plik.width(5);
    plik<<"Pkt";
    plik.width(5);
    plik<<"M";
    plik.width(5);
    plik<<"W";
    plik.width(5);
    plik<<"R";
    plik.width(5);
    plik<<"P";
    plik.width(5);
    plik<<"+";
    plik.width(5);
    plik<<"-";
    plik.width(7);
    plik<<"bilans";
    plik<<endl;
    for(int i=0;i<wielkosc;i++){
        plik.width(3);
        plik<<i+1;
        plik.width(20);
        plik<<d[i].nazwa;
        plik.width(5);
        plik<<d[i].pkt;
        plik.width(5);
        plik<<d[i].mecze;
        plik.width(5);
        plik<<d[i].zwyciestwa;
        plik.width(5);
        plik<<d[i].remisy;
        plik.width(5);
        plik<<d[i].porazki;
        plik.width(5);
        plik<<d[i].bramki_zdobyte;
        plik.width(5);
        plik<<d[i].bramki_stracone;
        plik.width(7);
        if(d[i].bilans>0) plik<<"+";
        plik<<d[i].bilans;
        plik<<endl;

        }
    plik<<"Wyniki spotkan "<<nr_kolejki <<" kolejki: "<<endl;
        for(int i=0;i<wielkosc;i++){
            plik<<tab[i]<<endl;
    }


}
plik.close();
}
Kolejka::~Kolejka(){
    //dtor
}

