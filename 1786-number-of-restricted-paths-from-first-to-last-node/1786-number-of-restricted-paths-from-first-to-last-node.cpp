class Solution {
public:
    const int mod=1e9+7;
    int dp[20001];
    int dfs(vector<vector<pair<int, int>>>&adj,int i,int n,vector<int>&dist){
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int y=0;
        for(auto it:adj[i]){
            if(dist[it.first]<dist[i]){
                y=(y%mod+dfs(adj,it.first,n,dist)%mod)%mod;
            }
        }
        return dp[i]=y;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        pq.push({0,n});
        dist[n]=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int d=p.first;
            int no=p.second;
            for(auto it:adj[no]){
                int node=it.first;
                int dis=it.second;
                if(dist[node]>dis+dist[no]){
                    dist[node]=dis+dist[no];
                    pq.push({dist[node],node});
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return dfs(adj,1,n,dist);
    }
};