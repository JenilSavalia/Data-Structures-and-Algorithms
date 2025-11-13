#include <iostream>
#include <vector>
using namespace std;

// segregate 0s and 1s in an array

int main()
{

    vector<int> arr = {1, 0, 0, 1, 1, 0, 1};

    int j = 0; // this pointer holds the last index of 1 (that we will shift)
    int i = 0;
    for (i = 0; i < arr.size(); i++)
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

// segregate even and odd numbers

int main()
{
    vector<int> arr = {5, 4, 9, 7, 6, 2, 5};
    int j = 0; // j keeps track of the position where the next even number should go.
    int i = 0; // i scans every element.
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
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