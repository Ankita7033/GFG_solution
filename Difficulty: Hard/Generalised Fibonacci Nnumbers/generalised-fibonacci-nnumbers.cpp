class Solution {
public:
    long long mod;

    vector<vector<long long>> multiply(vector<vector<long long>> A,
                                       vector<vector<long long>> B) {
        vector<vector<long long>> C(3, vector<long long>(3, 0));

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>> A, int n) {
        vector<vector<long long>> res = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };

        while (n) {
            if (n & 1)
                res = multiply(res, A);

            A = multiply(A, A);
            n >>= 1;
        }

        return res;
    }

    int genFibNum(int a, int b, int c, int n, int m) {
        mod = m;

        if (n == 1 || n == 2)
            return 1 % m;

        // Transformation matrix:
        // g(i) = a*g(i-1) + b*g(i-2) + c
        vector<vector<long long>> T = {
            {a % m, b % m, c % m},
            {1,     0,     0},
            {0,     0,     1}
        };

        T = power(T, n - 2);

        // Initial vector = [g(2), g(1), 1] = [1, 1, 1]
        return (T[0][0] + T[0][1] + T[0][2]) % m;
    }
};