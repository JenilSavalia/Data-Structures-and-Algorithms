#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// aggressive cows

// range can be from 1 to (maxVal - minVal)

// as cows (k) >= 2

// if two cows are given , range would be from [1,maxVal-minVal]
// i.e two cows are adjacena and at first and last index

// brute force approach

bool canWePlaceCows(vector<int> &arr, int minMaxDistance, int cows)
{
    int remainCows = cows - 1;
    int lastStallUsed = arr[0];
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[j] - lastStallUsed >= minMaxDistance)
        {
            remainCows--;
            lastStallUsed = arr[j];
        }
    }
    return remainCows <= 0 ? true : false;
}

int main()
{
    vector<int> arr = {4, 2, 1, 3, 6};
    int k = 2;

    sort(arr.begin(), arr.end());

    int maxDist = arr.back() - arr.front();

    for (int i = 1; i <= maxDist; i++)
    {
        if (canWePlaceCows(arr, i, k) == true)
        {
            continue;
        }
        else
        {
            cout << i - 1;
            return i - 1;
        }
    }

    cout << maxDist;
    return 0;
}

// optimal approach would be binary search

// as we have a range from [1,maxVal-minVal]

bool canWePlaceCows(vector<int> &arr, int minMaxDistance, int cows)
{
    int remainCows = cows - 1;
    int lastStallUsed = arr[0];
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[j] - lastStallUsed >= minMaxDistance)
        {
            remainCows--;
            lastStallUsed = arr[j];
        }
    }
    return remainCows <= 0 ? true : false;
}

int main()
{

    vector<int> arr = {4, 2, 1, 3, 6};
    int k = 2;

    sort(arr.begin(), arr.end());

    int maxDist = arr.back() - arr.front();

    int left = 1;
    int right = maxDist;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (canWePlaceCows(arr, mid, k))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return right;
}