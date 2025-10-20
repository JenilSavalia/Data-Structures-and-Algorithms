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

//using hash map approach  O(n)

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
