class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> subset;

        generateSubsets(result, subset, nums, 0);

        return result;
    }

    void generateSubsets(vector<vector<int>>& result, vector<int> subset,
                         vector<int>& nums, int pos) {
        // base case
        if (pos >= nums.size()) {
            result.push_back(subset);
            return;
        }
        // backtracking
        subset.push_back(nums[pos]);
        generateSubsets(result, subset, nums, pos + 1); // include the current index
        subset.pop_back();
        generateSubsets(result, subset, nums, pos + 1); // excclude the current index

    }
};