#include "interface.h"
#include "obliczeniowe.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void wyswietl_char(const char T[], int n, int m) {
  int e = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << T[e];
      e++;
    }
    cout << endl;
  }
  cout << endl;
}

void wyswietl_int(const int T[], int n, int m) {
  int e = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << setw(4) << T[e];
      e++;
    }
    cout << endl;
  }
  cout << endl;
}

bool wczytaj_map(ifstream &plikin, char *T, string nazwa) {
  char t;
  plikin.open(nazwa);

  if (!plikin.good()) {
    plikin.close();
    cout << "problem z otwarciem pliku" << endl;
    return false;
  }

  plikin >> t;

  while (t != '@' && t != '.')
    plikin >> t;

  T[0] = t;
  for (int i = 1; i < w * k; i++)
    plikin >> T[i];

  plikin.close();
  return true;
}

void pokazTrase(int cel, const int P[], char *p, const char mapa[],
                int zrodloid) {
  int e = 0;

  for (int j = 0; j < w * k; j++)
    p[j] = mapa[j];

  int temp = cel;
  int counter = 0;
  int max_steps = w * k; // Zabezpieczenie przed nieskończoną pętlą

  while (temp != zrodloid && counter < max_steps) {
    p[temp] = '*';
    temp = P[temp];
    counter++;
    // Dodatkowe zabezpieczenie przed wyjściem poza zakres tablicy
    if (temp < 0 || temp >= w * k)
      break;
  }

  p[zrodloid] = '*';

  cout << endl << "Trasa:" << endl;

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < k; j++) {
      cout << p[e];
      e++;
    }
    cout << endl;
  }
}
