class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);
        for(auto& x:mp){
            sort(x.second.begin(),x.second.end());
        }
        int ans=INT_MAX;
        for(auto& x:mp){
            if(x.second.size()<3) continue;
            for(int i=0;i<x.second.size()-2;i++){
                ans=min(ans,abs(x.second[i]-x.second[i+1])+abs(x.second[i]-x.second[i+2])+abs(x.second[i+2]-x.second[i+1]));
            }
        }
        return ans==INT_MAX? -1:ans;
    }
};