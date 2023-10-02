class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        //Finding largest sequence of maxi in array
        int ct=0;
        int ma=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]==maxi && nums[i]==nums[i+1]){
                ct++;
            }
            else{
                ma=max(ma,ct+1);
                ct=0;
            }
        }
        ma=max(ma,ct+1);
        return ma;
    }
};