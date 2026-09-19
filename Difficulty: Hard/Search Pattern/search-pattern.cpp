class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        int m = pat.size();
        int n = txt.size();

        // LPS = Longest Proper Prefix which is also Suffix
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                lps[i] = len + 1;
                len++;
                i++;
            } 
            else {
                if (len != 0) {
                    len = lps[len - 1];
                } 
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        vector<int> ans;

        // Search pattern in text
        i = 0;
        int j = 0;

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m) {
                ans.push_back(i - j);

                // Continue searching for overlapping occurrences
                j = lps[j - 1];
            }
            else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return ans;
    }
};