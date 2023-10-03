class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto &m:mp){
            ans=ans+(m.second*(m.second-1))/2;
        }
        return ans;
    }
};