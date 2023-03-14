#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

ifstream in("tests.txt");
const int NMAX = 100000000;
short int v[1 + NMAX];
int N = 100000000;
short int maxValue;
const int exponent = 7;

vector <short int> buckets[1 << exponent];

void radixSort(short int v[1 + NMAX], long long power){
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

int main()
{
    ///T31
    maxValue = 1000;
    for (int i = 1; i <= N; i++)
        v[i] = rand() % (maxValue + 1);
    clock_t time;
    time = clock();
    radixSort(v, 0);
    time = clock() - time;
    cout << "T31 N = " << N << " MAX = " << maxValue << " Timp: "
    << float(time)/CLOCKS_PER_SEC << " sec ";


    if (sortedCheck(v))
        cout << " Sortare reusita\n";
    else
        cout << " Vectorul nu a putut fi sortat\n\n";

    ///T32
    maxValue = 10000;
    for (int i = 1; i <= N; i++)
        v[i] = rand() % (maxValue + 1);
    time = clock();
    radixSort(v, 0);
    time = clock() - time;
    cout << "T32 N = " << N << " MAX = " << maxValue << " Timp: "
    << float(time)/CLOCKS_PER_SEC << " sec ";


    if (sortedCheck(v))
        cout << " Sortare reusita\n";
    else
        cout << " Vectorul nu a putut fi sortat\n\n";
    return 0;
}
