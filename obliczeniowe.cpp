#include "obliczeniowe.h"

int index(wezel wsp)
{
    int id;
    id = wsp.y * k + wsp.x;
    return id;
}

wezel wsp(int id)
{
    wezel wynik;
    wynik = {id % k, id / k};
    return wynik;
}

krawedz generujKrawedz(int id, int kierunek, char mapa[])
{
    wezel wez = wsp(id);
    wezel sasiad;
    sasiad.x = wez.x + kierunki[kierunek].x;
    sasiad.y = wez.y + kierunki[kierunek].y;
    int sasiadid = index(sasiad);

    krawedz kr;
    kr.pocz = id;
    kr.kon = sasiadid;

    if (sasiad.x < 0 || sasiad.y < 0 || sasiad.x >= k || sasiad.y >= w)
        kr.waga = kosztmax + 1;
    else if (mapa[id] == '@' || mapa[sasiadid] == '@')
        kr.waga = kosztmax + 1;
    else
        kr.waga = 1;

    return kr;
}

void BellmanFord(int *&G, char mapa[])
{
    for (int i = 0; i < w * k; i++)
        for (int j = 0; j < w * k; j++)
            for (int u = 0; u < 4; u++)
            {
                krawedz e = generujKrawedz(j, u, mapa);
                if (G[j] != kosztmax + 1 && e.kon >= 0)
                {
                    if (G[e.kon] > G[e.pocz] + e.waga)
                        G[e.kon] = G[e.pocz] + e.waga;
                }
            }
}

void znajdzDrogi(int G[], int *&P, char mapa[])
{
    for (int i = 0; i < w * k; i++)
        P[i] = -1;

    for (int j = 0; j < w * k; j++)
        for (int u = 0; u < 4; u++)
        {
            krawedz e = generujKrawedz(j, u, mapa);
            if (e.waga < kosztmax)
                if (G[e.kon] < G[e.pocz])
                    P[j] = e.kon;
        }
}
