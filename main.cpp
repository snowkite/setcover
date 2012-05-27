#include <cstdlib>
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

/**
 * Решения задачи нахождения среди множества к бинарных слов длины n 
 * минимального подмножества образуещего единичного покрытия без наложения.
 * покрытия 
 * Битовые последовательности(двоичные слова) представлены в виде чисел. 
 * 000 - 0
 * 001 - 1
 * 010 - 2
 * 011 - 3
 * и т. д.
 * Тип данных задаётся через template 
 * Есть возможность задать свой тип, и хранить массивами...
 **/

/**
 * full_iterator - класс для циклов.
 * Производит полный перебор всех возможных вариантов
 * для заданного количества битовых наборов и их длины.
 * 
 * Также может использоваться для переборов диапазонов вариантов.
 **/
template <class T>
class full_iterator {
private:

    /**
     * Основной массив, в котором хранятся последовательности
     **/
    T* array;

    /**
     * Кл-во слов
     **/
    int k;


    /**
     * Максимально возможное число.
     * 1  - 1
     * 3  - 11
     * 7  - 111
     * 15 - 1111
     * и т. д.
     **/
    T m;

    /**
     * @param n - количество бит
     * @return T число для n 
     * старшие биты которого состоят из единиц.
     **/
    T get_max_bnumber(int n) {
        T i = pow((double) 2, n);
        i--;
        return i;
    }

public:

    /**
     * @param a - основной массив
     * @param n - длина слова
     * @param k - количество слов
     **/
    full_iterator(T *a, int n, int kolich) : array(a), k(kolich) {
        m = get_max_bnumber(n);
    }

    /**
     * Обнуление основного массива.
     **/
    void clear() {
        for (int i = 0; i < k; i++)
            array[i] = 0;
    }

    /**
     * @return - имеет ли итератор следующий шаг
     * false если все значения массива единицы длины n
     **/
    bool has_next() {
        bool b = true;
        for (int i = 0; i < k; i++)
            b = b & (array[i] == m);
        return !b;
    }

    /**
     *  Шаг итерации массива array
     *  После достижения максимального значения обнуляется
     **/
    void operator++() {
        for (int i = 0; (i < k) && (++array[i] == m + 1); array[i++] = 0);
    }
};

/**
 * Жадный алгоитм
 * Класс поиска минимального множества образующего покрытие
 *  в заданых множествах
 **/
template <class T>
class greedy_algo {
private:
    T *a;

    /**
     * Массив хранит количество единиц в каждом слове
     **/
    short * sum;

    /**
     * Массивы хранят номера слов в порядке убывания количества бит
     **/
    short * srt[2];
    bitset < 32 > bs;

    /**
     * Длина слова
     **/
    int n;

    /**
     * к-во слов
     **/
    int k;

    /**
     * флаг текущего варианта srt
     **/
    bool b;

    /**
     * Максимально возможное число.
     * 1  - 1
     * 3  - 11
     * 7  - 111
     * 15 - 1111
     * и т. д.
     **/
    T m;

public:

    /**
     * @param a - основной массив
     * @param n - длина слова
     * @param k - количество слов
     **/
    greedy_algo(T *a_, int n_, int k_) : a(a_), n(n_), k(k_) {
        sum = new short[k];
        srt[0] = new short[k];
        srt[1] = new short[k];
        m = (T) pow((double) 2, n);
        m--;
    }

    /**
     * Обнуление полей класса 
     * нужно выполнять перед обработкой следуещего числа
     **/
    void clear() {
        b = false;
        for (int i = 0; i < k; i++) {
            sum[i] = 0;
            srt[0][i] = 0;
            srt[1][i] = 0;
        }
    }

    /**
     * Сорировка слов по количеству единиц
     * индексирут основной массив a 
     * по результату работы 
     * заполняет массивы sum, srt[0], srt[1] и флаг b
     * 
     * текущее значении b укаывает на массив srt хранящий номера 
     * массива T *а в нисходящем порядке
     **/
    void sort() {
        for (int i = 0; i < k; i++) {
            b = !b;
            bs = a[i];
            sum[i] = bs.count();
            int j = 0;
            while ((sum[i] < sum[srt[!b][j]]) && (j < k)) {
                srt[b][j] = srt[!b][j];
                j++;
            }
            srt[b][j] = i;
            while (++j < k)
                srt[b][j] = srt[!b][j - 1];
        }
    }

    /**
     * Рекурсивная функция поиска минимального множества
     * @param s - маска числа.
     * к премеру, запуск функции начинается
     * с 0000 далее при обходе 0110, 0111 и т д.
     * 
     * @param r - номер слова
     * поиска идет слева направа от 0 до n
     * 
     * @return  
     * 0 - если не содержит полного покрытия
     * > 0 - если содержит 
     * unsigned int - маска которого соответствует найденому
     * минимальному покрытию
     * к примеру, 000101
     * значит в массиве a слова a[0] a[2] образуют 
     * минимальное покрытие
     * для результата 011100 - соответственно a[2] a[3] a[4]
     **/
    unsigned int recur(T s, int r) {
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

    /**
     * основная функция класса для внешнего вызова
     * @return результат поиска 
     * в формате результатов recur() 
     **/
    unsigned int invoke() {
        clear();
        sort();
        return recur(0, 0);
    }
};

/**
 * 2 аргумента 
 * 1 - длина слова
 * 2 - количество слов
 **/
int main(int argc, char** argv) {
    int n = 3;
    int k = 4;

    //    if (argc == 3) {
    //        n = atoi(argv[1]);
    //        k = atoi(argv[2]);
    //    }

    unsigned int * a = new unsigned int[k];
    full_iterator<unsigned int> fi(a, n, k);
    greedy_algo<unsigned int> ga(a, n, k);
    bitset < 10 > bs;
    bitset < 10 > bs2;

    while (fi.has_next()) {
        ++fi;
        bs = ga.invoke();
        for (int i = 0; i < k; i++) {
            bs2 = a[i];
            if (bs[i])
                cout << " *" << bs2.to_string().substr(10 - n, 10) << "* ";
            else
                cout << " [" << bs2.to_string().substr(10 - n, 10) << "] ";
        }
        cout << endl;
    }

    return 0;
}

