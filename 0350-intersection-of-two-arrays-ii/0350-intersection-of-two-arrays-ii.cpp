class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        int h1[1001]={0};
        int h2[1001]={0};
        for(int i=0;i<n;i++){
            h1[nums1[i]]++;
        }
        for(int i=0;i<m;i++){
            h2[nums2[i]]++;
        }
        for(int i=0;i<n;i++){
            if(h2[nums1[i]]>0){
                ans.push_back(nums1[i]);
                h2[nums1[i]]--;
            }
        }
        return ans;
    }
};