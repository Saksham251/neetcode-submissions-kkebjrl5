class Solution {
public:
        int solve(int index,vector<int>&dp,vector<int>&nums){
        if(index==nums.size()-1){
            return 0;
        }
        if(nums[index]==0){
            return 1000000;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int end = min(index+nums[index],int(nums.size())-1);
        int result = INT_MAX;
        for(int j = index+1;j<=end;j++){
            result = min(result,1+solve(j,dp,nums));
        }
        dp[index]=result;
        return dp[index];
    }
    int jump(vector<int>& nums) {
          int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,dp,nums);
    }
};
