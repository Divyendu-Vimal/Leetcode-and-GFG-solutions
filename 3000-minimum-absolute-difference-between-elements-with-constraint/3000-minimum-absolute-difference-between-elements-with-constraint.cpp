class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int>s;
        int n=nums.size();
        for(int i=x;i<n;i++){
            s.insert(nums[i]);
        }
        int mini=INT_MAX;
        for(int i=0;i<n-x;i++){
            int l=nums[i];
            auto it=s.upper_bound(l);
            int y=INT_MAX;
            int y1=INT_MAX;
            if(it!=s.end()){
                cout<<"ffn"<<endl;
                y=abs(l-(*it));
            }
            if(it!=s.begin()){
                cout<<"yy"<<endl;
                y1=abs(l-(*prev(it)));
                cout<<y1<<endl;
            }
            mini=min({mini,y,y1});
            auto it1=s.find(nums[i+x]);
            s.erase(it1);
        }
        return mini;
    }
};