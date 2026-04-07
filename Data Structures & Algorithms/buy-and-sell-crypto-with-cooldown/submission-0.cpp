class Solution {
public:
    int solve(int index,bool buying,vector<int>& prices,vector<vector<int>> &dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][buying]!=-1){
            return dp[index][buying];
        }
        int skip = solve(index+1,buying,prices,dp);
        if(buying){
            int buy = solve(index+1,false,prices,dp)-prices[index];
            return dp[index][buying] = max(skip,buy);
        }
        else{
            int sell = solve(index+2,true,prices,dp)+prices[index];
            return dp[index][buying] = max(skip,sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0,true,prices,dp);
    }
};
