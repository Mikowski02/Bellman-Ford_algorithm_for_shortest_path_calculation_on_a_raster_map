#include "interface.h"
#include "obliczeniowe.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

/**
 *@mainpage
 *@par Wytyczanie trasy robota
 * Program wytyczający najkrótszą możliwą trasę dla robota na mapie
 * rastrowej za pomocą algorytmu Bellmana-Forda.
 * @author Kacper Mik
 * @date 08.06.2022
 * @version 4
 */

int main() {
  /**
   * @par plikin -
   *  Zmienna plikowa do odczytu mapy z pliku
   * @par nazwa -
   *  Zmienna przechowująca nazwę pliku z mapą
   * @par mapa[]-
   * Tablica do zapisu mapy
   * @par p[]-
   *  Tablica z mapą z naniesioną trasą
   * @par G[]-
   *  Tablica kosztu dotarcia do każdego węzła
   * @par P[]-
   *  Każda komórka tablicy P reprezentuje odpowiedni węzeł
   * i zawiera nr id kolejnego węzła na drodze do punktu startowego
   * @par cel -
   *  Zmienna przechowująca współrzędne celu
   * @par zrodlo -
   *  Zmienna przechowująca współrzędne punktu startowego
   * @par zrodloid -
   *  Zmienna przechowująca adres id punktu startowego
   * @par celid -
   *  Zmienna przechowująca adres id celu
   * @par odp -
   *  Zmienna weryfikująca powtarzanie wytyczania trasy
   */
  ifstream plikin;
  string nazwa;
  char *mapa;
  mapa = new char[w * k];
  char *p;
  p = new char[w * k];
  int *G;
  G = new int[w * k];
  int *P;
  P = new int[w * k];
  wezel cel, zrodlo;
  int zrodloid, celid;
  char odp;

  cout << "podaj nazwe pliku z mapa" << endl;
  cin >> nazwa;

  string sciezka = "map/" + nazwa;
  if (!wczytaj_map(plikin, mapa, sciezka)) {
    delete[] p;
    delete[] P;
    delete[] G;
    delete[] mapa;
    system("pause");
    return 1;
  }

  cout << endl << "Mapa:" << endl;
  wyswietl_char(mapa, w, k);

  cout << "podaj swoje polozenie (wiersz, kolumna)" << endl;
  cin >> zrodlo.y >> zrodlo.x;
  while (zrodlo.y < 0 || zrodlo.x < 0 || zrodlo.y >= w || zrodlo.x >= k ||
         mapa[index(zrodlo)] == '@') {
    cout << "podaj poprawne wspolrzedne" << endl;
    cin >> zrodlo.y >> zrodlo.x;
  }

  zrodloid = index(zrodlo);

  do {
    cout << "podaj wspolrzedne celu (wiersz, kolumna)" << endl;
    cin >> cel.y >> cel.x;
    while (cel.y < 0 || cel.x < 0 || cel.y >= w || cel.x >= k ||
           mapa[index(cel)] == '@') {
      cout << "podaj poprawne wspolrzedne" << endl;
      cin >> cel.y >> cel.x;
    }

    celid = index(cel);

    for (int i = 0; i < w * k; i++)
      G[i] = kosztmax;
    G[zrodloid] = 0;

    BellmanFord(G, mapa);

    if (G[celid] == kosztmax) {
      cout << "nie da sie dojechac do celu :(" << endl;
      cout << endl << "czy wytyczyc inna trase? (T/N)" << endl;
      cin >> odp;
    }

    else {
      znajdzDrogi(G, P, mapa);

      pokazTrase(celid, P, p, mapa, zrodloid);

      zrodloid = celid;
      cout << endl << "czy wytyczyc kolejna trase? (T/N)" << endl;
      cin >> odp;
    }

  } while (odp == 'T');

  delete[] p;
  delete[] P;
  delete[] G;
  delete[] mapa;
  system("pause");
  return 0;
}
