#include "Grafo.h"

int Minimo(int Val1, int Val2)
{
    int Min= Val1;
    if (Val2 < Min)
    Min= Val2;
    return Min;
}

template <class T>
Grafo<T>::Grafo()
{
    int Ind1, Ind2;

    for (Ind1= 0; Ind1 < MAX; Ind1++){
        DistMin[Ind1]= 0;
        Vertices[Ind1]= 0;

        for (Ind2= 0; Ind2 < MAX; Ind2++){

            if (Ind1 != Ind2){
                MatAdy[Ind1][Ind2] = 999;
                MatAux[Ind1][Ind2] = 999;
            }

            else{
                MatAdy[Ind1][Ind2] = 0;
                MatAux[Ind1][Ind2] = 0;
            }

            CerTran[Ind1][Ind2]= 0;
            VerInt[Ind1][Ind2]= 0;
        }
    }

    NumVer= 0;
}

template <class T>
void Grafo<T>::Lee()
{
    int NumArcos, Indice, Origen, Destino;
    cout<<"\n\n Ingrese numero de vertices de la grafica dirigida: ";
    cin>>NumVer;
    for (Indice = 0; Indice < NumVer; Indice++){
        cout<<"\n\n Ingrese el nombre del vertice de la grafica dirigida: ";
        cin>>Vertices[Indice];
    }
    cout<<"\n\n Total de aristas de la grafica dirigida: ";
    cin>>NumArcos;
    Indice= 0;
    while (Indice < NumArcos){
        cout<<"\n\n Ingrese vertices origen: ";
        cin>>Origen;
        cout<<"\n\n Ingrese vertices destino: ";
        cin>>Destino;
        cout<<"\n\n Costo de origen a destino: ";
        cin>>MatAdy[Origen - 1][Destino - 1];
        MatAux[Origen - 1][Destino - 1] = MatAdy[Origen - 1][Destino - 1];
        Indice++;
    }
}

