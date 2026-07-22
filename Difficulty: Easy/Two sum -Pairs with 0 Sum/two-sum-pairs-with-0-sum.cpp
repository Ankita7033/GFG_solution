class Solution {
public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        vector<vector<int>> ans;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == 0) {
                ans.push_back({arr[left], arr[right]});

                int l = arr[left];
                int r = arr[right];

                while (left < right && arr[left] == l)
                    left++;
                while (left < right && arr[right] == r)
                    right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};