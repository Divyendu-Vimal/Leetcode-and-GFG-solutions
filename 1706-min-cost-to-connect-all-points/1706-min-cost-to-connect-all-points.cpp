class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        map<int,vector<pair<int,int>>>adj;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                adj[i].push_back({j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
                adj[j].push_back({i,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
            }
        }
        vector<int>vis(n,0);
        int sum=0;
        pq.push({0,0});
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            int dist=p.first;
            int node=p.second;
            if(vis[node]==0){
                vis[node]=1;
                sum=sum+dist;
                for(auto &nod:adj[node]){
                    int no=nod.first;
                    int dis=nod.second;
                    if(vis[no]==0){
                        pq.push({dis,no}); 
                    }
                }
            }
        }
        return sum;
    }
};