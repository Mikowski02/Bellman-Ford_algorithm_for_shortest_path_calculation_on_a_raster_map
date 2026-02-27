#include "interface.h"
#include "obliczeniowe.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void wyswietl_char(char T[], int n, int m)
{
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << T[e];
            e++;
        }
        cout << endl;
    }
    cout << endl;
}

void wyswietl_int(int T[], int n, int m)
{
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(4) << T[e];
            e++;
        }
        cout << endl;
    }
    cout << endl;
}

void wczytaj_map(ifstream &plikin, char *&T, string nazwa)
{
    char t;
    plikin.open(nazwa);

    if (!plikin.good())
    {
        plikin.close();
        cout << "problem z otwarciem pliku" << endl;
        return;
    }

    plikin >> t;

    while (t != '@' && t != '.')
        plikin >> t;

    T[0] = t;
    for (int i = 1; i < w * k; i++)
        plikin >> T[i];

    plikin.close();
}

void pokazTrase(int cel, int P[], char *&p, char mapa[], int zrodloid)
{
    int e = 0;

    for (int j = 0; j < w * k; j++)
        p[j] = mapa[j];

    int temp = cel;
    while (temp != zrodloid)
    {
        p[temp] = '*';
        temp = P[temp];
    }

    p[zrodloid] = '*';

    cout << endl
         << "Trasa:" << endl;

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << p[e];
            e++;
        }
        cout << endl;
    }
}
