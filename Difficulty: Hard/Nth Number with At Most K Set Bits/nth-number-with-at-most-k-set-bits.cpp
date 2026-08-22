class Solution {
public:
    long long findNthNumber(int n, int k) {
        // n is 1-indexed, and 0 is the first number.

        // Count binary numbers of length 'len'
        // having at most k set bits.
        auto countNumbers = [&](int len, int ones) -> long long {
            if (len == 1) return 1; // only "1"

            int bits = len - 1;     // remaining bits after leading 1
            int need = min(ones - 1, bits);

            long long sum = 0;
            long long comb = 1;    // C(bits, 0)

            for (int j = 0; j <= need; j++) {
                if (j > 0)
                    comb = comb * (bits - j + 1) / j;

                // n <= INT_MAX, so cap safely
                if (sum > (long long)n - comb)
                    return n;

                sum += comb;
            }

            return sum;
        };

        // 0 is the first number.
        if (n == 1)
            return 0;

        n--; // Now find the (n)-th positive number.

        // Find the bit-length of the answer.
        int len = 1;

        while (true) {
            long long cnt = countNumbers(len, k);

            if (n <= cnt)
                break;

            n -= cnt;
            len++;
        }

        // The answer starts with 1.
        long long ans = 1LL << (len - 1);
        int remainingOnes = k - 1;

        // Construct the remaining bits from left to right.
        for (int pos = len - 2; pos >= 0; pos--) {
            if (remainingOnes == 0)
                break;

            // If this bit is 0, count valid numbers obtainable
            // from the remaining 'pos' bits.
            long long cnt = 0;
            long long comb = 1; // C(pos, 0)

            int limit = min(remainingOnes, pos);

            for (int j = 0; j <= limit; j++) {
                if (j > 0)
                    comb = comb * (pos - j + 1) / j;

                if (cnt > (long long)n - comb) {
                    cnt = n;
                    break;
                }

                cnt += comb;
            }

            if (n > cnt) {
                // Skip all numbers whose current bit is 0.
                n -= cnt;

                // Current bit becomes 1.
                ans |= (1LL << pos);
                remainingOnes--;
            }
        }

        return ans;
    }
};