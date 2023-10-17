class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        int ct=0;
        queue<int>q;
        vector<int>vis(n,-1);
        vector<int>v(n,-1);
        for(int i=0;i<n;i++){
            if(l[i]!=-1){
                v[l[i]]=1;
            }
            if(r[i]!=-1){
                v[r[i]]=1;
            }
        }
        int k=0;
        for(int i=0;i<n;i++){
            if(v[i]!=1){
                k=i;
                ct++;
            }
        }
        //cout<<ct;
        if(ct!=1){
            return false;
        }
        q.push(k);
        while(!q.empty()){
            int p=q.front();
            vis[p]=vis[p]+1;
            if(vis[p]>0){
                return false;
            }
            q.pop();
            if(l[p]!=-1){
                q.push(l[p]);
            }
            if(r[p]!=-1){
                q.push(r[p]);
            }
        }
        /*for(int i=0;i<n;i++){
            if(vis[i]==-1 && (l[i]!=-1 || r[i]!=-1)){
                ct++;
                q.push(i);
                //vis[i]=1;
            }
            while(!q.empty()){
                int p=q.front();
                vis[p]=vis[p]+1;
                if(vis[p]>0){
                    return false;
                }
                q.pop();
                if(l[p]!=-1){
                    q.push(l[p]);
                }
                if(r[p]!=-1){
                    q.push(r[p]);
                }
            }
        }*/
        int f=0;
        for(int i=0;i<n;i++){
            if(vis[i]!=0){
                f=1;
            }
        }
        if(f==1){
            return false;
        }
        return true;
    }
};