class Solution {
public:
    int check(vector<int>&v,int d,int mid,int n){
        int ct=0;
        int sum=0;
        int i=0;
        while(i<n){
            sum=sum+v[i];
            if(sum>mid){
                sum=v[i];
                ct++;
            }
            i++;
        }
        if(sum>mid){
            ct=ct+2;
        }
        else{
            ct=ct+1;
        }
        if(ct<=d){
            return 1;
        }
        else{
            return 0;
        }
    }
    int bs(vector<int>&v,int d,int l,int h,int n){
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(v,d,mid,n)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int maxi=*max_element(nums.begin(),nums.end());
        int ans=bs(nums,k,maxi,sum,n);
        return ans;
    }
};