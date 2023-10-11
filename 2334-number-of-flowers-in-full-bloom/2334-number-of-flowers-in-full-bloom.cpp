class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>ans;
        int n=flowers.size();
        int m=people.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[flowers[i][0]]++;
            mp[flowers[i][1]+1]--;
        }
        int ct=0;
        for(auto &it:mp){
            mp[it.first]=it.second+ct;
            ct=mp[it.first];
        }
        for(int i=0;i<m;i++){
            int u=people[i];
            auto it=mp.upper_bound(u);
            if(it==mp.begin()){
                ans.push_back(0);
            }
            else{
                --it;
                ans.push_back((*it).second);
            }
        }
        return ans;
    }
};