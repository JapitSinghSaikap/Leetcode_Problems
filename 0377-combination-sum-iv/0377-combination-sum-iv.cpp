class Solution {
public:
vector<int>dp;
int getcount(vector<int>& nums,long long sum,int target,bool isstart){
    if(sum>target){
        return 0;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    if(sum==target){
        return 1;
    }
    int count=0;
    for(int i=0;i<nums.size();i++){
        count+=getcount(nums,sum+nums[i],target,false);
    }
    return dp[sum]=count;
}
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(10001,-1);
        return getcount(nums,0,target,true);
    }
};