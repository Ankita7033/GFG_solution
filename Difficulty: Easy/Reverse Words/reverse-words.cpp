class Solution {
  public:
    string reverseWords(string &s) {
        vector<string> words;
        string temp = "";

        // Split and ignore empty words
        for (char c : s) {
            if (c == '.') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp.clear();
                }
            } else {
                temp += c;
            }
        }

        // Last word
        if (!temp.empty())
            words.push_back(temp);

        // Build answer in reverse order
        string ans;
        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            if (i > 0)
                ans += '.';
        }

        return ans;
    }
};