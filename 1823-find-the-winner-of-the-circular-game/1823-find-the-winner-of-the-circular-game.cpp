class Solution {
public:
    void findwin(int i,vector<int>&v,int &ans,int k){
        if(v.size()==1){
            ans=v[0];
            return;
        }
        i=(i+k-1)%v.size();
        v.erase(v.begin()+i);
        findwin(i,v,ans,k);
    }
    int findTheWinner(int n, int k) {
        vector<int>v(n);
        for(int i=1;i<=n;i++){
            v[i-1]=i;
        }
        int ind=0;
        int ans=-1;
        findwin(0,v,ans,k);
        return ans;
    }
};