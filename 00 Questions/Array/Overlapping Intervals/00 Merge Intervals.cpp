// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        if (intervals.size() == 1)
            return intervals;

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        int n = intervals.size();
        for (int i = 1; i < n; i++)
        {
            if (result.back()[1] >= intervals[i][0])
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};