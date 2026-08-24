class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            // Build histogram using ORIGINAL column positions
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Sort a COPY because height must remain
            // associated with its original column.
            vector<int> sortedHeight = height;

            sort(sortedHeight.begin(),
                 sortedHeight.end(),
                 greater<int>());

            // Columns can be rearranged
            for (int j = 0; j < m; j++) {
                int width = j + 1;
                int area = sortedHeight[j] * width;

                ans = max(ans, area);
            }
        }

        return ans;
    }
};