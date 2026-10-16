class Solution {
  public:
    vector<int> valEqualToPos(vector<int>& arr) {
        vector<int> result;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == i + 1) {
                result.push_back(arr[i]);
            }
        }

        return result;
    }
};