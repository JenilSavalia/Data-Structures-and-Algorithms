class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        int i;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                // find next non zero element and replace with it
                for (int j = i+1; j < nums.size(); j++) {
                    if (nums[j] != 0) {
                      swap(nums[i],nums[j]);
                      break;    
                    }
                }
            }
        }

    }
};