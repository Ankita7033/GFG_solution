
class Solution {
  public:
    long long sumOfDivisors(long long n) {
        long long sum = 0;

        for (long long i = 1; i <= n; i++) {
            sum += i * (n / i);
        }

        return sum;
    }
};
