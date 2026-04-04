class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int max_count = 0;
        for(int it : st){
           if(!st.count(it-1)){
                int el = it;
                int curr_count = 0;
                while(st.count(el)){
                    curr_count++;
                    el++;
                }
                max_count = max(max_count,curr_count);
           }
        }
        return max_count;
        
    }
};