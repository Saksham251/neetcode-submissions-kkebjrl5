class Solution {
public:
    int solve(int index,vector<int> &dp,vector<int> &nums){
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int doRobbery = nums[index]+solve(index-2,dp,nums);
        int notDoRobbery = 0 + solve(index-1,dp,nums);
        dp[index] = max(doRobbery,notDoRobbery);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return solve(n-1,dp,nums);
    }
};
