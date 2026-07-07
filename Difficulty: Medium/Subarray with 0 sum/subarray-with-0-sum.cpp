class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_set<int>st;
        int sum=0;
        for(int n : arr){
            sum+=n;
            if(sum==0){
                return true;
            }
            if(st.count(sum)){
                return true;
            }
            st.insert(sum);
        }
        return false;
    }
};