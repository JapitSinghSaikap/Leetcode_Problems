class Solution {
public:
    int f(int ind,int time,vector<int>& arr,vector<vector<int>>& dp){
        if(ind==arr.size()) return 0;
        if(dp[ind][time]!=-1) return dp[ind][time];

        int take=arr[ind]*time+f(ind+1,time+1,arr,dp);
        int nottake=f(ind+1,time,arr,dp);


        return dp[ind][time]=max(take,nottake);
    }
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,1,arr,dp);
    }
};


// class Solution {
// public:
//     int maxSatisfaction(vector<int>& arr) {
//         sort(arr.begin(),arr.end());
//         int n=arr.size();
//         int curr=0;
//         int maxx=0;
//         for(int i=n-1;i>=0;i--){
//             curr+=arr[i];

            
//             if(curr<0) break;
//             maxx+=curr;
//         }

//         return maxx;
//     }
// };