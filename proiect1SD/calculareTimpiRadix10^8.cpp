#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>
using namespace std;

ifstream in("tests.txt");
const int NMAX = 100000000;
short int v1[1 + NMAX], v2[1 + NMAX];
const int EXP_MAX = 16;
int N = 100000000;
short int maxValue = 10000;
int exponent = 7;

vector <short int> buckets[1 << EXP_MAX];

void radixSort(short int v[1 + NMAX], long long power){
    if (maxValue > 32767 || N > 100000000){
        cout << "Algoritmul nu poate efectua sortarea ";
        return;
    }
    int stop = 0;
    for (int i = 1; i <= N; i++)
    {
        if ((v[i] >> power) == 0)
            stop++;
        buckets[(v[i] >> power) & ((1 << exponent) - 1)].push_back(v[i]);
        //buckets[(v[i] / power) % BASE].shrink_to_fit();
    }
    int poz = 0;

    for (int i = 0; i < (1 << exponent); i++){
        for (int j = 0; j < buckets[i].size(); j++){
            v[++poz] = buckets[i][j];
        }
        buckets[i].clear();
        buckets[i].shrink_to_fit();
    }

    if (stop == N)
        return;
    radixSort(v, power + exponent);
}

bool sortedCheck(short int v[1 + NMAX])
{
    for (int i = 1; i < N; i++)
    {
        if (v[i] > v[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
void copiere(short int v[1 + NMAX])
{
    for (int i = 1; i <= N; i++)
        v[i] = v1[i];
}

int main()
{
    for (int j = 1; j <= N; j++){
            v1[j] = rand() % (maxValue + 1);
    }

    exponent = 7;
    copiere(v2);
    clock_t time;
    time = clock();
    radixSort(v2, 0);
    time = clock() - time;
    cout << "\tRADIX 2^7: ";
    if (float(time)/CLOCKS_PER_SEC == 0)
        cout << "sub 0.001 sec ";
    else
        cout << float(time)/CLOCKS_PER_SEC << " sec ";
    if (sortedCheck(v2))
        cout << " Sortare reusita\n";
    else
        cout << " Vectorul nu a putut fi sortat\n";

    exponent = 10;
    copiere(v2);
    time = clock();
    radixSort(v2, 0);
    time = clock() - time;
    cout << "\tRADIX 2^10:";
    if (float(time)/CLOCKS_PER_SEC == 0)
        cout << "sub 0.001 sec ";
    else
        cout << float(time)/CLOCKS_PER_SEC << " sec ";
    if (sortedCheck(v2))
        cout << " Sortare reusita\n";
    else
        cout << " Vectorul nu a putut fi sortat\n";

    exponent = 13;
    copiere(v2);
    time = clock();
    radixSort(v2, 0);
    time = clock() - time;
    cout << "\tRADIX 2^13: ";
    if (float(time)/CLOCKS_PER_SEC == 0)
        cout << "sub 0.001 sec ";
    else
        cout << float(time)/CLOCKS_PER_SEC << " sec ";
    if (sortedCheck(v2))
        cout << " Sortare reusita\n";
    else
        cout << " Vectorul nu a putut fi sortat\n";

    exponent = 16;
    copiere(v2);
    time = clock();
    radixSort(v2, 0);
    time = clock() - time;
    cout << "\tRADIX 2^16: ";
    if (float(time)/CLOCKS_PER_SEC == 0)
        cout << "sub 0.001 sec ";
    else
        cout << float(time)/CLOCKS_PER_SEC << " sec ";
    if (sortedCheck(v2))
        cout << " Sortare reusita\n";
    else
        cout << " Vectorul nu a putut fi sortat\n";
    return 0;
}
