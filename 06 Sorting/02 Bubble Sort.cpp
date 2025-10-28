#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    BubbleSort(arr);
    return 0;
}
