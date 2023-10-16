class Solution {
public:
    vector<int> getRow(int r) {
        if(r==0){
            return {1};
        }
        if(r==1){
            return {1,1};
        }
        vector<int>v;
        v.push_back(1);
        v.push_back(1);
        for(int i=2;i<=r;i++){
            vector<int>v1;
            v1.push_back(1);
            for(int j=0;j<v.size()-1;j++){
                int k=v[j]+v[j+1];
                v1.push_back(k);
            }
            v1.push_back(1);
            v=v1;
        }
        return v;

    }
};