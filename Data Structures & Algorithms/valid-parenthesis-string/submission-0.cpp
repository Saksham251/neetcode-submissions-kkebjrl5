class Solution {
public:
    bool solve(string &s,int index,int count,vector<vector<int>>&dp){
        if(index==s.size()){
            return count == 0;
        }
        if(count<0){
            return false;
        }
        if(dp[index][count]!=-1){
            return dp[index][count];
        }
         if(s[index]=='('){
            return dp[index][count] = solve(s,index+1,count+1,dp);
        }
        else if(s[index]==')'){
            return dp[index][count] =  solve(s,index+1,count-1,dp);
        }
        else if(s[index]=='*'){
            return dp[index][count] = solve(s,index+1,count,dp) || solve(s,index+1,count-1,dp) || solve(s,index+1,count+1,dp);
        }
        return true;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int count = 0;
        return solve(s,0,0,dp);
    }
};
