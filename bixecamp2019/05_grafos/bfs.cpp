#include "bits/stdc++.h"
using namespace std;

#define MAXV 1001000
typedef pair<int, int> pii;

int n, distancia[MAXV];
vector<pii> adj[MAXV];

void BFS(int fonte)
{
    for (int i = 0; i < MAXV; i++) // Marca os vértices como não visitados
        distancia[i] = -1;

    queue<int> fila;
    fila.push(fonte);     // Insere a fonte na fila
    distancia[fonte] = 0; // Iniciando a distancia da fonte como zero

    int aux;
    while (!fila.empty())
    {
        aux = fila.front(); // Pega o primeiro elemento da fila
        fila.pop();         // Apaga o primeiro elemento da fila

        for (auto viz : adj[aux])
        {
            if (distancia[viz] != -1) // Se foi visitado, não adiciona na fila
                continue;

            distancia[viz] = distancia[aux] + 1;
            fila.insert(viz);
        }
    }
}

// Vector de movimento

// bool valido(int x, int y){
//     if (x<0 || y<0) return false;
//     if (x>=n || y>=m) return false;
//     return true;
// }

// for (int i =0; i< tamanho_matrix; i++){
//     if valido(x+mx[i], y+ my[i] )
//     if...
// }