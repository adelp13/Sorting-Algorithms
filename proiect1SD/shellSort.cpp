#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

ifstream fin("nr.txt");
int v[100000001], N = 100000000;
void shellSort(int v[100000001], int h, int N)
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
        shellSort(v, h/2, N);
    }
}
int main()
{
    /*fin >> N;
    for (int i = 1; i <= N; i++)
        fin >> v[i];
    shellSort(v, N/2, N);
    for (int i = 1; i <= N; i++)
        cout << v[i] << ' ';
        */
    for (int i = 1; i <= N; i++)
        v[i] = rand()%1000000;
    cout << "da";
    shellSort(v, N/2, N);
    bool da = true;
    for (int i = 1; i < N; i++)
    if (v[i] > v[i + 1])
    {
        da = false;
        break;
    }
    cout << "da";
    cout << da;
    //for (int i = 1; i <= 100000; i++)
        //cout << v[i] << ' ';
    return 0;
}

