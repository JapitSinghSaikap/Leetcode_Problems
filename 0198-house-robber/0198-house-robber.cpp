// class Solution {
// public:
//     int recur(vector<int> &nums,vector<int> &dp , int n ){
//         if(n==0) return nums[0] ; 
//         if(n<0) return 0;

//         if(dp[n] != -1 ) return dp[n];


//         int take = nums[n] + recur(nums, dp , n-2);
//         int not_take = recur(nums, dp , n-1);


//         int maxi = max(take , not_take);

//         return dp[n] = maxi ;
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size(); 
//         // vector<int> dp (n, -1);
//         // return recur(nums, dp , n-1);
//         int prev1 = nums[0] , prev2 = 0 ;
//         for(int i = 1 ; i < n ; i++){
//             int take = prev2 + nums[i]; 
//             int notake = prev1;
//             int curr = max(take,notake);
//             prev2 = prev1;
//             prev1 = curr;
//         }  
//         return prev1;
//     }
// };


// class Solution {
// public:
//     int f(int ind,vector<int>& arr,vector<int>& dp){
//         if(ind==0) return arr[ind];
//         if(ind<0) return 0;
//         if(dp[ind]!=-1) return dp[ind];
//         int pick=arr[ind]+f(ind-2,arr,dp);
//         int notpick=f(ind-1,arr,dp);
//         return dp[ind]=max(pick,notpick);
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n,-1);
        
//         return f(n-1,nums,dp);
//     }
// };


class Solution {
public:
    int f(int ind,vector<int>& arr,vector<int>& dp){
        int n=arr.size();
        if(ind>=n) return 0;
        // if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=arr[ind]+f(ind+2,arr,dp);
        int notpick=f(ind+1,arr,dp);
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        
        return f(0,nums,dp);
    }
};