#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Input: {4, 2, -3, 1, 6}
// Output: true
// Explanation:
// There is a subarray with zero sum from index 1 to 3.

// Given an array of positive and negative numbers, the task is to find if there is a subarray (of size at least one) with 0 sum.

int main()
{

    vector<int> a = {4, 2, -3, 1, 6};
    unordered_set<int> s;

    int sum = 0;
    for (int x : a)
    {
        sum += x;
        if (sum == 0 || s.find(sum) != s.end())
        {
            return true;
        }
        s.insert(sum);
    }

    return false;

    return 0;
}