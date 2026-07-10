class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());

        int n = arr.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {

            long long removed = prefix[i];

            int idx = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin();

            if (idx < n) {

                long long total = prefix[n] - prefix[idx];

                long long allowed = 1LL * (n - idx) * (arr[i] + k);

                removed += total - allowed;
            }

            ans = min(ans, removed);
        }

        return ans;
    }
};