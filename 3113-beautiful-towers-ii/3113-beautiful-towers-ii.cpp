class Solution {
public:
    vector<int> fun(vector<int>v,int n){
        stack<int>s;
        vector<int>pr;
        for(int i=0;i<n;i++){
            while(!s.empty() && v[i]<v[s.top()]){
                s.pop();
            }
            if(s.empty()){
                pr.push_back(-1);
            }
            else{
                pr.push_back(s.top());
            }
            s.push(i);
        }
        return pr;
    }
    long long maximumSumOfHeights(vector<int>& v) {
        int n=v.size();
        vector<int>pref=fun(v,n);
        /*for(int i=0;i<n;i++){
            cout<<pref[i]<<" ";
        }
        cout<<endl;*/
        vector<long long int>npref(n);
        for(int i=0;i<n;i++){
            if(pref[i]==-1){
                npref[i]=1LL*(i-pref[i])*1LL*v[i];
            }
            else{
                npref[i]=1LL*(i-pref[i])*1LL*v[i]+npref[pref[i]];
            }
        }
        /*for(int i=0;i<n;i++){
            cout<<npref[i]<<" ";
        }
        cout<<endl;*/
        reverse(v.begin(),v.end());
        vector<int>suff=fun(v,n);
        /*for(int i=0;i<n;i++){
            cout<<suff[i]<<" ";
        }
        cout<<endl;*/
        vector<long long int>nsuff(n);
        for(int i=0;i<n;i++){
            if(suff[i]==-1){
                nsuff[i]=1LL*(i-suff[i])*1LL*v[i];
            }
            else{
                nsuff[i]=1LL*(i-suff[i])*1LL*v[i]+nsuff[suff[i]];
            }
        }
        reverse(nsuff.begin(),nsuff.end());
        /*for(int i=0;i<n;i++){
            cout<<nsuff[i]<<" ";
        }
        cout<<endl;*/
        reverse(v.begin(),v.end());
        long long int maxi=0;
        long long int sum1=0;
        for(int i=0;i<n;i++){
            sum1=(npref[i]+nsuff[i]-v[i]);
            maxi=max(maxi,sum1);
        }
        return maxi;
    }
};