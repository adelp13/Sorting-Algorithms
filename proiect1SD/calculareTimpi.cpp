#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

ifstream in("teste2.txt");
//ifstream in("teste.txt");
const int NMAX = 100000000;
const int VAL_MAX = 100000000;
const int EXP_MAX = 16;
int w[1 + NMAX], fr[VAL_MAX + 1];
int v1[1 + NMAX], v2[1 + NMAX];
int N, t, maxValue;

int exponent;
vector <int> buckets[1 << EXP_MAX];
bool sorted;

void copiere(int v[1 + NMAX]);
bool sortedCheck(int v[1 + NMAX]);
void shellSort(int v[1 + NMAX], int h);
void msort(int v[1 + NMAX], int left, int right);
void countSort(int v[1 + NMAX]);
void radixSort(int v[1 + NMAX], long long power);
void quickSortMedian3(int v[1 + NMAX], int left, int right);
void stlSort(int v[1 + NMAX]);

int main()
{
    in >> t;
    for (int i = 0; i < t; i++)
    {

        in >> N >> maxValue;
        //generate random vector
        for (int j = 1; j <= N; j++)
        {
            v1[j] = rand() % (maxValue + 1);
            v2[j] = v1[j];
        }
        cout << "T" << i + 1 << " N = " << N << " MAX = " << maxValue << ":\n";

        clock_t time;

        time = clock();
        stlSort(v2);
        time = clock() - time;
        cout << "\tSTL: ";
        if (float(time)/CLOCKS_PER_SEC == 0)
            cout << "sub 0.001 sec\n";
        else
            cout << float(time)/CLOCKS_PER_SEC << " sec\n";

        copiere(v2);
        time = clock();
        shellSort(v2, N/2);
        time = clock() - time;
        cout << "\tSHELL: ";
        if (sortedCheck(v2))
        {
            if (float(time)/CLOCKS_PER_SEC == 0)
                cout << "sub 0.001 sec ";
            else
                cout << float(time)/CLOCKS_PER_SEC << " sec ";
            cout << " Sortare reusita\n";
        }
        else
            cout << " Vectorul nu a putut fi sortat\n";

        copiere(v2);
        time = clock();
        countSort(v2);
        time = clock() - time;
        cout << "\tCOUNT: ";
        if (sortedCheck(v2))
        {
            if (float(time)/CLOCKS_PER_SEC == 0)
                cout << "sub 0.001 sec ";
            else
                cout << float(time)/CLOCKS_PER_SEC << " sec ";
            cout << " Sortare reusita\n";
        }
        else
            cout << " Vectorul nu a putut fi sortat\n";

        copiere(v2);
        time = clock();
        msort(v2, 1, N);
        time = clock() - time;
        cout << "\tMERGE: ";
        if (sortedCheck(v2))
        {
            if (float(time)/CLOCKS_PER_SEC == 0)
                cout << "sub 0.001 sec ";
            else
                cout << float(time)/CLOCKS_PER_SEC << " sec ";
            cout << " Sortare reusita\n";
        }
        else
            cout << " Vectorul nu a putut fi sortat\n";

        ///Radix:

            exponent = 7;
            copiere(v2);
            time = clock();
            radixSort(v2, 0);
            time = clock() - time;
            cout << "\tRADIX 2^7: ";
            if (sortedCheck(v2))
            {
                if (float(time)/CLOCKS_PER_SEC == 0)
                    cout << "sub 0.001 sec ";
                else
                    cout << float(time)/CLOCKS_PER_SEC << " sec ";
                cout << " Sortare reusita\n";
            }
            else
                cout << " Vectorul nu a putut fi sortat\n";

            exponent = 10;
            copiere(v2);
            time = clock();
            radixSort(v2, 0);
            time = clock() - time;
            cout << "\tRADIX 2^10:";
            if (sortedCheck(v2))
            {
                if (float(time)/CLOCKS_PER_SEC == 0)
                    cout << "sub 0.001 sec ";
                else
                    cout << float(time)/CLOCKS_PER_SEC << " sec ";
                cout << " Sortare reusita\n";
            }
            else
                cout << " Vectorul nu a putut fi sortat\n";

            exponent = 13;
            copiere(v2);
            time = clock();
            radixSort(v2, 0);
            time = clock() - time;
            cout << "\tRADIX 2^13: ";
           if (sortedCheck(v2))
            {
                if (float(time)/CLOCKS_PER_SEC == 0)
                    cout << "sub 0.001 sec ";
                else
                    cout << float(time)/CLOCKS_PER_SEC << " sec ";
                cout << " Sortare reusita\n";
            }
            else
                cout << " Vectorul nu a putut fi sortat\n";

            exponent = 16;
            copiere(v2);
            time = clock();
            radixSort(v2, 0);
            time = clock() - time;
            cout << "\tRADIX 2^16: ";
            if (sortedCheck(v2))
            {
                if (float(time)/CLOCKS_PER_SEC == 0)
                    cout << "sub 0.001 sec ";
                else
                    cout << float(time)/CLOCKS_PER_SEC << " sec ";
                cout << " Sortare reusita\n";
            }
            else
                cout << " Vectorul nu a putut fi sortat\n";

        copiere(v2);
        time = clock();
        quickSortMedian3(v2, 1, N);
        time = clock() - time;
        cout << "\tQUICK: ";
       if (sortedCheck(v2))
        {
            if (float(time)/CLOCKS_PER_SEC == 0)
                cout << "sub 0.001 sec ";
            else
                cout << float(time)/CLOCKS_PER_SEC << " sec ";
            cout << " Sortare reusita\n";
        }
        else
            cout << " Vectorul nu a putut fi sortat\n";
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
    if (maxValue > 1000000000)
    {
        cout << "Algoritmul nu poate efectua sortarea ";
        return;
    }
    int maxVal = 0;
    for(int i = 0; i < N; i++)
    {
        fr[v[i]]++;
        if(v[i] >= maxValue)
            maxValue = v[i];
    }

    int cnt = 0;
    for(int i = 0; i <= maxValue; i++)
        for(int j = 1; j <= fr[i]; j++)
            v[++cnt] = i;
}

void radixSort(int v[1 + NMAX], long long power){
    if (N > 10000000){
        cout << "Algoritmul nu poate efectua sortarea ";
        return;
    }
    else{
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
    if (N == 100000000 && maxValue < 10000){
        cout << "Algoritmul nu poate efectua sortarea ";
        return;
    }
    else if (left < right)
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
        if (v[i] > v[i + 1])
            return 0;
    return 1;
}

void copiere(int v[1 + NMAX])
{
    for (int i = 1; i <= N; i++)
        v[i] = v1[i];
}
