// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

// Program to move all negative numbers to the end of the array
// using the two-pointer approach
int main()
{
    // Initialize a vector with both negative and positive integers
    vector<int> v = {-1, 2, -3, -6, 5, 4, 7};

    int i = 0; // Pointer to iterate through the vector
    int j = 0; // Pointer to track the position for the next positive number

    // Traverse the entire vector
    for (i; i < v.size(); i++)
    {
        // Check if the current element is non-negative (i.e., >= 0)
        if (!(v[i] < 0))
        {
            // Swap the current non-negative element with the element at index j
            // This moves non-negative numbers to the front
            swap(v[i], v[j]);
            j++; // Increment j to the next position for the next positive number
        }
    }

    // Print the rearranged vector
    // After this loop, all non-negative numbers will be at the beginning
    // and all negative numbers will be at the end
    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
