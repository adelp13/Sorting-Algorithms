#include <iostream>
#include <cstdlib>
using namespace std;

int v[100000001], N;

void quickSortRandom(int v[100000001], int left, int right){
    if (left < right)
    {
        int index = left + (rand() % (right - left +1));
        int val = v[index];
        int above = 0;
        int indexVal;

        for (int i = left; i <= right - above; i++)
        {
            if (v[i] >= val)
            {
                if(v[i] == val)
                    indexVal = right - above;
                swap(v[i], v[right - above]);
                above++;
                i--;
            }
        }
        swap(v[right - above + 1], v[indexVal]);
        quickSortRandom(v, left, right - above);
        quickSortRandom(v, right - above + 2, right);
    }
    return;
}

void quickSortMedian3(int v[100000001], int left, int right){
    if (left < right)
    {
        int mid = (left + right) / 2;
        if (v[left] > v[mid])
            swap(v[left], v[mid]);
        if (v[mid] > v[right])
            swap(v[right], v[mid]);
        if (v[left] > v[right])
            swap(v[right], v[left]);
        int val = v[mid];
        int above = 0, indexVal;

        for (int i = left; i <= right - above; i++)
        {
            if (v[i] >= val)
            {
                if(v[i] == val)
                    indexVal = right - above;
                swap(v[i], v[right - above]);
                above++;
                i--;
            }
        }
        swap(v[right - above + 1], v[indexVal]);
        quickSortMedian3(v, left, right - above);
        quickSortMedian3(v, right - above + 2, right);
    }
    return;
}
int main()
{
    /*cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> v[i];
        */
    for (int i = 1; i <= 100000000; i++)
        v[i] = rand()%1000000;
    cout << "da";
    quickSortMedian3(v, 1, 100000000);
    bool da = true;
    for (int i = 1; i < 100000000; i++)
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
