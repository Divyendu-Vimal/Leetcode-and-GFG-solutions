class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int n=piles.size();
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        while(k!=0){
            int y=pq.top();
            pq.pop();
            int u=ceil(float(y)/(2*1.0));
            pq.push(u);
            k--;
        }
        int sum=0;
        while(!pq.empty()){
            sum=sum+pq.top();
            pq.pop();
        }
        return sum;
    }
};