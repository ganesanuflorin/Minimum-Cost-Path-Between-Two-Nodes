#ifndef ALGO_H
#define ALGO_H

#include <vector>

/*
 * 
 * edge.first  -> indexul vecinului 
 * edge.second -> costul
 */
typedef std::pair<int, int> edge;

/**
 * Pentru un grafic dat T, calculeaza distanta de la fiecare nod la fiecare alt nod din grafic.
 * 
 * @graph: Graficul este reprezentat folosind liste de adiacenta(graficul[i] - va ofera vecinii nodului i)
 * @returns: Returneaza matricea adiacenta cu distante minime dintre fiecare nod. Daca nu exista nici o cale          reach node j from i, store -1 in the matrix. (print it as "inf" in the tests)
 */
std::vector<std::vector<int>> shortest_path_all(const std::vector<std::vector<edge>>& graph);

#endif
