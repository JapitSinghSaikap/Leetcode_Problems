class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> indx;
        for(int i=0;i<n;i++){
            if(nums[i]==1 || nums[i]==2){
                indx.push_back({i,nums[i]});
            }
        }
        int minn=INT_MAX;
        //brute force check every pair
         for(int i=0;i<indx.size();i++){
            for(int j=i+1;j<indx.size();j++){
                if(indx[i].second != indx[j].second){
                    minn = min(minn, abs(indx[i].first - indx[j].first));
                }
            }
        }

        if(minn == INT_MAX) return -1;
        return minn;
    }
};