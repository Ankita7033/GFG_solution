class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= x) {
                ans = mid;        // Possible floor
                low = mid + 1;    // Look for a larger valid value
            } else {
                high = mid - 1;   // Floor must be on the left
            }
        }

        return ans;
    }
};