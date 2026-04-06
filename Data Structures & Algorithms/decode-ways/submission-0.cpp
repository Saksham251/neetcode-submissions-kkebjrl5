class Solution {
public:
    int solve(int index,vector<int> &dp,string s){
        if(index==s.size()){
            return 1;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int res = 0;
        if(s[index]=='0'){
            return 0;
        }
        res+=solve(index+1,dp,s);
        if((index+1<s.size() && (s[index]=='1' || s[index]=='2' && s[index+1]<='6'))){
            res+=solve(index+2,dp,s);
        }
        return dp[index] = res;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(0,dp,s);
    }
};
