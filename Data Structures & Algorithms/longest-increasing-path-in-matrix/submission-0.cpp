class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};
    int solve(int i,int j,int preVal,vector<vector<int>> &dp,vector<vector<int>>& matrix){
        if(i>=matrix.size() || i<0 || j>=matrix[0].size() || j<0 || matrix[i][j]<=preVal){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int res = 1;
        for(auto it:directions){
            int i_ = i+it[0];
            int j_ = j+it[1];
            res = max(res,1+solve(i_,j_,matrix[i][j],dp,matrix));
        }
        return dp[i][j] = res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int LIP = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                LIP = max(LIP,solve(i,j,INT_MIN,dp,matrix));
            }
        }
        return LIP;
    }
};
