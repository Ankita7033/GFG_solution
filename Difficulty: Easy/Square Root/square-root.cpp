class Solution {
public:
    int floorSqrt(int n) {
        int low = 1, high = n;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid <= n / mid) {
                // mid * mid <= n
                ans = mid;
                low = mid + 1;
            } 
            else {
                // mid * mid > n
                high = mid - 1;
            }
        }

        return ans;
    }
};