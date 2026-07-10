class Solution {
public:

unordered_map<string,bool> dp;

bool solve(string a,string b){

    if(a==b)
        return true;

    if(a.length()!=b.length())
        return false;

    string key=a+" "+b;

    if(dp.count(key))
        return dp[key];

    int n=a.length();

    for(int i=1;i<n;i++){

        // No Swap
        if(solve(a.substr(0,i),b.substr(0,i))
        &&
        solve(a.substr(i),b.substr(i)))
            return dp[key]=true;

        // Swap
        if(solve(a.substr(0,i),b.substr(n-i))
        &&
        solve(a.substr(i),b.substr(0,n-i)))
            return dp[key]=true;
    }

    return dp[key]=false;
}

bool isScramble(string A,string B){

    dp.clear();

    return solve(A,B);
}

};