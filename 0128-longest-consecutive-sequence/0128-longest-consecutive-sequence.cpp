class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if (nums.empty()) return 0;

        sort(nums.begin(), nums.end()); 
        int maxlen = 1, len = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
             continue; 
            if (nums[i] == nums[i - 1] + 1) {
                len++;
            } else {
                maxlen = max(maxlen, len);
                len = 1;
            }
        }
        return max(maxlen, len);
    }
};


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n=nums.size();
//         if(n==0){
//             return 0;
//         }

//         unordered_map<int,bool>mpp;
//         int len=1; //to check for the seq
//         int maxlen=1;//to check for the max seq
        
//         for(auto x: nums){
//             mpp[x]=false;
//         }
        
//         for(int i=0;i<n;i++){
//             //next number konsa hona chahiye seq mein
//             int nxt=nums[i]+1;

//             while(mpp.find(nxt)!=mpp.end() && mpp[nxt]==false){
//                 //ki yeh milgya hai
//                 mpp[nxt]=true;
//                 len++;
//                 nxt++;//ab agla check kteinge
//         }
//         int prev=nums[i]-1;
//         while(mpp.find(prev)!=mpp.end() && mpp[prev]==false){
//                 mpp[prev]=true;
//                 len++;
//                 prev--;
//             }
//             maxlen=max(maxlen,len);
//             len=1;
//         }
//         return maxlen;
//     }
// };