class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        unordered_set<int> res;
        for(auto t:triplets){
            if(t[0]>target[0] || t[1]>target[1] || t[2]>target[2]){
                continue;
            }
            for(int i = 0;i<target.size();i++){
                if(t[i]==target[i]){
                    res.insert(i);
                }
            }
        }
        return res.size()==3;
    }
};
