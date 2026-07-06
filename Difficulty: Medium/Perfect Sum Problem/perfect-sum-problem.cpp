class Solution {
  public:
    int perfectSum(vector<int>& arr, int sum) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // Sum 0 is always possible by taking empty subset
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {

                // Don't take current element
                dp[i][j] = dp[i - 1][j];

                // Take current element if possible
                if (j >= arr[i - 1]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]) % MOD;
                }
            }
        }

        return dp[n][sum];
    }
};