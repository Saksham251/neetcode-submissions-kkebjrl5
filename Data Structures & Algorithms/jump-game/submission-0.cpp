class Solution {
public:
    bool solve(int index,vector<bool>&dp,vector<int>&nums){
        if(index==nums.size()-1){
            return true;
        }
        if(nums[index]==0){
            return false;
        }
        if(dp[index]!=false){
            return dp[index];
        }
        int end = min(index+nums[index],int(nums.size())-1);
        for(int j = index+1;j<=end;j++){
            if(solve(j,dp,nums)){
                return dp[index]=true;
            }
        }
        dp[index]=false;
        return dp[index];
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        return solve(0,dp,nums);
    }
};
