class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        // code here
        vector<int> ans;

        long long d = 1LL * b * b - 4LL * a * c;

        // No real roots
        if (d < 0) {
            ans.push_back(-1);
            return ans;
        }

        int root1 = floor((-b + sqrt(d)) / (2.0 * a));
        int root2 = floor((-b - sqrt(d)) / (2.0 * a));

        ans.push_back(max(root1, root2));
        ans.push_back(min(root1, root2));

        return ans;
    }
};