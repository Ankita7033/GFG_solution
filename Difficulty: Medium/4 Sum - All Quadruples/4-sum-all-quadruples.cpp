class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {

        sort(arr.begin(), arr.end());

        int n = arr.size();

        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate first element
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate second element
                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;

                int l = j + 1;
                int r = n - 1;

                while (l < r) {

                    long long sum = (long long)arr[i] + arr[j] +
                                    arr[l] + arr[r];

                    if (sum == target) {

                        ans.push_back({arr[i], arr[j], arr[l], arr[r]});

                        l++;
                        r--;

                        while (l < r && arr[l] == arr[l - 1])
                            l++;

                        while (l < r && arr[r] == arr[r + 1])
                            r--;
                    }

                    else if (sum < target)
                        l++;

                    else
                        r--;
                }
            }
        }

        return ans;
    }
};