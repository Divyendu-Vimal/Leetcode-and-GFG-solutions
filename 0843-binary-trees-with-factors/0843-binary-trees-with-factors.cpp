class Solution {
public:
const int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            return 1;
        }
        sort(arr.begin(),arr.end());
        map<long long int,long long int>mp;
        mp[arr[0]]=1;
        for(int i=1;i<n;i++){
            mp[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int u=arr[i]/arr[j];
                    if(mp.find(u)!=mp.end()){
                        long long int y=((1LL*mp[u]%mod)*(1LL*mp[arr[j]]%mod));
                        mp[arr[i]]=((mp[arr[i]]%mod)+(y%mod))%mod;
                    }
                }
            }
        }
        long long int sum=0;
        for(auto it:mp){
            sum=((sum%mod)+(it.second%mod))%mod;
        }
        return sum;
    }
};
//2  4,2,2  10,5,2  10,2,5   20,5,4  20,4,5  20,10,2-2  20,2,10  