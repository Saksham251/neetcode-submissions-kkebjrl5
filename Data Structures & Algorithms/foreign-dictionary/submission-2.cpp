class Solution {
public:
    vector<int> topoSort(int V,vector<int> adj[]){
        vector<int> indegree(V,0);
        queue<int> q;
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);  
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node); 
            for(auto it:adj[node])
            { 
                indegree[it]--; 
                if(indegree[it]==0){ 
                    q.push(it);
                } 
            }
        }
        return topo;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        
        unordered_set<char> uniqueChars;
        for(int i = 0;i<words.size();i++){
            for(auto it:words[i]){
                uniqueChars.insert(it);
            }
        }
        int m = uniqueChars.size();
        vector<int> adj[26];
        // build graph
        for(int i = 0; i < words.size() - 1; i++) {
            string str1 = words[i];
            string str2 = words[i + 1];

            // invalid case
            if(str1.length() > str2.length() && 
               str1.substr(0, str2.length()) == str2) {
                return "";
            }

            int mini = min(str1.length(), str2.length());
            for(int j = 0; j < mini; j++) {
                if(str1[j] != str2[j]) {
                    adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(26, adj);
        // cycle check
        if(topo.size() < uniqueChars.size()) return "";
        string ans = "";
        for(auto it : topo) {
            char ch = it + 'a';
            if(uniqueChars.count(ch)) {
                ans += ch;
            }
        }

        return ans;
    }
};
