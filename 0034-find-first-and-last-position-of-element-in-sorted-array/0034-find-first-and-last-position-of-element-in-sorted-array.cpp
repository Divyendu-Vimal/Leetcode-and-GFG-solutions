class Solution {
public:
    int firstoccur(vector<int>&nums,int t,int n){
        int l=0;
        int h=n-1;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==t){
                ans=mid;
                h=mid-1;
            }
            else if(nums[mid]<t){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
    int lastoccur(vector<int>&nums,int t,int n){
        int l=0;
        int h=n-1;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==t){
                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]<t){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int y=firstoccur(nums,target,n);
        int yy=lastoccur(nums,target,n);
        return {y,yy};
    }
};