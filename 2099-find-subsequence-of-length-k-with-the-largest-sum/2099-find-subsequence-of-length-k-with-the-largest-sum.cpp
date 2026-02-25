#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
            
            if(pq.size() > k)
                pq.pop();   // remove smallest
        }
        
        // Store selected elements
        vector<pair<int,int>> temp;
        
        while(!pq.empty()){
            temp.push_back(pq.top());
            pq.pop();
        }
        
        // Sort by original index to maintain order
        sort(temp.begin(), temp.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });
        
        vector<int> res;
        for(auto &p : temp)
            res.push_back(p.first);
        
        return res;
    }
};