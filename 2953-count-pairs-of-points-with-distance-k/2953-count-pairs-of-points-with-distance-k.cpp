class Solution {
public:
    int countPairs(vector<vector<int>>& v, int k) {
        int ans=0;
        int n=v.size();
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                int x=j^v[i][0];
                int y=(k-j)^v[i][1];
                if(mp.find({x,y})!=mp.end()){
                    int p=mp[{x,y}];
                    ans=ans+p;
                }
            }
            mp[{v[i][0],v[i][1]}]++;
        }
        return ans;
    }
};