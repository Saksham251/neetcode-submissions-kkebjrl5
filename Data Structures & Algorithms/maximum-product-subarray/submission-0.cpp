class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        
        for(int i = 0;i<nums.size();i++){
            if(prefix==0){
                prefix = 1;
            }
            if(suffix==1){
                suffix = 1;
            }
            prefix = prefix*nums[i];
            suffix = suffix*nums[n-1-i];
            maxi = max(maxi,max(prefix,suffix));
        }
        return maxi;
    }
};
