class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<pair<int,int>>q;
        set<pair<int,int>>vis;
        for(int i=0;i<n;i++){
            q.push({i,1<<i});
            vis.insert({i,1<<i});
        }
        int ct=0;
        int y=pow(2,n)-1;
        while(!q.empty()){
            int k=q.size();
            ct++;
            for(int i=0;i<k;i++){
                auto p=q.front();
                int node=p.first;
                int mask=p.second;
                q.pop();
                for(auto &i:graph[node]){
                    int nmask=mask | (1<<i);
                    if(nmask==y){
                        return ct;
                    }
                    if(vis.find({i,nmask})==vis.end()){
                        vis.insert({i,nmask});
                        q.push({i,nmask});
                    }
                }
            }
        }
        return 0;
    }
};