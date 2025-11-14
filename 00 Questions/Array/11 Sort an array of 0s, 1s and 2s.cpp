#include <iostream>
using namespace std;

// Brute Force Approach O(n^2)

int main()
{

    int arr[] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}

// using hash map approach  O(n)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }

        for (int i = 0; i < mpp[0]; i++)
        {
            nums[i] = 0;
        }

        for (int i = mpp[0]; i < mpp[0] + mpp[1]; i++)
        {
            nums[i] = 1;
        }

        for (int i = mpp[0] + mpp[1]; i < n; i++)
        {
            nums[i] = 2;
        }
    }
};

// using optimal approach  (Dutch National flag algorithm)

// The idea is to sort the array of size n using three pointers:
// lo = 0, mid = 0 and hi = n - 1 such that the array is divided into 4 parts -

// [0...low-1] -> all 0s
// [low....mid-1] -> all 1s
// [mid...high] -> unprocessed elements
// [high+1...n-1] -> all 2s

// Here,
// low is index where next 0 sould be places
// mid is the current element being checked,
// high is the index where the next 2 should be placed.

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr = {0, 2, 2, 2, 0, 1, 1, 0, 0, 1};
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
