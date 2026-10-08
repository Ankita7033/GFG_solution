class Solution {
public:
    void rearrange(vector<int> &arr) {
        vector<int> pos, neg;

        // Separate positives and negatives while preserving order
        for (int x : arr) {
            if (x >= 0)
                pos.push_back(x);
            else
                neg.push_back(x);
        }

        vector<int> result;
        int i = 0, j = 0;

        // Always start with positive
        while (i < pos.size() && j < neg.size()) {
            result.push_back(pos[i++]);
            result.push_back(neg[j++]);
        }

        // Add remaining positives
        while (i < pos.size()) {
            result.push_back(pos[i++]);
        }

        // Add remaining negatives
        while (j < neg.size()) {
            result.push_back(neg[j++]);
        }

        arr = result;
    }
};