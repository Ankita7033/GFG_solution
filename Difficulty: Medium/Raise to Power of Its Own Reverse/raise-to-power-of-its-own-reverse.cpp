class Solution {
  public:
    int reverseExponentiation(int n) {
        int rev = 0;
        int temp = n;

        // Reverse the number
        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        // Calculate n^rev
        int ans = 1;

        for (int i = 0; i < rev; i++) {
            ans *= n;
        }

        return ans;
    }
};