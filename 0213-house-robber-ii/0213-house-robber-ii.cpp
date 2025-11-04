class Solution {
public:
    int rob(vector<int>& nums) {
        //space optimised

        int n=nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

       
        int prev=nums[0];
        int prev2=0;
        //last wala skip kr rha hun ismein
        for(int i=1;i<n-1;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int nottake = 0+prev;
            int curi=max(take,nottake);
            prev2=prev;
            prev=curi;
        }
        int prev3=nums[1];
        int prev4=0;
        for(int i=2;i<n;i++){
            int take1=nums[i];
            if(i>2) take1+=prev4;
            int nottake1=0+prev3;
            int curi1=max(take1,nottake1);
            prev4=prev3;
            prev3=curi1;
        }

        return max(prev,prev3);
    }
};