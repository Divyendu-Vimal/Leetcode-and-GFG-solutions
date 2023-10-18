class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& time) {
        vector<int>adj[n];
        int m=r.size();
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            adj[r[i][0]-1].push_back(r[i][1]-1);
            mp[r[i][1]-1]++;
        }
        queue<int>q;
        int maxi=0;
        vector<int>maxTime(n,0);
        for(int i=0;i<n;i++){
            if(mp[i]==0){
                q.push(i);
                maxTime[i]=time[i];
            }
        }
        while(!q.empty()){
            int y=q.front();
            q.pop();
            for(auto it:adj[y]){
                mp[it]--;
                if(mp[it]==0){
                    q.push(it);
                }
                maxTime[it]=max(maxTime[it],maxTime[y]+time[it]);
            }
        }
        return *max_element(maxTime.begin(),maxTime.end());
    }
};