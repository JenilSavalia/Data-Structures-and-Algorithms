#include <iostream>
#include <vector>
using namespace std;

// Main concept of this question is to find all the subarray's

// Brute force approach O(n**2)
int main()
{

    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

    int SumCount = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        SumCount = nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            SumCount += nums[j];
            if (SumCount == k)
            {
                count = max(j - i + 1, count);
            }
        }
    }
    cout << count;
}

// using PREFIX SUM using hashmap O(nlogn)

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{

    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;
    map<int, int> m;
    int sum = 0;
    int len = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        // m.insert({sum,i});
        if (sum == k)
        {
            len = max(len, i + 1);
        }

        int rem = sum - k;

        // m.find(rem):
        // This tries to find the key rem in the map m.
        // If the key exists, find() returns an iterator pointing to that key-value pair.
        // If the key does not exist, it returns m.end() — which is a special iterator that represents
        // "one past the last element" in the map (i.e., it means "not found").

        if (m.find(rem) != m.end())
        {
            int temp = i - m[rem];
            len = max(len, temp);
        }

        if (m.find(sum) == m.end())
        {
            m[sum] = i;
        }
    }

    // for(auto x : m){
    //     cout << x.first << " : " << x.second << endl;
    // }
    cout << len;
}