


// rotateing array by k positions to right;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        int i;
        if (nums.size() == 1)
            return;
        k = k % nums.size();
        // If k is greater than the length of nums, then you're trying to rotate
        // the array more times than its length — but logically, rotating an
        // array by its length (n) results in the same array. So, rotating by k
        // is the same as rotating by k % n.
        for (i = nums.size() - k; i < nums.size(); i++) {
            temp.push_back(nums[i]);
        }
        for (i = 0; i < nums.size() - k; i++) {
            temp.push_back(nums[i]);
        }
        for (i = 0; i < nums.size(); i++) {
            nums[i] = temp[i];
        }
        
    }
};