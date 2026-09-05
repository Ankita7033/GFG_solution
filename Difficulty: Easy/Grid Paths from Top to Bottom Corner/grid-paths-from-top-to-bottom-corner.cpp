class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& mat,
               vector<int>& path, vector<vector<int>>& ans) {

        int n = mat.size();
        int m = mat[0].size();

        path.push_back(mat[i][j]);

        // Reached bottom-right
        if (i == n - 1 && j == m - 1) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        // Move down
        if (i + 1 < n) {
            solve(i + 1, j, mat, path, ans);
        }

        // Move right
        if (j + 1 < m) {
            solve(i, j + 1, mat, path, ans);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> allPaths(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(0, 0, mat, path, ans);

        return ans;
    }
};