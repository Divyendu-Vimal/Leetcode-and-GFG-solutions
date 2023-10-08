class Solution {
public:
    int dp[501][501];
    int findprod(vector<int>&nums1,vector<int>&nums2,int n1,int n2){
        //int result1=0;
        //int maxi=0;
        if(n1<0 || n2<0){
            return -1000000000;
        }
        if(dp[n1][n2]!=-1){
            return dp[n1][n2];
        }
        int result1=(nums1[n1]*nums2[n2]);
        int take1=result1+findprod(nums1,nums2,n1-1,n2-1);
        int take2=findprod(nums1,nums2,n1,n2-1);
        int take3=findprod(nums1,nums2,n1-1,n2);
        return dp[n1][n2]=max({result1,take1,take2,take3});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        memset(dp,-1,sizeof(dp));
        int ans=findprod(nums1,nums2,n1-1,n2-1);
        return ans;
    }
};