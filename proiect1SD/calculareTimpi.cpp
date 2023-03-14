#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

ifstream in("tests.txt");
const int NMAX = 100000000;
const int VAL_MAX = 100000000;
int v[1 + NMAX], w[1 + NMAX], fr[VAL_MAX + 1];
int N, t, maxValue;
const int exponent = 7;
vector <int> buckets[1 << exponent];

void shellSort(int v[1 + NMAX], int h);

void msort(int v[1 + NMAX], int left, int right);

void countSort(int v[1 + NMAX]);

void radixSort(int v[1 + NMAX], long long power);

void quickSortMedian3(int v[1 + NMAX], int left, int right);

void stlSort(int v[1 + NMAX]);
bool sortedCheck(int v[1 + NMAX]);

int main()
{
    in >> t;
    for (int i = 0; i < t; i++)
    //for (int i = 0; i < t - 2; i++) // for radix and quick
    {
        in >> N >> maxValue;
        //generate random vector
        for (int j = 1; j <= N; j++)
            v[j] = rand() % (maxValue + 1);
        clock_t time;
        time = clock();

        quickSortMedian3(v, 1, N);
        //shellSort(v, N/2);
        //stlSort(v);
        //countSort(v);
        //msort(v, 1, N);
        //radixSort(v, 0);
        time = clock() - time;

        cout << "T" << i + 1 << " N = " << N << " MAX = " << maxValue << " Timp: ";
        if (float(time)/CLOCKS_PER_SEC == 0)
            cout << "sub 0.001 sec ";
        else
            cout << float(time)/CLOCKS_PER_SEC << " sec ";
        if (sortedCheck(v))
            cout << " Sortare reusita\n";
        else
            cout << " Vectorul nu a putut fi sortat\n\n";
    }
    return 0;
}

void msort(int v[1 + NMAX], int left, int right)
{

    if (left < right)
    {
        int mid = (left + right) / 2;
        msort(v, left, mid);
        msort(v, mid + 1, right);

        int i = left, j = mid + 1, nr = 1;
        while (i <= mid && j <= right)
        {
            if (v[i] > v[j]) w[nr++] = v[j++];
            else w[nr++] = v[i++];
        }
        while (i <= mid)
            w[nr++] = v[i++];
        while (j <= right)
            w[nr++] = v[j++];

        for (int i = right; i >= left; i--)
            v[i] = w[--nr];
    }
    return;
}

void countSort(int v[1 + NMAX]){
    int maxVal = 0;
    for(int i = 0; i < N; i++)
    {
        fr[v[i]]++;
        if(v[i] >= maxVal)
            maxVal = v[i];
    }

    int cnt = 0;
    for(int i = 0; i <= maxVal; i++)
        for(int j = 1; j <= fr[i]; j++)
            v[++cnt] = i;
}

void radixSort(int v[1 + NMAX], long long power){
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


void shellSort(int v[1 + NMAX], int h)
{
    if (h >= 1)
    {
        for (int i = 1; i <= h; i++)
            for (int j = i + h; j <= N; j += h)
            {
                int k = j - h;
                while(k >= i && v[k] > v[k + h])
                {
                    swap(v[k], v[k + h]);
                    k -= h;
                }
            }
        shellSort(v, h/2);
    }
}



void quickSortMedian3(int v[1 + NMAX], int left, int right){
    if (left < right)
    {
        int mid = (left + right) / 2;
        if (v[left] > v[right])
            swap(v[right], v[left]);
        if (v[mid] > v[right])
            swap(v[right], v[mid]);
        if (v[left] > v[mid])
            swap(v[left], v[mid]);

        swap(v[mid], v[right]);
        int poz = left;

        for (int i = left; i < right; i++)
            if (v[i] < v[right])
                swap(v[poz++], v[i]);
        swap(v[right], v[poz]);

		quickSortMedian3(v, left , poz - 1);
		quickSortMedian3(v, poz + 1 , right);
    }
    return;
}
void stlSort(int v[1 + NMAX])
{
    sort(v + 1, v + N + 1);
}
bool sortedCheck(int v[1 + NMAX])
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
