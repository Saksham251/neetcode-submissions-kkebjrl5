class Solution {
public:
    int solve(vector<int> &nums,int left,int right,vector<vector<int>> &dp){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        dp[left][right] = 0;
        for(int i = left;i<=right;i++){
            int coins = nums[left-1]*nums[i]*nums[right+1];
            coins+=solve(nums,left,i-1,dp)+solve(nums,i+1,right,dp);
            dp[left][right] = max(dp[left][right],coins);
        }
        return dp[left][right];
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n+2,1);
        for(int i = 0;i<n;i++){
            newNums[i+1] = nums[i];
        }
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return solve(newNums,1,newNums.size()-2,dp);
    }
};
