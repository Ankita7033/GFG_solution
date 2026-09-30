class Solution {
private:
    const int MOD = 1e9 + 7;

    // Helper function to precompute factorials for fast combination nCr calculations
    void precomputeFactorials(int n, vector<long long>& fact, vector<long long>& invFact) {
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    // Binary exponentiation to calculate modular inverse
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // nCr modulo 10^9 + 7
    long long nCr(int n, int r, const vector<long long>& fact, const vector<long long>& invFact) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    // Check if the sum contains digit 'c' or 'd'
    bool isValidSum(long long sum, int c, int d) {
        if (sum == 0) return (c == 0 || d == 0);
        while (sum > 0) {
            int digit = sum % 10;
            if (digit == c || digit == d) return true;
            sum /= 10;
        }
        return false;
    }

public:
    int bestNumbers(int n, int a, int b, int c, int d) {
        // Edge case: if a and b are identical, there's only one arrangement (all digits are a)
        if (a == b) {
            long long totalSum = (long long)n * a;
            return isValidSum(totalSum, c, d) ? 1 : 0;
        }

        vector<long long> fact(n + 1);
        vector<long long> invFact(n + 1);
        precomputeFactorials(n, fact, invFact);

        long long ans = 0;

        // Iterate through all possible counts of digit 'a' from 0 to n
        for (int i = 0; i <= n; i++) {
            long long currentSum = (long long)i * a + (long long)(n - i) * b;

            if (isValidSum(currentSum, c, d)) {
                ans = (ans + nCr(n, i, fact, invFact)) % MOD;
            }
        }

        return ans;
    }
};
