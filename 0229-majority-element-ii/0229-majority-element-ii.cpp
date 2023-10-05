class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        int k=n/3;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto &m:mp){
            if(m.second>k){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};