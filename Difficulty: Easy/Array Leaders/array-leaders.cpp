class Solution {
public:
    vector<int> leaders(vector<int>& arr) {

        int n = arr.size();

        vector<int> ans;

        int maxi = arr[n - 1];
        ans.push_back(maxi);

        for (int i = n - 2; i >= 0; i--) {

            if (arr[i] >= maxi) {
                maxi = arr[i];
                ans.push_back(arr[i]);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};