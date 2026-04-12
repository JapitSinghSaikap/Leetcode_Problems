class Solution {
public:
    bool prime(int n){
        if(n<2) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ops=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(prime(nums[i])){}
                else{
                   while(!prime(nums[i])){
                       nums[i]+=1;
                       ops+=1;
                   }
                }
            }else{
                if(!prime(nums[i])){}
                else{
                    while(prime(nums[i])){
                        nums[i]+=1;
                        ops+=1;
                    }   
                }
            }
        }

        return ops;
    }
};