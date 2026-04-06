class Solution {
public:
    int solve(int index,int curr,int prev,vector<vector<int>> &dp,vector<int> &nums){
        if(index==nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int take = 0;
        if(prev==-1 || nums[curr]>nums[prev]){
            take = 1+solve(index+1,curr+1,curr,dp,nums);
        }
        int notTake = solve(index+1,curr+1,prev,dp,nums);
        return dp[curr][prev+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,-1,dp,nums);
    }
};
