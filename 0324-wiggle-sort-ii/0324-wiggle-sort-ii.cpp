class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // Copy the input array
        vector<int> sortedNums = nums;
      
        // Sort the copied array
        sort(sortedNums.begin(), sortedNums.end());
      
        // Get the size of the array
        int n = nums.size();
      
        // Calculate indices for odd and even position elements
        int midIndex = (n - 1) >> 1; // Right shift by 1 is equivalent to divide by 2
        int lastIndex = n - 1;
      
        // Iterate over the numbers to interleave them
        for (int k = 0; k < n; ++k) {
            if (k % 2 == 0) {
                // Even index, assign value from the first half of the sorted array
                nums[k] = sortedNums[midIndex--];
            } else {
                // Odd index, assign value from the second half of the sorted array
                nums[k] = sortedNums[lastIndex--];
            }
        }
        // Now 'nums' is wiggle sorted
    }
};