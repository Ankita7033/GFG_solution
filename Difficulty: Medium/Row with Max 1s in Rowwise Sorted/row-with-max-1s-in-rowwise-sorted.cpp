class Solution {
public:
    // Returns number of 1s in a row
    int maxOnes(vector<int> &row) {
        int low = 0, high = row.size() - 1;
        int firstOne = row.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (row[mid] == 1) {
                firstOne = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return row.size() - firstOne;
    }

    int rowWithMax1s(vector<vector<int>> &arr) {
        int maxi = 0;
        int ans = -1;

        for (int i = 0; i < arr.size(); i++) {
            int ones = maxOnes(arr[i]);

            if (ones > maxi) {
                maxi = ones;
                ans = i;
            }
        }

        return ans;
    }
};