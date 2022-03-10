#include "algo.h"
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

std::vector<std::vector<int>> shortest_path_all(const std::vector<std::vector<edge>>& graph) {
    int V = graph.size(); // Numarul de varfuri din graf
    
    vector< vector<int> > final_matrix(V + 1, vector<int>(V + 1, INF));

    for (int k = 0; k < V; ++k) {
        // initializam distantele corespunzatoare tuturor varfurilor cu inf
        int dist[V];
        for (int i = 0; i < V; ++i) {
            dist[i] = INF;
        }

        // intializam distanta corespunzatoare sursei cu 0
        dist[k] = 0;

        // Relaxam toate muchiile de |V| - 1 ori. 
        // cea mai scurta cale de la src la celalalt
        // nodurile pot sa aiba maxim |V| - 1 muchii
        for (int i = 0; i < V - 1; ++i) {
            for (int j = 0; j < V; ++j) {
                for (auto& it : graph[j]) {
                    if (dist[j] + it.second < dist[it.first]) {
                        dist[it.first] = dist[j] + it.second;
                    }
                }   
            }
        }

        // verificam daca exista cicluri de cost negativ. 
        // Pasul urmator garanteaza cea mai scurta 
        // distanta daca graful nu contine 
        // ciclu de cost negativ.  Daca gasim o 
        // cale mai scurta atunci este un ciclu.
        for (int i = 0; i < V; ++i) {
            for (auto& it : graph[i]) {
                int x = i;
                int y = it.first;
                int weight = it.second;

                if (dist[x] != INF && dist[x] + weight < dist[y]) {
                    return vector<vector<int>>(V, vector<int>(V, -1));
                }
            }
        }

        for (int i = 0; i < V; ++i) {
            final_matrix[k][i] = dist[i];
        }

    }

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (final_matrix[i][j] == INF) {
                final_matrix[i][j] = -1;
            }
        }
    }

    return final_matrix;
}