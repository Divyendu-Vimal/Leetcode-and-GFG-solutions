class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int>pq;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto &it:mp){
            pq.push(it.second);
        }
        while(pq.size()>1){
            int y=pq.top();
            pq.pop();
            int z=pq.top();
            pq.pop();
            y--;
            z--;
            if(y!=0){
                pq.push(y);
            }
            if(z!=0){
                pq.push(z);
            }
        }
        if(pq.empty()){
            return 0;
        }
        else{
            return pq.top(); 
        }
    }
};