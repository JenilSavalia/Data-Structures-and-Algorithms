

// binary search

int splitArray(vector<int> &arr, int m)
{

    // range of subarray would be from min element , to sum of all

    int maxEle = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);

    int left = maxEle;
    int right = sum;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (countPossibleSubarray(arr, mid) <= m)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int countPossibleSubarray(vector<int> &arr, int maxSubarraySum)
{
    int count = 1;
    int currSubarraySum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (currSubarraySum + arr[i] <= maxSubarraySum)
        {
            currSubarraySum += arr[i];
        }
        else
        {
            count++;
            currSubarraySum = arr[i];
        }
    }
    return count;
}