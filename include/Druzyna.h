#ifndef DRUZYNA_H
#define DRUZYNA_H
#include <string>
#include <iostream>
using namespace std;
class Druzyna
{
    public:
        string nazwa;
        int indeks,pkt,mecze,zwyciestwa,remisy,porazki,bramki_zdobyte,bramki_stracone,bilans,status_druzyny,sila_defensywy,
        sila_ofensywy,forma_ofensywy,forma_defensywy,mobilizacja_zespolu,pomysl_taktyczny,overall;
        void wczytaj(int mi,string n,int p,int me,int zw,int r,int po,int bz,int bs,int bi);
        void wczytanie_na_mecz();
        void losowanie_zmiennych();
        int wczytanie(int zakres);
        int sumowanie();
        int losowanie_z_prawdopodobienstwem();
        void wcztywanie_zmiennych();
        void oblicz_bilans(int ba,int bb);
        void mecz(int ba,int bb,int pk);
};

#endif // DRUZYNA_H
