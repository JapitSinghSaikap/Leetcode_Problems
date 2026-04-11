class Solution {
public:
    int check(int index,vector<int>& nums,vector<int>& dp){
        int n=nums.size();
        //zero contribute hoga yha pe
        if(index>=n){
            return 0;
        }

        if(dp[index]!=-1) return dp[index];

        int pick=nums[index]+check(index+2,nums,dp);
        int notpick = check(index+1,nums,dp);

        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return check(0,nums,dp);
    }
};

