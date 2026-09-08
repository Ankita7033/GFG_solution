class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        if (s1.size() != s2.size()) return false; // Every rotation of s1 will appear in s1 + s1 
        string temp = s1 + s1; 
        return temp.find(s2) != string::npos;
        
    }
};