#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// The Painter's Partition Problem

// Given an array arr[] and k, where the array represents the boards and each element of
// the given array represents the length of each board. k numbers of painters are available
// to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
// The task is to find the minimum time to get this job done by painting all the boards under
// the constraint that any painter will only paint the continuous sections of boards

int allocatePainters(vector<int> &arr, int answerToCheck)
{

    // This function answers one question:
    // If each painter is allowed to paint at most answerToCheck units of board length,
    // how many painters are required to paint all boards (continuously)?

    int count = 1;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (currentSum + arr[i] <= answerToCheck)
        {
            currentSum += arr[i];
        }
        else
        {
            count++;
            currentSum = arr[i];
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int painters = 2;

    int maxEle = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);

    // what question is that, we are given a array, element in array represents borads and arr[i] is length
    // of the board, and we are given k (painters), we need to paint  all boards and return the minimum
    // time  to get the job done

    // ex
    // arr = [10,20,30,40] and k = 2;

    // basically this problem is if binary search pattern of min(max) on answers

    // following are the partitons:
    //         10 | 20 30 40      => min time to complete job is => max(10 , 20+30+40)
    //         10 20 | 30 40      => min time to complete job is => max(10+20 , 30+40)
    //         10 20 30 | 40      => min time to complete job is => max(10+20+30 , 40)
    //

    // we will find answer on range [max_element,sum_of_elements]
    // why ????
    // if k = 1, then min time to finish job would be sum of all elements
    // and if k = size of arr , then min time to complete job would be max element

    int left = maxEle;
    int right = sum;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (allocatePainters(arr, mid) > painters)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << left;

    return 0;
}

// Time complexity (good to mention in interviews)

// Time: O(n log(sum))
// Space: O(1)