class Solution {
public:
    bool isValid(string s) {
        stringstream ss(s);
        string part;
        int count = 0;

        while (getline(ss, part, '.')) {
            // Empty part
            if (part.empty())
                return false;

            // Only digits
            for (char c : part) {
                if (!isdigit(c))
                    return false;
            }

            // Leading zero
            if (part.size() > 1 && part[0] == '0')
                return false;

            // Convert to number
            int num = stoi(part);

            // Range check
            if (num < 0 || num > 255)
                return false;

            count++;
        }

        return count == 4;
    }
};