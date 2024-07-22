class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n=heights.size();
    vector<string>ans;
    map<int,string,greater<int>>mp;
    for(int i=0;i<n;i++){
        mp[heights[i]]=names[i];
    }
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;  
    }
};