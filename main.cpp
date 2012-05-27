#include <cstdlib>
#include <iostream>
#include <bitset>
#include <cmath>
#include "setcover.h"

using namespace std;

/**
 * 2 аргумента 
 * 1 - длина слова
 * 2 - количество слов
 **/

int main(int argc, char** argv) {
    int n = 6;
    int k = 2;

        if (argc == 3) {
            n = atoi(argv[1]);
            k = atoi(argv[2]);
        }
    
    unsigned int * a = new unsigned int[k];
    full_iterator<unsigned int> fi(a, n, k);
    greedy_algo<unsigned int> ga(a, n, k);
    bitset < 64 > bs;
    bitset < 64 > bs2;

    while (fi.has_next()) {
        ++fi;
        bs = ga.invoke();
        for (int i = 0; i < k; i++) {
            bs2 = a[i];
            if (bs[i]) {
                cout << " *" << bs2.to_string().substr(64 - n, 64) << "* ";
            } else {
                cout << " [" << bs2.to_string().substr(64 - n, 64) << "] ";
            }
        }
        cout << endl;
    }

    return 0;                
}

