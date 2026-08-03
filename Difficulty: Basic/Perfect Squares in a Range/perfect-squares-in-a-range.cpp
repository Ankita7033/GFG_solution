
class Solution {
  public:
    int numOfPerfectSquares(int a, int b) {
        // code here
         int left = ceil(sqrt(a));
        int right = floor(sqrt(b));

        if (left > right)
            return 0;

        return right - left + 1;
        
    }
};