#include <iostream>
using namespace std;

int v[500001], N, fr[500001];
void countSort(int v[500001], int fr[500001], int N){
    int maxVal = 0;
    for(int i = 1; i <= N; i++)
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
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> v[i];
    countSort(v, fr, N);
    for (int i = 1; i <= N; i++)
        cout << v[i] << ' ';
    return 0;
}
