#include <iostream>
#include <vector>
using namespace std;

// sagerate 0s and 1s in an array

int main()
{

    vector<int> arr = {1, 0, 0, 1, 1, 0, 1};

    int j = 0;
    int i = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
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