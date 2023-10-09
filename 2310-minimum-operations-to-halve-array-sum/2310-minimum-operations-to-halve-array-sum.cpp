class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n=nums.size();
        double sum=0;
        priority_queue<double>pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]*1.0);
            sum=sum+nums[i];
        }
        double y=sum/2;
        int ct=0;
        while(sum>y){
            double u=pq.top();
            pq.pop();
            double k=u/2;
            sum=sum-k;
            ct++;
            pq.push(k);
        }
        return ct;
    }
};