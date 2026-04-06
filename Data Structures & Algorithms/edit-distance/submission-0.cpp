class Solution {
public:
    int solve(int index1,int index2,string word1, string word2,vector<vector<int>> &dp){
        if(index1==word1.size()){
            return word2.size()-index2;
        }
         if(index2==word2.size()){
            return word1.size()-index1;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        if(word1[index1]==word2[index2]){
            return dp[index1][index2] = solve(index1+1,index2+1,word1,word2,dp);
        }
        else{
            int insertAns = 1+solve(index1,index2+1,word1,word2,dp);
            int deleteAns = 1+solve(index1+1,index2,word1,word2,dp);
            int updateAns = 1+solve(index1+1,index2+1,word1,word2,dp);
            return dp[index1][index2] = min(insertAns,min(deleteAns,updateAns));
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solve(0,0,word1,word2,dp);
    }
};
