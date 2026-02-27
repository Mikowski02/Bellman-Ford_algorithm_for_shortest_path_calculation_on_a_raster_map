#ifndef OBLICZENIOWE_H
#define OBLICZENIOWE_H

using namespace std;

/**
 * @brief wezel -
 * Struktura zawierająca współrzędne węzła
 */
struct wezel
{
    /// wsp x
    int x;
    /// wsp y
    int y;
};

/**
 * @brief krawedz -
 * Struktura zawierająca parametry krawedzi łączącej wezły
 */
struct krawedz
{
    /// nr id węzła początku krawędzi
    int pocz;
    /// nr id węzła końca krawędzi
    int kon;
    /// waga krawedzi
    int waga;
};

/**
 * @par w - liczba wierszy mapy
 */
const int w = 15;
/**
 * @par k- liczba kolumn mapy
 */
const int k = 30, kosztmax = w * k;
/**
 * @par kierunki
 * tablica ze wspólrzędnościowymi zapisami
 * kierunków w których możemy się poruszać
 */
const wezel kierunki[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

/**
 * @brief obliczanie numeru id węzła
 * @param wsp - wspólrzedne węzła
 * @return numer id węzła
 */
int index(wezel wsp);

/**
 * @brief obliczanie współrzędnych węzła
 * @param id - numer id węzła
 * @return współrzedne węzła
 */
wezel wsp(int in);

/**
 * @brief tworzenie krawedzi miedzy węzłami
 * @param id - numer id węzła
 * @param mapa - tablica z zapisaną mapą
 * @param kierunek - numer kierunku (z tablicy z kierunkami)
 * @see kierunki[] krawedz wezel wsp() index()
 * @return wygenerowana krawędź
 */
krawedz generujKrawedz(int id, int kierunek, char mapa[]);

/**
 * @brief algorytm Bellmana-Forda
 * @param G - tablica kosztu dotarcia do każdego węzła
 * @param mapa - tablica z zapisaną mapą
 * @see generujKrawedz()
 */
void BellmanFord(int *&G, char mapa[]);

/**
 * @brief wyznacza trasy z każdego węzła do punktu startowego
 * @param G - tablica kosztu dotarcia do każdego węzła
 * @param P - każda komórka tablicy P reprezentuje odpowiedni węzeł
 * i zawiera nr id kolejnego węzła na drodze do punktu startowego
 * @param mapa - tablica z zapisaną mapą
 * @see generujKrawedz
 */
void znajdzDrogi(int G[], int *&P, char mapa[]);

#endif // OBLICZENIOWE_H
