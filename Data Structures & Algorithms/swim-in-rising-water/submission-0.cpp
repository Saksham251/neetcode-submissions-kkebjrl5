class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    int n;
    bool dfsPathPossible(vector<vector<int>>& grid,vector<vector<bool>> &visited,int i,int j,int t){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]>t || visited[i][j]==true){
            return false;
        }
        visited[i][j]=true;
        if(i==n-1 && j==n-1){
            return true;
        }
        for(auto dir:directions){
            int i_ = dir[0]+i;
            int j_ = dir[1]+j;
            if(dfsPathPossible(grid,visited,i_,j_,t)){
                return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = grid[0][0];
        int r = n*n-1;
        int result = 0;
        while(l<=r){
            vector<vector<bool>> visited(n,vector<bool>(n,0));
            int mid = l+(r-l)/2;
            if(dfsPathPossible(grid,visited,0,0,mid)){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};
