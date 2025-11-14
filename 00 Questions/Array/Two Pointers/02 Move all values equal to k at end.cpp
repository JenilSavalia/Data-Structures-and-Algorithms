#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr = {2, 1, 2, 2, 2, 3, 4, 2};
    int k = 2;
    int n = arr.size();

    int i = 0;
    int j = 0;
    for (i; i < n; i++)
    {
        if (arr[i] != k)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
