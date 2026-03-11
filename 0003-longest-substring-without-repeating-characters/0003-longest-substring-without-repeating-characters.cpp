class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> mpp(256, -1);
       int l,r,len,maxlen=0;
       l=0;
       r=0;
       int n=s.size();
       while(r<n){
            if(mpp[s[r]]!=-1){//this means it exists
                if(mpp[s[r]]>=l){
                    l=mpp[s[r]]+1;//shift to the next index of occurence
                }
            }
            len=r-l+1;
            maxlen=max(maxlen,len);
            mpp[s[r]]=r;
            r++;
       }

       return maxlen;
    }
};