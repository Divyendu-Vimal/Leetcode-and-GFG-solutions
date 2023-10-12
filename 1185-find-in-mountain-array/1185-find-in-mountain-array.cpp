/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bsss(int l,int h,MountainArray &mountainArr,int n,int t){
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mountainArr.get(mid)==t){
                return mid;
            }
            else if(mountainArr.get(mid)>t){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return -1;
    }
    int bss(int l,int h,MountainArray &mountainArr,int n,int t){
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mountainArr.get(mid)==t){
                return mid;
            }
            else if(mountainArr.get(mid)>t){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
    int bs(int l,int h,MountainArray &mountainArr,int n){
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mid>0 && mountainArr.get(mid)>mountainArr.get(mid-1)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int k=bs(0,n-1,mountainArr,n);
        int ele=mountainArr.get(k);
        if(target==ele){
            return k;
        }
        int b=bss(0,k,mountainArr,n,target);
        if(b!=-1){
            return b;
        }
        //return b;
        int b1=bsss(k+1,n-1,mountainArr,n,target);
        //return b1;
        if(b1!=-1){
            return b1;
        }
        return -1;
    }
};