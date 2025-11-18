// Input: arr[ ] = {3, 8, 9, 15}, K = 2
// Output: 6.5

// All subarrays of length 2 are {3, 8}, {8, 9}, {9, 15} and their averages are (3+8)/2 = 5.5, (8+9)/2 = 8.5, and (9+15)/2 = 12.0 respectively.

// Therefore, the difference between the maximum(=12.0) and minimum(=5.5) is 12.0 -5.5 = 6.5.

#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{

    vector<int> arr = {3, 8, 9, 15};
    int k = 2;
    int start = 0;
    int end = 0;
    int minSum = INT_MAX;
    int maxSum = INT_MIN;
    int sum = 0;

    while (end < arr.size())
    {
        sum += arr[end];

        if (end - start + 1 == k)
        {
            minSum = min(minSum, sum);
            maxSum = max(maxSum, sum);
            sum = sum - arr[start];
            start++;
        };
        end++;
    }

    cout << (maxSum / 2) - (minSum / 2) << endl;

    return 0;
}