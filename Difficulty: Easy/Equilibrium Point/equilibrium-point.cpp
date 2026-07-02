class Solution {
public:
    int findEquilibrium(vector<int> &arr) {

        long long totalSum = 0;

        for (int x : arr)
            totalSum += x;

        long long leftSum = 0;

        for (int i = 0; i < arr.size(); i++) {

            totalSum -= arr[i];   

            if (leftSum == totalSum)
                return i;

            leftSum += arr[i];
        }

        return -1;
    }
};