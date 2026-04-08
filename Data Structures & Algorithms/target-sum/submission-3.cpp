class Solution {
public:
    # define MOD 1000000007
    int solve(int index,int amount,vector<vector<int>> &dp,vector<int> &nums){
         if(index == nums.size()){
            return amount == 0;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int pick = 0;
        if(amount-nums[index]>=0){
            pick = solve(index+1,amount-nums[index],dp,nums);
        }
        int notPick = solve(index+1,amount,dp,nums);
        return dp[index][amount] = (pick%MOD+notPick%MOD)%MOD;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        // S1 + S2 = totalSum
        // S1 - S2 = d
        int subsetSum = (totalSum-target)/2;
        if((totalSum-target)< 0 || (totalSum-target)%2==1) return 0;
        vector<vector<int>> dp(n,vector<int>(subsetSum+1,-1));
        return solve(0,subsetSum,dp,nums);
    }
};
