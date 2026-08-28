class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int total = 0;

        int curMax = 0, maxSum = arr[0];
        int curMin = 0, minSum = arr[0];

        for (int x : arr) {
            // Maximum subarray (Kadane)
            curMax = max(x, curMax + x);
            maxSum = max(maxSum, curMax);

            // Minimum subarray
            curMin = min(x, curMin + x);
            minSum = min(minSum, curMin);

            total += x;
        }

        // All elements are negative
        if (maxSum < 0)
            return maxSum;

        // Either normal or circular answer
        return max(maxSum, total - minSum);
    }
};