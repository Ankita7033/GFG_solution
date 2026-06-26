class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int left=0;
        int sum=0;
        int n = arr.size();
        vector<int>ans;
        for(int right=0;right<n;right++) {
            sum+=arr[right];
            while(sum>target && left<=right) {
                sum-=arr[left];
                left++;
            }
            if(sum==target) {
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
    
        }
        ans.push_back(-1);
        
        return ans;
        
    }
};