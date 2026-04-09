class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,string &s,string &t){
        if(j>=t.size()){
            return 1;
        }
        if(i>=s.size()){
            return 0; 
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            dp[i][j] = solve(i+1,j+1,dp,s,t)+solve(i+1,j,dp,s,t);
        }
        else{
            dp[i][j] = solve(i+1,j,dp,s,t);
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solve(0,0,dp,s,t);
    }
};