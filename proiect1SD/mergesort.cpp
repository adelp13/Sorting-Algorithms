#include <iostream>
using namespace std;

int N, v[500001], w[500001];;

void msort(int v[500001], int left, int right)
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

int main()
{

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> v[i];
    msort(v, 1, N);
    for (int i = 1; i <= N; i++)
        cout << v[i] << ' ';
    return 0;
}
