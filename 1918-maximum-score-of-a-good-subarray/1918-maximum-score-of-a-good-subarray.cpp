class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int l=k;
        int r=k;
        int mini=nums[k];
        int sum=nums[k];
        while(l>0 || r<n-1){
            int a=0;
            int b=0;
            if(l>0){
                a=nums[l-1];
            }
            else if(l<=0){
                a=0;
            }
            if(r<n-1){
                b=nums[r+1];
            }
            else if(r>=n){
                b=0;
            }
            if(a>=b){
                l--;
                mini=min(mini,nums[l]);
            }
            else if(b>a){
                r++;
                mini=min(mini,nums[r]);
            }
            int u=mini*(r-l+1);
            sum=max(sum,u);
        }
        return sum;
    }
};