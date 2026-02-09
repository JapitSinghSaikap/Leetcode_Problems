class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = 0;
        int n2 = 0;
        int c1 = 0;
        int c2 = 0;
        int n = nums.size();
        for(int it : nums){
           if(c1==0 && it!=n2){
              c1 = 1;
              n1 = it;
           }
           else if(c2==0 && it!=n1){
              c2 = 1;
              n2 = it;
           }
           else if(n1==it) c1++;
           else if(n2==it) c2++;
           else{
             c1--;
             c2--;
           }
        } 
        c1 = 0;
        c2 = 0;
        for(int it : nums){
            if(it==n1) c1++;
            else if(it==n2) c2++;
        }
        vector<int>ans;
        if(c1>(n/3)) ans.push_back(n1);
        if(c2>(n/3)) ans.push_back(n2);
        return ans;
    }
};