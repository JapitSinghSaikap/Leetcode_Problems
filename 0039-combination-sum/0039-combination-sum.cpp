class Solution {
public:
    void check(int ind,int target,vector<int>& nums,vector<vector<int>>& ans,vector<int>& arr){
        int n=nums.size();
        if(ind==n){
            if(target==0){
                ans.push_back(arr);
            }
            return;
        }

        if(nums[ind]<=target){
            arr.push_back(nums[ind]);
            check(ind,target-nums[ind],nums,ans,arr);
            arr.pop_back();
        }
        check(ind+1,target,nums,ans,arr);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        check(0,target,candidates,ans,arr);
        return ans;
    }
};