class Solution {
public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        int sum = 0;
        int ans = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            
            // If prefix sum is 0, subarray from 0 to i
            if (sum == 0)
                ans = i + 1;
            
            // Prefix sum seen before
            if (mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            } else {
                // Store first occurrence only
                mp[sum] = i;
            }
        }
        
        return ans;
    }
};