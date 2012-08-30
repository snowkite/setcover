#ifndef NEWFILE_TPP
#define	NEWFILE_TPP

#include "setcover.h"
#include <bitset>
#include <cmath>

using namespace std;

template <class T>
T full_iterator<T>::get_max_bnumber(int n) {
    T i = pow((double) 2, n);
    i--;
    return i;
}

template <class T>
full_iterator<T>::full_iterator(T *a, int n, int kolich) : array(a), k(kolich) {
    m = get_max_bnumber(n);
}

template <class T>
void full_iterator<T>::clear() {
    for (int i = 0; i < k; i++)
        array[i] = 0;
}

template <class T>
bool full_iterator<T>::has_next() {
    bool b = true;
    for (int i = 0; i < k; i++)
        b = b & (array[i] == m);
    return !b;
}

template <class T>
void full_iterator<T>::operator++() {
    for (int i = 0; (i < k) && (++array[i] == m + 1); array[i++] = 0);
}

template <class T>
greedy_algo<T>::greedy_algo(T *a_, int n_, int k_) : a(a_), n(n_), k(k_) {
    sum = new short[k];
    srt[0] = new short[k];
    srt[1] = new short[k];
    m = (T) pow((double) 2, n);
    m--;
}

template <class T>
void greedy_algo<T>::clear() {
    b = false;
    for (int i = 0; i < k; i++) {
        sum[i] = 0;
        srt[0][i] = 0;
        srt[1][i] = 0;
    }
}

template <class T>
greedy_algo<T>::~greedy_algo() {
    delete [] sum;
    delete [] srt[0];
    delete [] srt[1];
}

template <class T>
void greedy_algo<T>::sort() {
    bitset<64> bs;
    for (int i = 0; i < k; i++) {
        b = !b;
        bs = a[i];
        sum[i] = bs.count();
        int j = 0;
        while ((sum[i] <= sum[srt[!b][j]]) && (j < i)) {
            srt[b][j] = srt[!b][j];
            j++;
        }
        srt[b][j] = i;
        while (++j <= i)
            srt[b][j] = srt[!b][j - 1];
    }
}

template <class T>
unsigned long greedy_algo<T>::recur(T s, int r) {
    T x = a[srt[b][r]] ^ s;
    if (x == m)
        return (unsigned int) pow((double) 2, srt[b][r]);

    for (int i = r + 1; i < k; i++) {
        T y = a[srt[b][i]];
        if ((x & y) == 0) {
            int v = recur(x, i);
            if (v)
                return (v ^ (unsigned int) pow((double) 2, srt[b][r]));
        }
    }
    if ((s == 0) && (r < k))
        return recur(0, r + 1);
    return 0;
}

template <class T>
unsigned long greedy_algo<T>::invoke() {
    clear();
    sort();
    return recur(0, 0);
}

#endif	/* NEWFILE_TPP */

