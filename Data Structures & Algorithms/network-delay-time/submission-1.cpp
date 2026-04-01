class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1,INT_MAX);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d,node]= pq.top(); 
            pq.pop();
            for(auto it:adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                if(dist[adjNode]>d+edgeW){
                    dist[adjNode]=d+edgeW;
                    pq.push({d+edgeW,adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1;i<=n;i++ ){
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans==INT_MIN?-1:ans;
    }
};
