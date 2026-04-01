class Solution {
public:
    int sumMST(vector<vector<pair<int,int>>> &adj,int V){
        int sum=0;
        vector<bool> inMST(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0}); // weight,node

        while(!pq.empty()){
            auto [weight,node] = pq.top(); 
            pq.pop();
            if(inMST[node]==true){
                continue;
            }
            inMST[node] = true;
            sum+=weight;
            for(auto it:adj[node]){
                int neighbour = it.second;
                int edgeW = it.first;
                
                if(!inMST[neighbour]){
                    pq.push({edgeW,neighbour});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0;i<V;i++){
            for(int j = i+1;j<V;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
        }
        return sumMST(adj,V);
    }
};
