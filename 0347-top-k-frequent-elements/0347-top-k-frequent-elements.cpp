// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int> mpp;
//         for (auto num : nums) {
//             ++mpp[num];
//         }

//         vector<int> ans;
//         while(ans.size() < k){
//             int maxFreq = 0;
//             int maxFreqNum;
//             for(auto it: mpp){
//                 if(it.second > maxFreq){
//                     maxFreq = it.second;
//                     maxFreqNum = it.first;
//                 }
//             }
//             ans.push_back(maxFreqNum);
//             mpp.erase(maxFreqNum);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>mpp;
        for(int i : nums){
            mpp[i]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }

        vector<int>ans(k,0);
        int i=0;
        
       
        while(i < k){
            ans[i] = pq.top().second;
            pq.pop();
            i++;
        }
        // while(i<k){
        //     cout<<pq.top().first;
        //     // cout<<pq.top().second;
        //     ans[i]=pq.top().second;
        //     i++;
        //     pq.pop();
        // }
        return ans;
        // return vector<int>{};
       
    }
};