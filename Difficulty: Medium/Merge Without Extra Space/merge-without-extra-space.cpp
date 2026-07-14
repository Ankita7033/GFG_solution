class Solution {
public:
    int nextGap(int gap) {
        if (gap <= 1) return 0;
        return (gap / 2) + (gap % 2);
    }

    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        int gap = nextGap(n + m);

        while (gap > 0) {

            int i = 0;
            int j = gap;

            while (j < n + m) {

                // both in a
                if (i < n && j < n) {
                    if (a[i] > a[j])
                        swap(a[i], a[j]);
                }

                // i in a, j in b
                else if (i < n && j >= n) {
                    if (a[i] > b[j - n])
                        swap(a[i], b[j - n]);
                }

                // both in b
                else {
                    if (b[i - n] > b[j - n])
                        swap(b[i - n], b[j - n]);
                }

                i++;
                j++;
            }

            gap = nextGap(gap);
        }
    }
};