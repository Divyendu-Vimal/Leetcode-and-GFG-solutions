class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
            }
            int k=nums[i]+maxi;
            v.push_back(k);
        }
        vector<long long int>ans(n);
        ans[0]=v[0];
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+v[i];
        }
        return ans;
    }
};