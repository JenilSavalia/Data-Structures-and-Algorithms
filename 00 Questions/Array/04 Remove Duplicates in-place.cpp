#include <iostream>

#include <vector>

using namespace std;

int main()
{
    int arr[] = {1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = 1;

    while (right < n)
    {
        if (arr[right] != arr[left])
        {
            left++;
            arr[left] = arr[right];
        }
        right++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}

// Instead of using a set to store the unique elements, we can implement a two pointer strategy to optimize the space. Since the array is sorted, we know that all the duplicate values will be adjacent to each other.
// Begin at the first position, which will always be part of the final unique list.
// Move through the list one item at a time, comparing the current item with the most recently kept unique item.
// If the current item is the same as the last kept one, skip it because it’s a duplicate.
// If it’s different, place it right after the last kept unique item to keep all unique values grouped at the front.
// Continue until every element in the list has been checked. The first part of the list now contains all the unique values in their original order, and the rest can be ignored.
