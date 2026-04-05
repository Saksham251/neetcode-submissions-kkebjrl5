class Solution {
public:
    int solve(int index,vector<int>&cost,vector<int>&dp){
        if(index==0){
            return cost[0];
        }
         if(index==1){
            return cost[1];
        }
        if(dp[index]!=-1){
            return dp[index];
        }
       
        dp[index]= cost[index]+min(solve(index-1,cost,dp),solve(index-2,cost,dp));
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
    }
};
