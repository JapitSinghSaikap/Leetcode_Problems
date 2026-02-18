class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        //to check for duplicates ki hai ya nhi
        int n=arr.size();
        unordered_map<int,int> mpp;
        long long currSum = 0;
        long long maxSum = 0;
        int l = 0;

        for(int r=0;r<n;r++) {
            mpp[arr[r]]++;
            currSum+=arr[r];
            if(r-l+1>k) {
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0) mpp.erase(arr[l]);
                currSum-=arr[l];
                l++;
            }
            if(r-l+1==k && mpp.size() == k) {
                maxSum=max(maxSum,currSum);
            }
        }

        return maxSum;
    }
};
