class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            int ct=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    ct++;
                }
            }
            pq.push({ct,i});
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            auto p=pq.top();
            ans.push_back(p.second);
            pq.pop();
        }
        return ans;
    }
};