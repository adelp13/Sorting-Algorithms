#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("nr.txt");
int v[500001], N;
void shellSort(int v[500001], int h, int N)
{
    if (h >= 1)
    {
        for (int i = 1; i <= h; i++)
            for (int j = i + h; j <= N; j++)
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
    fin >> N;
    for (int i = 1; i <= N; i++)
        fin >> v[i];
    shellSort(v, N/2, N);
    for (int i = 1; i <= N; i++)
        cout << v[i] << ' ';
    return 0;
}

