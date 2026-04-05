class Solution {
public:
    vector<int> topoSort(int V,vector<int> adj[]){
        vector<int> indegree(V,0);

        for(int i = 0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        vector<int> topo;
        queue<int>q;
        for(int i = 0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto adjNode:adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0){
                    q.push(adjNode);
                }
            }
        }
        return topo;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<int> adj[26];
        unordered_set<char>uniqueChars;
        for(auto word:words){
            for(int i = 0;i<word.size();i++){
                uniqueChars.insert(word[i]);
            }
        }

        for(int i = 0;i<n-1;i++){
            string str1 = words[i];
            string str2 = words[i+1];
            if(str1.length()>str2.length() && (str1.substr(0,str2.length())==str2)){
                return "";
            }

            int minLength = min(str1.size(),str2.size());
            for(int j = 0;j<minLength;j++){
                if(str1[j]!=str2[j]){
                    adj[str1[j]-'a'].push_back(str2[j]-'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(26,adj);

        // cycle detection 
        if(topo.size()<uniqueChars.size()){
            return "";
        }

        string ans = "";
        for(auto it:topo){
            char ch = it+'a';
            if(uniqueChars.count(ch)){
                ans+=ch;
            }
        }
        return ans;

    }
};
