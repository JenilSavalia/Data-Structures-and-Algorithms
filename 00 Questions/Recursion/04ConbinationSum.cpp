class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        // Combination Sum is solved by backtracking where we either reuse the current number or move forward,
        //  while pruning paths that exceed the target.

        // we would need to take two decisions at every candidate
        // i.e
        // 1) take the current index
        // 2) skip the current index
        vector<vector<int>> result;
        vector<int> subset;
        generate(candidates, subset, result, 0, 0, target);

        return result;
    }

    void generate(vector<int> &candidates, vector<int> &subset,
                  vector<vector<int>> &result, int sum, int index, int target)
    {

        if (sum > target)
            return;

        if (index == candidates.size())
            return;

        if (target == sum)
        {
            result.push_back(subset);
            return;
        }

        // decision #1 -> take the current index
        subset.push_back(candidates[index]);
        generate(candidates, subset, result, sum + candidates[index], index,
                 target);

        // decision #2 -> skip the current index
        subset.pop_back();
        generate(candidates, subset, result, sum, index + 1, target);
    }
};