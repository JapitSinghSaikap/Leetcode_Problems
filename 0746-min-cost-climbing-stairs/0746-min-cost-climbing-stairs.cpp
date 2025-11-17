// class Solution {
// public:
//     int costt(int idx,vector<int>& arr,vector<int>& dp){
//         if(idx<=1) return 0;

//         if(dp[idx]!=-1) return dp[idx];

//         int one = arr[idx-1]+costt(idx-1,arr,dp);
//         int two =arr[idx-2]+costt(idx-2,arr,dp);
//         return dp[idx] = min(one,two);
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int> dp(n+1,-1);
//         return costt(n,cost,dp);
//     }
// };

class Solution {
public:
    int costt(int idx,vector<int>& arr,vector<int>& dp){
        int n=arr.size();
        if(idx>=n) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int one = costt(idx+1,arr,dp);
        int two =costt(idx+2,arr,dp);
        return dp[idx] = min(one,two)+arr[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        //either 0 or 1 se start hoga
        return min(costt(0, cost, dp), costt(1, cost, dp));
    }
};