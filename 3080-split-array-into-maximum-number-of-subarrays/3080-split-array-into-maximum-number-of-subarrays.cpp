class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n=nums.size();
        int a=nums[0];
        for(int i=0;i<n;i++){
            a=a&nums[i];
        }
        if(a!=0){
            return 1;
        }
        else{
            int i=0;
            int ct=0;
            int k=nums[i];
            while(i<n){
                k=k&nums[i];
                if(k==0){
                    ct++;
                    i++;
                    if(i<n){
                        k=nums[i];
                    }
                }
                else{
                    i++;
                }
            }
            return ct;
        }
    }
};