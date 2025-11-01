// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// Brute Force Approach O(n^2)
int main()
{

    int arr[] = {2, 6, 5, 8, 11};
    int target = 14;
    int n = 5;
    bool isTwoSum = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                isTwoSum = true;
                break;
            }
        }
    }

    cout << isTwoSum;
    return isTwoSum;
    return 0;
}

// hash map implementation

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        map<int, int> mpp;
        vector<int> TwoSum;

        for (int i = 0; i < n; i++)
        {
            int diff = target - nums[i];
            if (mpp.find(diff) != mpp.end())
            {
                TwoSum.push_back(i);
                TwoSum.push_back(mpp[diff]);
            }
            mpp[nums[i]] = i;
        }
        return TwoSum;
    }
};



// using two pointers (array should be sorted)

#include <iostream>
using namespace std;

int main()
{

    int arr[] = {2, 6, 5, 8, 11};
    int target = 15;
    int n = 5;
    bool isTwoSum = false;

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {

        if (arr[left] + arr[right] == target)
        {
            isTwoSum = true;
            break;
        }
        else if (arr[left] + arr[right] > target)
        {
            right--;
        }
        else if (arr[left] + arr[right] < target)
        {
            left++;
        }
    }

    cout << isTwoSum;
    return isTwoSum;
    return 0;
}
