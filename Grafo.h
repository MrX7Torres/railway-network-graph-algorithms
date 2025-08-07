#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <locale>
#include <fstream>
#define MAX 10


using namespace std;

template <class T>
class Grafo
{
private:
    T MatAdy[MAX][MAX], MatAux[MAX][MAX];
    int NumVer, Vertices[MAX], DistMin[MAX], CerTran[MAX][MAX], VerInt[MAX][MAX];
public:
    Grafo();
    void Lee();
    void Imprime(int);
    void Guarda(int);
    void Warshall();
    void Floyd();
    void FloydVerInt();
    void Dijkstra();
};


#endif // GRAFO_H
