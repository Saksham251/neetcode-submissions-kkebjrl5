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
        if(n==1){
            return nums[0];
        }
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        vector<int> first;
        vector<int> second;

        // exclude first
        for(int i = 1; i < n; i++){
            first.push_back(nums[i]);
        }

        // exclude last
        for(int i = 0; i < n-1; i++){
            second.push_back(nums[i]);
        }
        return max(solve(first.size()-1,dp1,first),solve(second.size()-1,dp2,second));
    }
};
