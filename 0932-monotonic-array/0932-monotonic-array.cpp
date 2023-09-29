class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int>v=nums;
        reverse(v.begin(),v.end());
        if(is_sorted(v.begin(),v.end()) || is_sorted(nums.begin(),nums.end())){
            return true;
        }
        return false;
    }
};