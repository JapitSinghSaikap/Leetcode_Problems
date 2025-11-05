class Solution {
public:
    vector<int>dp;
    int solve(int index, vector<int>&cost, int n){
          if (index > n) return 1e9;
          if(index==n) return cost[index-1];
          if(dp[index]!=-1) return dp[index];
          int ans = index-1>=0 ? cost[index-1]:0;
          int firstStep = 1 + solve(index+1,cost,n);
          int secondStep = 4 + solve(index+2,cost,n);
          int thirdStep = 9 + solve(index+3,cost,n);
          return dp[index] = ans + min(firstStep,min(secondStep,thirdStep));

    }
    int climbStairs(int n, vector<int>& costs) {
        //   cout<<costs[0];
          dp.resize(n+1,-1);
          return solve(0,costs,n);
    }
};