class Solution
{
    void heapify(vector<int> &a, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest])
            largest = left;

        if (right < n && a[right] > a[largest])
            largest = right;

        if (largest != i)
        {
            swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // sort(nums.begin(),nums.end());
        // return nums[(nums.size()-1)-k+1];

        // we start from n/2-1 as n/2-1 is index of last node before leaf node,
        // means next node is leaf node

        // all leaf node are considered heap, there fore we start to heapify
        // from n/2-1

        int n = nums.size();
        // Build MAX heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        // Extract max k-1 times
        for (int i = n - 1; i >= n - k + 1; i--)
        {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }

        return nums[0];
    }
};