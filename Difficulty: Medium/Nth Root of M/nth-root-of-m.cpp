class Solution {
  public:
    int nthRoot(int n, int m) {
        if (m == 0) return 0;

        for (int i = 1; i <= m; i++) {
            int power = 1;

            for (int j = 0; j < n; j++) {
                power *= i;
            }

            if (power == m)
                return i;

            if (power > m)
                break;
        }

        return -1;
    }
};