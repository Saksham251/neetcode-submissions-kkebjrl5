class Solution {
public:
    bool solve(int index,string s,unordered_set<string>&st,vector<int> &dp,vector<string>& wordDict){
        if(index==s.size()){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        string temp ="";
        for(int j = index;j<s.size();j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                if(solve(j+1,s,st,dp,wordDict)){
                    return dp[index]=true;
                }
            }
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(int i = 0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(0,s,st,dp,wordDict);
    }
};
