class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // int sum = 0;
        // int maxSum = INT_MIN;
        // int n = nums.size();
        // if(n==1) return nums[0];
        // for (int i = 0; i < n; i++) {
        //     sum = 0;
        //     for (int j = i; j < n; j++) {
        //         sum = sum + nums[j];
        //         maxSum = max(sum,maxSum);
        //     }
        // }
        // return maxSum;

        // Kadanes Algorithm

        int maxSum = INT_MIN;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            currentSum += nums[i];

            if (currentSum > maxSum)
            {
                maxSum = currentSum;
            }
            if (currentSum < 0)
            {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};

// printing indexes if max subarray (extension to kadanes algorithm)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        // maxSum keeps track of the maximum sum found so far
        // currentSum is the sum of the current subarray we're considering
        // L and R are the left and right pointers for the current window (subarray)
        // max_L and max_R will store the indices of the subarray with the maximum sum
        int maxSum = INT_MIN;
        int currentSum = 0;
        int L = 0, R = 0; // Left pointer (L) starts at 0, right pointer (R) will move across the array
        int max_L, max_R;

        // Iterate through the array with the right pointer (R)
        for (int R = 0; R < nums.size(); R++)
        {
            // Add the current element to the current sum
            currentSum += nums[R];

            // If the current sum exceeds the max sum, update the max sum and the subarray indices
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                max_L = L;
                max_R = R;
            }

            // If currentSum becomes negative, reset currentSum and move the left pointer to R
            // This means we start a new subarray from the next index
            if (currentSum < 0)
            {
                currentSum = 0;
                L = R;
            }
        }

        // Print the indices of the subarray with the maximum sum
        cout << max_L << " " << max_R;

        // Return the maximum sum found
        return maxSum;
    }
};
