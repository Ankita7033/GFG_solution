class Solution {
public:
    void solve(int n, vector<int>& ans) {
        ans.push_back(n);

        // Base case
        if (n <= 0)
            return;

        // Decreasing phase
        solve(n - 5, ans);

        // Increasing phase
        ans.push_back(n);
    }

    vector<int> pattern(int n) {
        vector<int> ans;
        solve(n, ans);
        return ans;
    }
};