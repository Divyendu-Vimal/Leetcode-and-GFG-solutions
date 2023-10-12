class Solution {
public:
    int bs(int l,int h,vector<int>&arr){
        int ans=0;
        if(arr[0]>arr[1]){
            return 0;
        }
        if(arr[arr.size()-1]>arr[arr.size()-2]){
            return arr.size()-1;
        }
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mid>0 && arr[mid]>arr[mid-1] && (mid<arr.size()-1) && arr[mid]>arr[mid+1]){
                ans=mid;
                return ans;
            }
            else if(arr[mid]<arr[mid+1]){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int k=bs(0,n-1,arr);
        return k;
    }
};