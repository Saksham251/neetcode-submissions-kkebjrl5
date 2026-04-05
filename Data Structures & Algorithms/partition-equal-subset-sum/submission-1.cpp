class Solution {
public:
    bool solve(int index,int target,vector<int>& nums,vector<vector<int>> &dp){
        if(target<0){
            return false;
        }
        if(target==0){
            return true;
        }
        if(index>=nums.size()){
            return false;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        bool pick = solve(index+1,target-nums[index],nums,dp);
        bool notPick = solve(index+1,target,nums,dp);
        return dp[index][target]=pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            sum+=nums[i];
        }
        if(sum & 1){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(0,target,nums,dp);
    }
};
