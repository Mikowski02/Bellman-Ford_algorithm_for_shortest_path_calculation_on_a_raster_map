#ifndef INTERFACE_H
#define INTERFACE_H
#include <fstream>

using namespace std;

/**
 * @brief wyswietlanie tablicy znaków
 * @param T - wyswietlana tablica
 * @param n - ilosc wierszy tablicy
 * @param m - ilosc kolumn tablicy
 */
void wyswietl_char(char T[], int n, int m);

/**
 * @brief wyswietlanie tablicy liczb całkowitych
 * @param T - wyswietlana tablica
 * @param n - ilosc wierszy tablicy
 * @param m - ilosc kolumn tablicy
 * @note funkcja niewykorzystana w ostatecznej wersji programu
 * jednak może być przydatna w przypadku chęci zweryfikowania wyglądu tablic
 * lub znalezienia błędu
 */
void wyswietl_int(int T[], int n, int m);

/**
 * @brief wczytywanie mapy z pliku
 * @param plikin - zmienna plikowa
 * @param T - tablica w której bedziemy zapisywac mapę
 * @param nazwa - nazwa pliku z którego bedziemy odczytywac mapę
 */
void wczytaj_map(ifstream &plikin, char *&T, string nazwa);

/**
 * @brief Wyswietlanie wytyczonej trasy na mapie
 * @param cel - wspolrzedne celu
 * @param P - każda komórka tablicy P reprezentuje odpowiedni węzeł
 * i zawiera nr id kolejnego węzła na drodze do punktu startowego
 * @param p - tablica z mapą z naniesioną trasą
 * @param mapa - tablica z zapisana mapą
 * @param zrodloid - nr id punktu startowego
 */
void pokazTrase(int cel, int P[], char *&p, char mapa[], int zrodloid);

#endif // INTERFACE_H
