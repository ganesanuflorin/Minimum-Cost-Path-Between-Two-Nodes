#include "algo.h"
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

// o functie utilitara care gaseste nodul cu distanta minima, de la
// de la setul de noduri neincluse inca in arborele de distanta minima 
int minDistance(int dist[], bool sptSet[], int size) {
    int min = INF;
    int min_index = 0;

    for (int v = 0; v < size; ++v) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

std::vector<std::vector<int>> shortest_path_all(const std::vector<std::vector<edge>>& graph) {
    int size = graph.size();

    vector< vector<int> > final_matrix(size, vector<int>(size, INF));

    for (int i = 0; i < size; ++i) {
        for (auto& it : graph[i]) {
            final_matrix[i][it.first] = it.second;
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                final_matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (final_matrix[i][j] < 0) {
                return vector<vector<int>>(size, vector<int>(size, -1));
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        // Array ul de output.  dist[i] o sa tina ceea mai scurta 
        //distanta de la src la i
        int dist[size];

        // sptSet[i] o sa fie true daca nodul i e inclus in arbore 
        // sau distanta minima de la src la i s-a finalizat 
        bool sptSet[size];

        // initializam distantele cu inf si sptSet cu false 
        for (int j = 0; j < size; ++j) {
            dist[j] = INF;
            sptSet[j] = false;
        }

         // distanta de la nod la el insusi e mereu 0
        dist[i] = 0;

       // Gasim cea mai scurta cale pentru toate nodurile
        for (int count = 0; count < size - 1; ++ count) {
            // Alegem nodul cu distanta minima  din setul de noduri neprocesate 
            // inca. u e mereu egal cu src la prima iterare 
            int u = minDistance(dist, sptSet, size);

            // marcam nodul ca procesat
            sptSet[u] = true;

            // actualizam distanta nodurile adiacente nodului ales

            for (int v = 0; v < size; ++v) {
                // Actualizam dist[v] doar daca nu e in sptSet, exista o muchie de la  
                // u to v, si costul total al caii de la  src la  v prin u este 
                // mai mic decat valoarea curenta a dist[v] 
                if (!sptSet[v] && final_matrix[u][v] && dist[u] != INF
                && dist[u] + final_matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + final_matrix[u][v];
                }
            }
        }
        for (int h = 0; h < size; ++h) {
            final_matrix[i][h] = dist[h];
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (final_matrix[i][j] == INF) {
                final_matrix[i][j] = -1;
            }
        }
    }
    return final_matrix;
}