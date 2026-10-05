class Solution {
public:
    string reverses(string &s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] == ' ') {
                left++;
            }
            else if (s[right] == ' ') {
                right--;
            }
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};