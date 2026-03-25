class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=0;
        int maxlen = 0;
        unordered_map<int,int> mpp;
        while(r<n){
            mpp[arr[r]]++;
            if(mpp.size()>2){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0) mpp.erase(arr[l]);
                l++;
            }
            r++;
            maxlen = max(maxlen,r-l+1);
        }

        return maxlen-1;
    }
};