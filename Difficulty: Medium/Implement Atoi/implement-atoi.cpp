
class Solution {
public:
    int myAtoi(string &s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        long long num = 0;

        // 1. Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check the sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // 3. Read digits and handle overflow
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            num = num * 10 + digit;

            // 4. Handle overflow
            if (sign == 1 && num > 2147483647LL) {
                return 2147483647;
            }

            if (sign == -1 && num > 2147483648LL) {
                return -2147483648;
            }

            i++;
        }

        return (int)(sign * num);
    }
};
