class Solution {
  public:
    int sumOfSeries(int n) {
        int sum = n * (n + 1) / 2;
        return sum * sum;
    }
};