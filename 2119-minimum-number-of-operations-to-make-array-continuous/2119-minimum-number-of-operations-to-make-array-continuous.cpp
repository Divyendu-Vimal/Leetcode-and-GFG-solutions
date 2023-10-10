class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        vector<int>v;
        for(auto &it:st){
            v.push_back(it);
        }
        sort(v.begin(),v.end());
        
        int mini=INT_MAX;
        for(int i=0;i<v.size();i++){
            int a=v[i]+n-1;
            auto p=upper_bound(v.begin(),v.end(),a);
            int o=p-v.begin();
            int h=o-i;
            int k=n-h;
            mini=min(mini,k);
        }
        return mini;
    }
};