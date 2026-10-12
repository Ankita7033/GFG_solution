class Solution {
public:
    int countDistinct(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        return s.size();
    }
};