#include <iostream>
using namespace std;

int v[500001], N;

void quickSort(int v[500001], int left, int right){
    if (left < right)
    {
        int mid = (left + right)/2;
        int val = v[mid];
        int above = 0;
        cout << 'x';
        for (int i = left; i <= right - above; i++)
        {
            if (v[i] > val)
            {
                above++;
                swap(v[i], v[right - above]);
                i--;
            }
        }
        quickSort(v, left, right - above - 1);
        quickSort(v, right - above , right);
    }
    return;
}
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> v[i];
    quickSort(v, 1, N);
    for (int i = 1; i <= N; i++)
        cout << v[i] << ' ';
    return 0;
}
