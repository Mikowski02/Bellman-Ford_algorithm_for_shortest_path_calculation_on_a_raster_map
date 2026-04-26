#include "obliczeniowe.h"

int index(wezel wsp) {
  int id;
  id = wsp.y * k + wsp.x;
  return id;
}

wezel wsp(int id) {
  wezel wynik;
  wynik = {id % k, id / k};
  return wynik;
}

krawedz generujKrawedz(int id, int kierunek, const char mapa[]) {
  wezel wez = wsp(id);
  wezel sasiad;
  sasiad.x = wez.x + kierunki[kierunek].x;
  sasiad.y = wez.y + kierunki[kierunek].y;
  int sasiadid = index(sasiad);

  krawedz kr;
  kr.pocz = id;
  kr.kon = sasiadid;

  if (sasiad.x < 0 || sasiad.y < 0 || sasiad.x >= k || sasiad.y >= w) {
    kr.waga = kosztmax + 1;
    kr.kon = -1; // Oznaczamy cel jako nieistniejący, aby nie wyjść poza tablicę
  } else if (mapa[id] == '@' || mapa[sasiadid] == '@')
    kr.waga = kosztmax + 1;
  else
    kr.waga = 1;

  return kr;
}

void BellmanFord(int *G, const char mapa[]) {
  // The Bellman-Ford algorithm relaxes all edges |V|-1 times.
  // For a grid, |V| = w * k.
  for (int i = 0; i < (w * k) - 1; i++) {
    bool changed = false;
    for (int j = 0; j < w * k; j++) { // For each vertex 'j'
      for (int u = 0; u < 4; u++) {
        krawedz e = generujKrawedz(j, u, mapa); // Generate its outgoing edges
        // If a path to the start of the edge exists and the edge is valid
        if (G[e.pocz] < kosztmax && e.kon != -1 && e.waga < kosztmax) {
          if (G[e.kon] > G[e.pocz] + e.waga) { // Relax the edge
            G[e.kon] = G[e.pocz] + e.waga;
            changed = true;
          }
        }
      }
    }
    if (!changed)
      break; // Optymalizacja: jeśli nie było zmian, przerywamy pętlę
  }
}

void znajdzDrogi(const int G[], int *P, const char mapa[]) {
  for (int i = 0; i < w * k; i++)
    P[i] = -1;

  for (int j = 0; j < w * k; j++)
    for (int u = 0; u < 4; u++) {
      krawedz e = generujKrawedz(j, u, mapa);
      if (e.waga < kosztmax && G[e.pocz] < kosztmax && G[e.kon] < kosztmax)
        if (G[e.pocz] == G[e.kon] + e.waga)
          P[j] = e.kon;
    }
}
