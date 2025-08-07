/*Programadores:



*/
#include <iostream>
#include <locale>
#include <fstream>
#include "Grafo.h"
int Menu();

using namespace std;

int Menu()
{
    int Opc;
    do
    {
        cout<<"\n\nMenú - Sistema Ferroviario\n";
        cout<<"\n0. Ingresar datos e imprimir matriz de adyacencias";
        cout<<"\n1. Ciudades que están comunicadas entre sí (Warshall)";
        cout<<"\n2. Mínimo costo entre todas las ciudades (Floyd)";
        cout<<"\n3. Mínimo costo entre todas las ciudades y ciudades intermedias (FloydVerInt)";
        cout<<"\n4. Mínimo costo entre una ciudad y las otras (Dijkstra)";
        cout<<"\n5. Salir";
        cout<<"\n\nIngrese una opción: ";
        cin>>Opc;
    } while (Opc < 0 || Opc > 5);
    return Opc;
}

int main()
{
    setlocale(LC_CTYPE, "spanish");
    Grafo<int> graf;
    int Opc;
    do
    {
        Opc= Menu();
        switch (Opc)
        {
        case 0:
            cout<<"\n\n\nIngrese datos de ciudades y costos de pasajes\n";
            graf.Lee();
            graf.Imprime(0);
            break;
            case 1:
            {
                graf.Warshall();
                graf.Imprime(1);
                graf.Guarda(1);
                break;
            }
            case 2:
            {
                graf.Floyd();
                graf.Imprime(2);
                graf.Guarda(2);
                break;
            }
            case 3:
            {
                graf.FloydVerInt();
                graf.Imprime(3);
                graf.Guarda(3);
                break;
            }
            case 4:
            {
                graf.Dijkstra();
                graf.Imprime(4);
                graf.Guarda(4);
                break;
            }
        }
    } while (Opc < 5 && Opc >= 0);
    return 0;
}

