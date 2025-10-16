#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force
// Sort the array and return last element (arr.length()-1)

int main()
{

    vector<int> arr = {1, 2, 99, 3};
    sort(arr.begin(), arr.end());
    cout << arr[arr.size() - 1];

    return 0;
}

// using itearion

int main()
{

    int arr[] = {1, 2, 99, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout << max;
}





// using reccursion

int maxElement(int arr[], int i, int size)
{
    if (i == size)
    {
        return arr[i];
    }
    int max = maxElement(arr, i + 1, size);

    //   cout << arr[i] << endl;

    if (arr[i] > max)
    {
        return arr[i];
    }
    else
    {
        return max;
    }
}

int main()
{

    int arr[] = {1, 2, 99, 3};

    cout << maxElement(arr, 0, 4);

    return 0;
}
