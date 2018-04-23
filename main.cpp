#include <iostream>
#include <ctime>
#include <cstdlib>

// RAND_MAX  - maximum value of function rand.

using namespace std;

template <typename T>                              // Deklaracja szablonu przed rozpoczeciem kazdej funkcji
void Wyswietl_Tablice(T *tablica, size_t rozmiar){ // Funkcja Wyswietl tablice. Dane wej: wskaznik na tablice i jej rozmiar.
    for(size_t i=1 ; i < rozmiar ; ++i){           // Wykonanie petli od 1 do rozmiaru tablicy z pre-inkrementacja
        cout<<tablica[rozmiar]<<" ";               // Wyswietlanie liczb kolejno z tablicy
    }
    cout<<endl;                                    // Po zakonczeniu - przejscie do drugiej linii.
}

int main(void) {
    size_t rozmiar = 100;                           // Deklaracja rozmiaru o typie size_t
    int *tablica = new int [rozmiar + 1];          // Deklaracja wskaznika na tablice i przypisanie jej wartosc rozmiaru o jedna jednostke wieksza.

    for(int i=1 ; i<rozmiar ; ++i){                // Wykonanie petli od 1 do rozmiaru tablicy z pre inkrementacja
        tablica[i] = (100.0 * rand())/RAND_MAX;    // Wpisywanie do kazdego miejsca w tablicy losowa wartosc
    }
    Wyswietl_Tablice(tablica,rozmiar);              // Wywolanie funkcji Wyswietl Tablice z argumentami - tablica oraz rozmiar 10.
}