template <class T>
void Grafo<T>::Imprime(int Opc)
{
    int Ind1, Ind2;
    switch(Opc)
    {
        case 0: cout<<"\n\n Matriz de Adyacencia o de Costos: \n\n";
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
            {
                cout<<Vertices[Ind1]<<": ";
                for (Ind2= 0; Ind2 < NumVer; Ind2++)
                    cout<<MatAdy[Ind1][Ind2]<<'\t';
                cout<<endl;
            }
            break;
        case 1: cout<<"\n\n Cerradura Transitiva de la Matriz de Adyacencia: "<<endl;
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
            {
                cout<<Vertices[Ind1] <<": ";
                for (Ind2= 0; Ind2 < NumVer; Ind2++)
                    cout<<CerTran[Ind1][Ind2]<<'\t';
                cout<<endl;
            }
            break;
        case 2: cout<<"\n\n Matriz de Distancias Minimas: "<<endl;
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
            {
                cout<<Vertices[Ind1]<<": ";
                for (Ind2= 0; Ind2 < NumVer; Ind2++)
                    cout<<MatAux[Ind1][Ind2]<<'\t';
                cout<<endl;
            }
            break;
        case 3: cout<<"\n\n Vertices Intermedios para lograr distancias minimas: "<<endl;
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
            {
                for (Ind2= 0; Ind2 < NumVer; Ind2++)
                    cout<<VerInt[Ind1][Ind2]<<'\t';
                cout<<endl;
            }
            break;
        case 4: cout<<"\n\n Distancias minimas a partir del vertice: "<<Vertices[0]<<"\n\n";
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
                cout<<' '<<DistMin[Ind1]<<'\t'<<endl;
            break;
        default: break;
    }
    cout<<endl;
}
template <class T>
void Grafo<T>::Guarda(int Opc)
{
    int Ind1, Ind2;
    switch(Opc){
        case 1:
            {
                ofstream archWarshall;
                archWarshall.open("Warshall.txt", ios::out);
                for (Ind1= 0; Ind1 < NumVer; Ind1++){
                    for (Ind2= 0; Ind2 < NumVer; Ind2++){
                        archWarshall<<CerTran[Ind1][Ind2]<<'\t';
                    }
                    archWarshall<<endl;
                }
                archWarshall.close();
                break;
            }
        case 2:
            {
                ofstream archFloyd;
                archFloyd.open("Floyd.txt", ios::out);
                for (Ind1= 0; Ind1 < NumVer; Ind1++)
                {
                    for (Ind2= 0; Ind2 < NumVer; Ind2++){
                        archFloyd<<MatAux[Ind1][Ind2]<< '\t';
                    }
                    archFloyd<<endl;
                }
                archFloyd.close();
                break;
            }
        case 3:
            {
                ofstream archFloydVerInt;
                archFloydVerInt.open("FloydVerInt.txt", ios::out);
                for (Ind1= 0; Ind1 < NumVer; Ind1++)
                {
                    for (Ind2= 0; Ind2 < NumVer; Ind2++){
                        archFloydVerInt<<VerInt[Ind1][Ind2]<<'\t';
                    }
                    archFloydVerInt<<endl;
                }
                archFloydVerInt.close();
                break;

            }
        case 4:
            {
                ofstream archDijkstra;
                archDijkstra.open("Dijkstra.txt", ios::out);
                for (Ind1= 0; Ind1 < NumVer; Ind1++){
                    archDijkstra<<DistMin[Ind1]<<'\t'<<endl;
                }
                archDijkstra.close();
                break;
            }
        default: break;
    }
}
template <class T>
void Grafo<T>::Warshall()
{
    int Ind1, Ind2, Ind3;
    for (Ind1= 0; Ind1 < NumVer; Ind1++){
        for (Ind2= 0; Ind2 < NumVer; Ind2++){
            if (MatAdy[Ind1][Ind2] != 999){
                CerTran[Ind1][Ind2]= 1;
            }
        }
    }
    for (Ind3= 0; Ind3 < NumVer; Ind3++){
        for (Ind1= 0; Ind1 < NumVer; Ind1++){
            for (Ind2= 0; Ind2 < NumVer; Ind2++){
                CerTran[Ind1][Ind2] |= CerTran[Ind1][Ind3] && CerTran[Ind3][Ind2];
            }
        }
    }
}
template <class T>
void Grafo<T>::Floyd()
{
    int Ind1, Ind2, Ind3;
    for (Ind3= 0; Ind3 < NumVer; Ind3++){
        for (Ind1= 0; Ind1 < NumVer; Ind1++){
            for (Ind2= 0; Ind2 < NumVer; Ind2++){
                if ( (MatAux[Ind1][Ind3] + MatAux[Ind3][Ind2]) < MatAux[Ind1][Ind2]){
                    MatAux[Ind1][Ind2] = MatAux[Ind1][Ind3] + MatAux[Ind3][Ind2];
                }
            }
        }
    }
}
template <class T>
void Grafo<T>::FloydVerInt()
{
    int Ind1, Ind2, Ind3;
    for (Ind3 = 0; Ind3 < NumVer; Ind3++){
        for (Ind1 = 0; Ind1 < NumVer; Ind1++){
            for (Ind2 = 0; Ind2 < NumVer; Ind2++){
                if ((MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2]) < MatAdy[Ind1][Ind2]){
                    MatAdy[Ind1][Ind2] = MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2];
                    VerInt[Ind1][Ind2] = Vertices[Ind3];
                }
            }
        }
    }
}
template <class T>
void Grafo<T>::Dijkstra()
{
    int Aux[MAX], VertInc[MAX], Ver1, Ver2, Ind1, Ind2, Menor, Band,
    Origen;
    for (Ind1= 0; Ind1 < NumVer; Ind1++){
        Aux[Ind1]= 0;
        VertInc[Ind1]= 0;
    }
    cout<<"\n\n Ingrese vertice origen: ";
    cin>>Origen;
    Origen -= 1;
    Aux[Origen]= 1;
    for (Ind1= 0; Ind1 < NumVer; Ind1++){
        DistMin[Ind1]= MatAdy[Origen][Ind1];
    }
    for (Ind1= 0; Ind1<NumVer; Ind1++){
        Menor= 999;
        for (Ind2= 1; Ind2 < NumVer; Ind2++){
            if (DistMin[Ind2] < Menor && !Aux[Ind2]){
                Ver1= Ind2;
                Menor= DistMin[Ind2];
            }
        }
        VertInc[Ind1]= Ver1;
        Aux[Ver1]= 1;
        Ver2= 1;
        while (Ver2 < NumVer){
            Band=0;
            Ind2= 1;
            while (Ind2 < NumVer && !Band){
                if (VertInc[Ind2] == Ver2){
                    Band= 1;
                }
                else{
                    Ind2++;
                }
            }
            if (!Band){
                DistMin[Ver2] = Minimo (DistMin[Ver2], DistMin[Ver1] + MatAdy[Ver1][Ver2]);
            }
            Ver2++;
        }
    }
}

template class Grafo<int>;
