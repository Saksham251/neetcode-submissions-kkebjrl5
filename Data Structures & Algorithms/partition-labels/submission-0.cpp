class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> lastIndex;
        vector<int> result;
        int n = s.size();
        for(int i = 0;i<n;i++){
            lastIndex[s[i]] = i;
        }
        int size = 0;
        int end = 0;

        for(int i = 0;i<n;i++){
            size++;
            end = max(end,lastIndex[s[i]]);
            if(i==end){
                result.push_back(size);
                size = 0;
            }
        }
        return result;
    }
};
