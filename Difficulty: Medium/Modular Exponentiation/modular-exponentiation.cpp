
class Solution {
  public:
    int powMod(int x, int n, int M) {
        long long ans = 1;
        long long base = x % M;

        while (n > 0) {
            if (n % 2 == 1) {
                ans = (ans * base) % M;
            }

            base = (base * base) % M;
            n /= 2;
        }

        return ans;
    }
};
