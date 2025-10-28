#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int> &arr)
{

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }

    for (int x : arr)
    {
        cout << x << " ";
    }
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    InsertionSort(arr);
    return 0;
}