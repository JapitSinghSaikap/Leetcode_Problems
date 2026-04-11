class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // for(auto it: intervals){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        vector<vector<int>> merged;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= prev[1]) {
                // Merge overlapping intervals
                prev[1] = max(prev[1], intervals[i][1]);
            } else {
                merged.push_back(prev);
                //agr overlap na ho then make the new prev for ex [1,6] [8,10]  
                // 8<=6 Nhi
                //push [1,6] to merged and new prev is 
                //prev 
                prev = intervals[i];
            }
        }

        merged.push_back(prev);
        return merged;
    }
};