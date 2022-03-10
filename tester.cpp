#include "algo.h"
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

inline void scanning(int &number) {
    int character;
    bool negFlag;
    negFlag = 0;

    character = getchar_unlocked();

    if (character == '-') {
        negFlag = 1;
        character = getchar_unlocked();
    }

    number = 0;

    for (; (character > 47 && character < 58); character = getchar_unlocked()) {
        number = number * 10 + character - 48;
    }

    if (negFlag == 1) {
        number *= -1;
    }
}

inline void printing(int n) {
    char number[70];
    int contor = 0;

	do {
		number[contor++] = n % 10 + '0';
		n = n / 10;
	} while (n != 0);

    --contor;

    while (contor >= 0) {
        putchar(number[contor--]);
    }

    putchar(' ');
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " input_file\n";
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string test_no = argv[1];
    string input_file = "in/" + test_no + ".in";
    string output_file = "out/" + test_no + ".out";

    FILE *fout = freopen(output_file.c_str(), "w", stdout);
    FILE *fin = freopen(input_file.c_str(), "r", stdin);

    if (fout == nullptr || fin == nullptr) {
       return -1;
    }
    int n, m;
    // decomentati daca vreti sa masurati timpul
    //auto start = chrono::high_resolution_clock::now();

    scanning(n);
    scanning(m);

    vector< vector<edge> > neig_list(n);
    vector< vector<int> > result_matrix(n, vector<int>(n, -1));

    for (int i = 1; i <= m; ++i) {
        int source, destination, cost;
        scanning(source);
        scanning(destination);
        scanning(cost);

        neig_list[source - 1].push_back(make_pair(destination - 1, cost));
    }

    result_matrix = shortest_path_all(neig_list);

    //auto stop = chrono::high_resolution_clock::now();

    //auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    //printing(duration.count());

    if (result_matrix[0][0] == -1) {
        putchar('w'), putchar('r'), putchar('o'), putchar('n'), putchar('g');
        putchar(' ');
        putchar('i'), putchar('n'), putchar('p'), putchar('u'), putchar('t');
    } else {
        for (int i = 0; i < n; ++i, putchar('\n')) {
            for (int j = 0; j < n; ++j) {
                if (result_matrix[i][j] == -1) {
                    putchar('i'), putchar('n'), putchar('f'), putchar(' ');
                } else {
                    printing(result_matrix[i][j]);
                }
            }
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}