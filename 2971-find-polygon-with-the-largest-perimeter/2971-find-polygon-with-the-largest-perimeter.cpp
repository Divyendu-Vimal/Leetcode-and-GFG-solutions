using ll=long long;
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll sum=0;
        int n=nums.size();
        ll maxi=-1;
        for(int i=0;i<nums.size()-1;i++){
            sum=sum+nums[i];
            if(i+1<n && sum>nums[i+1]){
                maxi=max(maxi,sum+nums[i+1]);
            }
        }
        return maxi;
    }
};