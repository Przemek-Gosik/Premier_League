#include <iostream>
#include "Druzyna.h"
#include "Kolejka.h"
using namespace std;

int main()
{   int wyb;
    string nazwa;
    cout<<"Podaj nazwe ligi"<<endl;
    cin>>nazwa;
    Kolejka k(nazwa+".txt");
    do{
    cout << "Wybierz co chcesz zrobic " << endl
        <<"1-Wyswietlenie tabeli"<<endl
        <<"2-Wyswietlenie meczow "<<(k.nr_kolejki)+1<<" kolejki"<<endl
        <<"3-Rozegranie kolejki"<<endl
        <<"4-Zamkniecie programu i zapis do pliku"<<endl;
        do{
            cin>>wyb;
        }while(wyb<1 || wyb>4);
    switch (wyb){
case 1:
    {
    k.wyswietlanie_tabeli();
    }
    break;
case 2:
    {
    k.wypisywanie_meczy();
    }
    break;
case 3:
    {
    k.dzien_meczowy();
    k.zmiana_kolejki();
    k.zapis_tabeli(nazwa);
    k.zapis_do_pliku(nazwa);
    }
    break;

default:
    {


    }
break;
    }
    }while(wyb!=4);
    return 0;
}
