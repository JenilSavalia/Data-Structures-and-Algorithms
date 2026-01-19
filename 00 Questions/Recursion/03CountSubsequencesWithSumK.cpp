#include <iostream>
#include <vector>
using namespace std;

// https://takeuforward.org/data-structure/count-all-subsequences-with-sum-k

void generate(vector<int> &nums, vector<int> subset, int target, int sum, int &count, int index)
{
    if (nums.size() == index)
    {
        if (sum == target)
            count++;
        // cout << sum <<  endl;
        return;
    }

    subset.push_back(nums[index]);
    sum += nums[index];
    generate(nums, subset, target, sum, count, index + 1);

    subset.pop_back();
    sum -= nums[index];
    generate(nums, subset, target, sum, count, index + 1);
}

int main()
{

    vector<int> nums = {4, 2, 10, 5, 1, 3};
    vector<int> subset;
    int target = 5;
    int count = 0;

    generate(nums, subset, target, 0, count, 0);
    cout << count;

    return 0;
}