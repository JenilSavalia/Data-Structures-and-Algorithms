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

// most optimal approach would be using two pointers O(2n) ~~ O(n)

// so to approach this question lets visualise how sub arrays are formed
// {1,2,3,1,1,1,1,3,3}   k=6

// so what are possible sub arrays
// {1,2}
// {1,2,3}
// {1,2,3,4}
// {1,2,3,4,1}
// {1,2,3,4,1,1}
// {1,2,3,4,1,1,1}
// {1,2,3,4,1,1,1.....,3}

// above is one set od sub arrays

// next would be

// {2,3}
// {2,3,1}
// {2,3,1,1}
// {2,3,1,1,1}

// and so on and so forth

// thing to note here is

// {1,2}    -> sum of this sub array is 3
// {1,2,3}   -> 6
// {1,2,3,4}    ->  sum of this sub array is 10 , which is more then k , so further subarrays would would not meet our k=6,
//                  so we would not iterate futrher to this below set of sub sets
// {1,2,3,4,1}
// {1,2,3,4,1,1}
// {1,2,3,4,1,1,1}
// {1,2,3,4,1,1,1.....,3}

// what we would do is we would move to next set of sub seft by moving our left pointer to starting pointer of that sub array

// {1,2,3,1,1,1,1,3,3}
//  ^     ^

// at this point sum of this sub array is 1+2+3+1 = 7 , which is more then k
// so we move to next set of sub arrays by moving left pointer such that, element it points is less then or equal to
// right pointer index and sum of that sub array is less then k.

// lets dive into the code and make sure to dry run it to enhance your learning

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int sum = arr[0];

    while (right < n)
    {
        while (sum > k && left <= right)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(right - left + 1, maxLen);
        }
        right++;
        if (right < n)
            sum += arr[right];
    }

    cout << maxLen;
}