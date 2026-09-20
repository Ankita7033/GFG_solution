class Solution {
  public:
    int countSetBits(int n) {
        if (n == 0)
            return 0;

        // Find largest power of 2 <= n
        int x = 0;
        while ((1 << (x + 1)) <= n)
            x++;

        int p = 1 << x;

        // Count set bits from 1 to p-1
        int bitsBefore = x * (p / 2);

        // Count the highest bit in numbers p to n
        int highestBit = n - p + 1;

        // Count remaining bits
        int remaining = countSetBits(n - p);

        return bitsBefore + highestBit + remaining;
    }
};