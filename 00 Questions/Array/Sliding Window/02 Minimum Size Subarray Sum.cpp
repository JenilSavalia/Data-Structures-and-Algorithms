
// find the minimum length of a contiguous subarray such that
// sum(subarray) ≥ target
// If no such subarray exists, return 0.

// target = 7
// nums = [2, 3, 1, 2, 4, 3]

// Why?

// The subarrays whose sums ≥ 7 are:

// [2,3,1,2] → sum = 8 → length = 4

// [3,1,2,4] → sum = 10 → length = 4

// [1,2,4] → sum = 7 → length = 3

// [4,3] → sum = 7 → length = 2 ← minimum

// So answer = 2

// ✅ 🔶 Why Sliding Window Works

// Because:

// All numbers in nums are positive.

// When the sum becomes too large, shrinking the window will always decrease the sum.

// When the sum is too small, expanding the window will always increase the sum.

// This allows a two-pointer sliding window approach.