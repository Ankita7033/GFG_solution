class Solution {
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int> ans;

        int i = 0, j = 0, k = 0;

        while (i < a.size() && j < b.size() && k < c.size()) {

            if (a[i] == b[j] && b[j] == c[k]) {
                // Avoid duplicates
                if (ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);

                i++;
                j++;
                k++;
            }
            else {
                int mn = min({a[i], b[j], c[k]});

                if (a[i] == mn) i++;
                if (b[j] == mn) j++;
                if (c[k] == mn) k++;
            }
        }

        return ans;
    }
};