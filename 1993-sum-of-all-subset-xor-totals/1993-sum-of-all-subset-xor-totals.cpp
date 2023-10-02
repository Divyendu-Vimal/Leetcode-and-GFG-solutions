class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int t=0;
        for(int i=1;i<(1<<n);i++){
            int x=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    x=x^nums[j];
                }
            }
            t=t+x;
        }
        return t;
    }
};