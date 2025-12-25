class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        long long dec = 0,i=0,ans=0;
        while(k--){
            //ek ek krke pick kr rhe bs
            long long val = arr[i]-dec;
            i++;
            dec++;
            if(val<=0) break;
            ans+=val;
        }
        return ans;
    }
};