class Solution {
public:
    int check(int index,vector<int>& arr, int target,vector<vector<int>>& dp){
        int n=arr.size();
        if(index==n-1) {
            if(target%arr[n-1]==0) return target/arr[n-1];
            return 1e9;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int notpick=check(index+1,arr,target,dp);
        int pick=INT_MAX;
        if(target>=arr[index]){
            pick=1+check(index,arr,target-arr[index],dp);
        }

        return dp[index][target]=min(pick,notpick);
    }
    int coinChange(vector<int>& arr, int target){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans=check(0,arr,target,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};

















































// class Solution {
// public:
//     int check(int n,vector<int>& arr,int target,vector<vector<int>>& dp){
//         if(n==0){
//             if(target%arr[n]==0) return target/arr[n];
//             else return 1e9;//itna bdha number do taki wo consider hi na ho
//         }
//         if (dp[n][target] != -1) return dp[n][target];
//         int nottake=check(n-1,arr,target,dp);
//         int take=INT_MAX;
//         //take only when target is greater than the current index value
//         if(target>=arr[n]){
//             take=1+check(n,arr,target-arr[n],dp);
//         }

//         return dp[n][target] =  min(take,nottake);
//     }
//     int coinChange(vector<int>& arr, int target) {
//         int n=arr.size();
//         vector<vector<int>> dp(n,vector<int>(target+1,-1));
//         int ans=check(n-1,arr,target,dp);
//         if(ans>=1e9) return -1;
//         return ans;
//     }
// };



// // class Solution {
// // public:
// //     int coinChange(vector<int>& coins, int amount) {
// //         vector<int> minCoins(amount + 1, amount + 1);
// //         minCoins[0] = 0;

// //         for (int i = 1; i <= amount; i++) {
// //             for (int j = 0; j < coins.size(); j++) {
// //                 if (i - coins[j] >= 0) {
// //                     minCoins[i] = min(minCoins[i], 1 + minCoins[i - coins[j]]);
// //                 }
// //             }
// //         }

// //         return minCoins[amount] != amount + 1 ? minCoins[amount] : -1;        
// //     }
// // };

