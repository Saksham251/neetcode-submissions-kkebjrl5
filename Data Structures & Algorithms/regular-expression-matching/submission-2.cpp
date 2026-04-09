class Solution {
public:
    bool solve(string s,string p){
        if(p.length()==0){
            return s.length()==0;
        }

        bool first_char_matched = false;
        if((s.length()>0) && (s[0]==p[0] || p[0]=='.')){
            first_char_matched = true;
        }
        if(p[1]=='*'){
            bool notTake = solve(s,p.substr(2));
            bool take = first_char_matched && solve(s.substr(1),p);
            return take || notTake;
        }
        return first_char_matched && solve(s.substr(1),p.substr(1));
    }
    bool solveOp(int i,int j,vector<vector<int>> &dp,string s,string p,int m,int n){
        if(j==n){
            return i==m; 
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        bool firstCharMatched = false;
        if((i<m) && (s[i]==p[j] || p[j]=='.')){
            firstCharMatched = true;
        }
        if(j + 1 < n && p[j + 1] == '*'){
            dp[i][j] = solveOp(i,j+2,dp,s,p,m,n) || (firstCharMatched && solveOp(i+1,j,dp,s,p,m,n));
        }
        else{
            dp[i][j] = firstCharMatched && solveOp(i+1,j+1,dp,s,p,m,n);
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return solve(s,p);
        return solveOp(0,0,dp,s,p,m,n);
    }
};