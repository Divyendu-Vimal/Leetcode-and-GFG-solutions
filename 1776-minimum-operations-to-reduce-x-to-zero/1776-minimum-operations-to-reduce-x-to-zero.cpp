class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        long long int s=sum-x;
        if(s<0){
            return -1;
        }
        if(s==0){
            return n;
        }
        int i=0;
        int j=0;
        long long int nsum=0;
        int mini=INT_MAX;
        while(i<n){
            nsum=nsum+nums[i];
            while(nsum>s && j<=i){
                nsum=nsum-nums[j];
                j++;
            }
            if(s==nsum){
                mini=min((n-(i-j)-1),mini);
            }
            i++;
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};