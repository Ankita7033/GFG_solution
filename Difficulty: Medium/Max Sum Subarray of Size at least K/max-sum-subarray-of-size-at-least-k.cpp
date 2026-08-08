class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();

        // max subarray sum ending at each index
        vector<int> maxEnd(n);
        maxEnd[0] = arr[0];

        for (int i = 1; i < n; i++) {
            maxEnd[i] = max(arr[i], maxEnd[i - 1] + arr[i]);
        }

        // Sum of first k elements
        int windowSum = 0;
        for (int i = 0; i < k; i++)
            windowSum += arr[i];

        int ans = windowSum;

        // Sliding window
        for (int i = k; i < n; i++) {
            windowSum += arr[i];
            windowSum -= arr[i - k];

            // Exactly k elements
            ans = max(ans, windowSum);

            // More than k elements
            ans = max(ans, windowSum + maxEnd[i - k]);
        }

        return ans;
    }
};