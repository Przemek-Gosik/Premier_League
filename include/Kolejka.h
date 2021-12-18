#ifndef KOLEJKA_H
#define KOLEJKA_H
#include "Druzyna.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
class Kolejka
{
    public:
        string tab[20];
        int nr_kolejki;
        int wielkosc;
        Kolejka(string Sciezka);
        int wybor_druzyny(int ind);
        void zmiana_kolejki();
        void wypisywanie_meczy();
        void rozgrywka(Druzyna &a,Druzyna &b,int &bramka,int &bramkb);
        void zwyciestwo(Druzyna a,Druzyna b,int &bramka,int &bramkb);
        void remis(Druzyna a,Druzyna b,int &bramka,int &bramkb);
        void dzien_meczowy();
        void wypisywanie_wynikow();
        int porownanie(Druzyna a,Druzyna b);
        void sortowanie_tabeli(Druzyna tab[],int left,int right);
        void wyswietlanie_tabeli();
        void zapis_tabeli(string Sciezka);
        void zapis_do_pliku(string Sciezka);
        virtual ~Kolejka();

};

#endif // KOLEJKA_H
