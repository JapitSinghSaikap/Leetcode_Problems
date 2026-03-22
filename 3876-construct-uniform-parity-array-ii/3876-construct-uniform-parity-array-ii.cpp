class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddcount=0;
        int evencount=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                evencount++;
            }
            else oddcount++;
        }
        if(nums1.size()==evencount||nums1.size()==oddcount){
            return true;
        }
        int mineven=INT_MAX;
        int minodd=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                mineven=min(mineven,nums1[i]);
            }
            else minodd=min(minodd,nums1[i]);
        }
        return mineven-minodd>0?true:false;
    }
};