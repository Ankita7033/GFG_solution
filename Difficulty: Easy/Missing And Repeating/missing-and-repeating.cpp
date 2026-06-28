class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {

        int n = arr.size();

        vector<int> freq(n + 1, 0);

        for(int i = 0; i < n; i++)
            freq[arr[i]]++;

        int repeating, missing;

        for(int i = 1; i <= n; i++)
        {
            if(freq[i] == 2)
                repeating = i;

            if(freq[i] == 0)
                missing = i;
        }

        return {repeating, missing};
    }
};