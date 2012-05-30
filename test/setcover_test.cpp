#include <stdlib.h>
#include <iostream>
#include <string>
#define private public
#include "setcover.h"
#undef private

void testClear() {
    unsigned int* a = new unsigned int[4];
    int n = 4;
    int kolich = 4;
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    full_iterator<unsigned int> _full_iterator(a, n, kolich);
    _full_iterator.clear();
    if (
        (a[0] != 0) ||
        (a[1] != 0) ||
        (a[2] != 0) ||
        (a[3] != 0)
        ) {
        std::cout << "%TEST_FAILED% time=0 testname=testClear (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testFull_iterator() {
    unsigned int* a = new unsigned int[4];
    int n = 4;
    int kolich = 4;
    full_iterator<unsigned int> _full_iterator(a, n, kolich);
    for (int i = 0; i < 10000; i++) {
        ++_full_iterator;
    }
    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;
    cout << a[3] << endl;

    if (false) {
        std::cout << "%TEST_FAILED% time=0 testname=testFull_iterator (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testHas_next() {
    unsigned int* a = new unsigned int[4];
    int n = 4;
    int kolich = 4;
    full_iterator<unsigned int> _full_iterator(a, n, kolich);
    bool result = _full_iterator.has_next();
    if (!result) {
        std::cout << "%TEST_FAILED% time=0 testname=testHas_next (newsimpletest1) message=error message sample" << std::endl;
    }

    unsigned int* b = new unsigned int[4];    
    b[0] = 15;
    b[1] = 15;
    b[2] = 15;
    b[3] = 15;
    full_iterator<unsigned int> _full_iterator2(b, n, kolich);
    bool result2 = _full_iterator2.has_next();
    if (result2) {
        std::cout << "%TEST_FAILED% time=0 testname=testHas_next (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testClear2() {
    unsigned int* a = new unsigned int[4];
    int n = 4;
    int kolich = 4;
    a[0] = 15;
    a[1] = 15;
    a[2] = 15;
    a[3] = 15;
    greedy_algo<unsigned int> _greedy_algo(a, n, kolich);
    _greedy_algo.clear();

    if (
        (_greedy_algo.sum[0] != 0) ||
        (_greedy_algo.sum[1] != 0) ||
        (_greedy_algo.sum[2] != 0) ||
        (_greedy_algo.sum[3] != 0)
        ) {
        std::cout << "%TEST_FAILED% time=0 testname=testClear2 (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testGreedy_algo() {
    unsigned int* a_ = new unsigned int[4];
    int n_ = 4;
    int k_ = 4;
    greedy_algo<unsigned int> _greedy_algo(a_, n_, k_);
    if (_greedy_algo.k != k_) {
        std::cout << "%TEST_FAILED% time=0 testname=testGreedy_algo (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testInvoke() {
    unsigned int* a_ = new unsigned int[4];
    int n_ = 4;
    int k_ = 4;
    bitset < 4 > bs0(string("0010"));
    bitset < 4 > bs1(string("0110"));
    bitset < 4 > bs2(string("1010"));
    bitset < 4 > bs3(string("1001"));
    a_[0] = bs0.to_ulong();
    a_[1] = bs1.to_ulong();
    a_[2] = bs2.to_ulong();
    a_[3] = bs3.to_ulong();
    greedy_algo<unsigned int> _greedy_algo(a_, n_, k_);
    unsigned int result = _greedy_algo.invoke();
    bitset < 4 > bs4(string("1010"));
    if (bs4.to_ulong() != result) {
        std::cout << "%TEST_FAILED% time=0 testname=testInvoke (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testRecur() {
    unsigned int s = 0;
    unsigned int* a_ = new unsigned int[4];
    int n_ = 4;
    int k_ = 4;
    bitset < 4 > bs0(string("1000"));
    bitset < 4 > bs1(string("0100"));
    bitset < 4 > bs2(string("0010"));
    bitset < 4 > bs3(string("0001"));
    a_[0] = bs0.to_ulong();
    a_[1] = bs1.to_ulong();
    a_[2] = bs2.to_ulong();
    a_[3] = bs3.to_ulong();
    int r = 0;
    greedy_algo<unsigned int> _greedy_algo(a_, n_, k_);
    _greedy_algo.sort();
    unsigned long result = _greedy_algo.recur(s, r);
    bitset < 4 > bs5(string("1111"));
    if (result != bs5.to_ulong()) {
        cout << "%TEST_FAILED% time=0 testname=testRecur (newsimpletest1) message=";
        cout << result << "!=" << bs5.to_ulong() << endl;
    }
}

void testSort() {
    unsigned long* a_ = new unsigned long[4];
    int n_ = 8;
    int k_ = 6;
    bitset < 8 > bs0(string("10000000"));
    bitset < 8 > bs1(string("11000000"));
    bitset < 8 > bs2(string("11110000"));
    bitset < 8 > bs3(string("10101011"));
    bitset < 8 > bs4(string("11111111"));
    bitset < 8 > bs5(string("01111111"));

    a_[0] = bs0.to_ulong();
    a_[1] = bs1.to_ulong();
    a_[2] = bs2.to_ulong();
    a_[3] = bs3.to_ulong();
    a_[4] = bs4.to_ulong();
    a_[5] = bs5.to_ulong();
    greedy_algo<unsigned long> _greedy_algo(a_, n_, k_);
    _greedy_algo.clear();
    _greedy_algo.sort();
    bool b = _greedy_algo.b;
    short *s = _greedy_algo.srt[b];
     if (
        (s[0] != 4) ||
        (s[1] != 5) ||
        (s[2] != 3) ||
        (s[3] != 2) ||
        (s[4] != 1) ||
        (s[5] != 0) 
        ) {
        cout << "%TEST_FAILED% time=0 testname=testSort (newsimpletest1) message=";
        cout << " s[0]" << s[0] << "!=" << (s[0] != 4);
        cout << " s[1]" << s[1] << "!=" << (s[1] != 5);
        cout << " s[2]" << s[2] << "!=" << (s[2] != 3);
        cout << " s[3]" << s[3] << "!=" <<  (s[3] != 2);
        cout << " s[4]" << s[4] << "!=" <<  (s[4] != 1);
        cout << " s[5]" << s[5] << "!=" <<  (s[5] != 0);
        cout << endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest1" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testClear (newsimpletest1)" << std::endl;
    testClear();
    std::cout << "%TEST_FINISHED% time=0 testClear (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testFull_iterator (newsimpletest1)" << std::endl;
    testFull_iterator();
    std::cout << "%TEST_FINISHED% time=0 testFull_iterator (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testHas_next (newsimpletest1)" << std::endl;
    testHas_next();
    std::cout << "%TEST_FINISHED% time=0 testHas_next (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testClear2 (newsimpletest1)" << std::endl;
    testClear2();
    std::cout << "%TEST_FINISHED% time=0 testClear2 (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testGreedy_algo (newsimpletest1)" << std::endl;
    testGreedy_algo();
    std::cout << "%TEST_FINISHED% time=0 testGreedy_algo (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testInvoke (newsimpletest1)" << std::endl;
    testInvoke();
    std::cout << "%TEST_FINISHED% time=0 testInvoke (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testRecur (newsimpletest1)" << std::endl;
    testRecur();
    std::cout << "%TEST_FINISHED% time=0 testRecur (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testSort (newsimpletest1)" << std::endl;
    testSort();
    std::cout << "%TEST_FINISHED% time=0 testSort (newsimpletest1)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

