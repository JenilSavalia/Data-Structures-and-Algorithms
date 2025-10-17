class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        // vector<int> zero;
        // zero.push_back(-1);
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == 0) {
        //         zero.push_back(i);
        //         cout << i << endl;
        //     }
        // }
        // zero.push_back(nums.size());

        // int count = 0;
        // for (int i = 1; i < zero.size(); i++) {
        //     if (count < zero[i] - zero[i - 1]) {
        //         int len = (zero[i] - zero[i - 1]) - 1;
        //         count = max(len, count);
        //     }
        // }
        // return count;

        int count = 0;
        int currentCount=0;
        for (int x : nums) {
            if (x == 1) {
                currentCount++;
            count = max(currentCount,count);
            }else{
                currentCount = 0;
            }
        }
        return count;
    }
};