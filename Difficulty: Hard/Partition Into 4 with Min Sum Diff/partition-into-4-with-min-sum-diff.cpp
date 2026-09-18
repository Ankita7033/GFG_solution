class Solution {
public:
    long long minDifference(vector<int> &arr) {
        int n = arr.size();

        // Prefix sums
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + arr[i];
        }

        long long total = pref[n];
        long long ans = LLONG_MAX;

        // j = end of Q / start of R
        // Need:
        // P = [0 ... i-1]
        // Q = [i ... j-1]
        // R = [j ... k-1]
        // S = [k ... n-1]
        //
        // In prefix notation:
        // W = pref[i]
        // X = pref[j] - pref[i]
        // Y = pref[k] - pref[j]
        // Z = total - pref[k]
        //
        // Therefore i must be in [1, j-1]
        // and k must be in [j+1, n-1].

        for (int j = 2; j <= n - 2; j++) {
            // ---------------------------------
            // Split pref[j] into W and X
            // Want pref[i] ~= pref[j] / 2
            // ---------------------------------
            long long targetLeft = pref[j] / 2;

            auto it = lower_bound(
                pref.begin() + 1,
                pref.begin() + j,
                targetLeft
            );

            vector<int> candidatesLeft;

            if (it != pref.begin() + j)
                candidatesLeft.push_back(it - pref.begin());

            if (it != pref.begin() + 1)
                candidatesLeft.push_back((it - pref.begin()) - 1);

            // ---------------------------------
            // Split remaining part into Y and Z
            // Want pref[k] - pref[j] ~= (total-pref[j])/2
            //
            // Therefore:
            // pref[k] ~= (total + pref[j]) / 2
            // ---------------------------------
            long long targetRight =
                (total + pref[j]) / 2;

            auto it2 = lower_bound(
                pref.begin() + j + 1,
                pref.begin() + n,
                targetRight
            );

            vector<int> candidatesRight;

            if (it2 != pref.begin() + n)
                candidatesRight.push_back(it2 - pref.begin());

            if (it2 != pref.begin() + j + 1)
                candidatesRight.push_back((it2 - pref.begin()) - 1);

            // Try the closest candidates on both sides
            for (int i : candidatesLeft) {
                for (int k : candidatesRight) {

                    long long W = pref[i];
                    long long X = pref[j] - pref[i];
                    long long Y = pref[k] - pref[j];
                    long long Z = total - pref[k];

                    long long mx = max({W, X, Y, Z});
                    long long mn = min({W, X, Y, Z});

                    ans = min(ans, mx - mn);
                }
            }
        }

        return ans;
    }
};