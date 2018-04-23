#include <iostream>
#include <ctime>
#include <cstdlib>

// RAND_MAX  - maximum value of function rand.

using namespace std;

template <typename T>                              // Deklaracja szablonu przed rozpoczeciem kazdej funkcji
void Wyswietl_Tablice(T *tablica, size_t rozmiar){ // Funkcja Wyswietl tablice. Dane wej: wskaznik na tablice i jej rozmiar.
    for(size_t i=1 ; i < rozmiar ; ++i){           // Wykonanie petli od 1 do rozmiaru tablicy z pre-inkrementacja
        cout<<tablica[i]<<" ";                     // Wyswietlanie liczb kolejno z tablicy
    }
    cout<<endl;                                    // Po zakonczeniu - przejscie do drugiej linii.
}

template <typename T>                                                               // Deklaracja szablonu przed rozpoczeciem kazdej funkcji
void Sprawdz_WezelGlowny (T *tablica, size_t rozmiar_glowny , size_t rozmiar) {     // Funkcja sprawdza czy lewy i prawy wezel lezal wobec rodzica w prawidlowej pozycji
    size_t lewy_wezel = 2 * rozmiar_glowny;                                         // Deklaracja lewego wezla przyjmuje wartosc 2 razy wieksza od rodzica
    size_t prawy_wezel = 2 * rozmiar_glowny + 1;                                    // Deklaracja prawego wezla przyjmuje wartosc 2 razy +1 wieksza od rodzica

    if(lewy_wezel < rozmiar && tablica[rozmiar_glowny] < tablica[lewy_wezel]){      // Jesli rozmiar lewego wezla jest mniejsza od rozmiaru calej tablicy i jesli wartosc rodzica jest mniejsza od wartosci lewego wezla
        tablica[rozmiar_glowny] = tablica[lewy_wezel];                              // Wartosc lewego wezla przepisana jest rodzicowi.
        tablica[lewy_wezel] = tablica[rozmiar_glowny];                              // Wartosc rodzica jest przepisana lewemu wezle.
        Sprawdz_WezelGlowny(tablica,lewy_wezel,rozmiar);                            // Nastepuje kolejne sprawdzanie prawidlowej pozycji wezla lewego wobec rodzica
    }

    if(prawy_wezel < rozmiar && tablica[rozmiar_glowny] < tablica[prawy_wezel]){    // Jesli rozmiar prawego wezla jest mniejsza od rozmiaru tablicy i jesli wartosc rodzica jest mniejsza od wartosci prawego wezla
        tablica[rozmiar_glowny] = tablica[prawy_wezel];                             // Wartosc prawego wezla przepisana jest rodzicowi
        tablica[prawy_wezel] = tablica[rozmiar_glowny];                             // Wartosc rodzica przepisana jest prawemu wezle
        Sprawdz_WezelGlowny(tablica, prawy_wezel, rozmiar);                         // Nastepuje kolejne sprawdzanie prawidlowej pozycji wezla prawego wobec rodzica
    }
}

template <typename T>
void Zbuduj_Kopiec ( T *tablica, size_t rozmiar) {
        for(size_t i = rozmiar/2; i > 0 ; --i){
            Sprawdz_WezelGlowny(tablica,i,rozmiar);
        }
}


template <typename T>
void Sortuj_Kopiec (T *tablica, size_t rozmiar){
    while(rozmiar > 1) {
        tablica[1] = tablica[rozmiar - 1];
        Sprawdz_WezelGlowny(tablica, 1, --rozmiar);
    }
}



int main(void) {
    size_t rozmiar = 10;                           // Deklaracja rozmiaru o typie size_t
    int *tablica = new int [rozmiar + 1];          // Deklaracja wskaznika na tablice i przypisanie jej wartosc rozmiaru o jedna jednostke wieksza.

    for(int i=1 ; i<rozmiar+1 ; ++i){              // Wykonanie petli od 1 do rozmiaru tablicy z pre inkrementacja
        tablica[i] = (100.0 * rand())/RAND_MAX;    // Wpisywanie do kazdego miejsca w tablicy losowa wartosc
    }
    Wyswietl_Tablice(tablica,rozmiar);             // Wywolanie funkcji Wyswietl Tablice z argumentami - tablica oraz rozmiar 10.
    Zbuduj_Kopiec(tablica,rozmiar);
    Sortuj_Kopiec(tablica,rozmiar);
    Wyswietl_Tablice(tablica,rozmiar);

    delete [] tablica;

    return 0;
}
