class Solution {
public:
    string minWindow(string &s, string &p) {
        if (p.size() > s.size())
            return "";

        vector<int> freq(26, 0);

        // Frequency required from p
        for (char c : p) {
            freq[c - 'a']++;
        }

        int left = 0;
        int count = 0;

        int minLen = INT_MAX;
        int start = -1;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // If this character is still needed
            if (freq[c - 'a'] > 0)
                count++;

            freq[c - 'a']--;

            // Current window contains all characters of p
            while (count == p.size()) {

                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];
                freq[leftChar - 'a']++;

                if (freq[leftChar - 'a'] > 0)
                    count--;

                left++;
            }
        }

        if (start == -1)
            return "";

        return s.substr(start, minLen);
    }
};