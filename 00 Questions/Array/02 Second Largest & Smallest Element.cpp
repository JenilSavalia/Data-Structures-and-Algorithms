
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Approach 1 : finding Max and Min element in first loop and findong second_largest and second_smallest in second loop

int main()
{

    int arr[] = {1, 2, 4, 7, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    int second_large = INT_MIN;
    int second_small = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] < second_small && arr[i] != min)
        {
            second_small = arr[i];
        }
        if (arr[i] > second_large && arr[i] != max)
        {
            second_large = arr[i];
        }
    }
}

// Approach 2 : (Optimal) -> in single traversal we will find second_smallest or second_largest

int second_largest(int arr[], int n)
{
    int max = INT_MIN;
    int second_large = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            second_large = max;
            max = arr[i];
        }
        else if (arr[i] > second_large && arr[i] != max)
        {
            second_large = arr[i];
        }
    }
    cout << second_large;
    return second_large;
}

int main()
{

    int arr[] = {1, 2, 4, 7, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    second_largest(arr, n);
}