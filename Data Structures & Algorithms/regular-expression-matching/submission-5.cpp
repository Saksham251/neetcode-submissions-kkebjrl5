class Solution {
public:
    bool solve(int i,int j,vector<vector<int>> &dp,string s,string p,int m,int n){
        if(j==n){
            return i==m;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool matched = false;
        if((i<m) && (s[i]==p[j] || p[j]=='.')){
            matched = true;
        }
        if((j+1<n) && p[j+1]=='*'){
            dp[i][j] = solve(i,j+2,dp,s,p,m,n) || (matched && solve(i+1,j,dp,s,p,m,n));
        }
        else{
            dp[i][j] = matched && solve(i+1,j+1,dp,s,p,m,n);
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,dp,s,p,m,n);
    }
};
