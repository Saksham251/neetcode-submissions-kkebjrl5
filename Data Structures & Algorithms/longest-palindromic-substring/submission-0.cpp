class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int resIndex = 0;
        int resLength = 0;
        for(int i = n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                if(s[i]==s[j] && ((j-i<=2) || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(resLength<(j-i+1)){
                        resLength = j-i+1;
                        resIndex = i;
                    }
                }
            }
        }
        return s.substr(resIndex,resLength);
    }
};
