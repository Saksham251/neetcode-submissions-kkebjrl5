class Solution {
public:
    bool solve(string s1, string s2, string s3,int i,int j,int k,vector<vector<int>>&dp){
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            return true;
        }
        if(i>s1.size() || j>s2.size()){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s3[k] && s2[j]==s3[k]){
            return dp[i][j] = solve(s1,s2,s3,i+1,j,k+1,dp) || solve(s1,s2,s3,i,j+1,k+1,dp);
        }
        else if(s1[i]==s3[k]){
            return dp[i][j] = solve(s1,s2,s3,i+1,j,k+1,dp);
        }
          else if(s2[j]==s3[k]){
            return dp[i][j] = solve(s1,s2,s3,i,j+1,k+1,dp);
        }
        else{
            return dp[i][j]=false;
        }

    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};
