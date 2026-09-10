class Solution {
public:
    vector<int> singleNum(vector<int>& arr) {
        int x = 0;

        // XOR of all elements = a ^ b
        for (int num : arr)
            x ^= num;

        // Get a set bit where a and b differ
        int bit = x & -x;

        int a = 0, b = 0;

        // Divide numbers into two groups
        for (int num : arr) {
            if (num & bit)
                a ^= num;
            else
                b ^= num;
        }

        if (a > b)
            swap(a, b);

        return {a, b};
    }
};