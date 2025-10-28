#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int minIndex = i; // Track the index of the minimum element
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j; // Update the index of the minimum element
            }
        }
        // Swap the found minimum element with the element at index i
        swap(arr[i], arr[minIndex]);
    }
}

// Time complexity: O(N2)
// Space Complexity: O(1)

int main()
{
    vector<int> arr = {8, 4, 6, 2, 7, 9, 1};
    selectionSort(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
