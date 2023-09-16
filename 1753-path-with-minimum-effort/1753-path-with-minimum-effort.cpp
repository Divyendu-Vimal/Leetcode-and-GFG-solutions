class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=grid.size();
        int m=grid[0].size();
        int dir[]={-1,0,1,0};
        int djr[]={0,1,0,-1};
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 && c==m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int nr=r+dir[i];
                int nc=c+djr[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int ndiff=max(diff,abs(grid[r][c]-grid[nr][nc]));
                    if(ndiff<dist[nr][nc]){
                        dist[nr][nc]=ndiff;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};