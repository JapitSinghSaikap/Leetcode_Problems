// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         // unordered_map<int,int> mpp;
//         vector<int> nge;
//         for(int i=0;i<nums1.size();i++){
//             // mpp[i]=nums[i];
//             for(int j=0;j<nums2.size();j++){
//                 if(nums[i]==nums[j]){
//                     if(nums[j+1]>nums[i] && ){
//                         nge[i]=nums2[];
//                     }else{
//                         nge[i] = -1;
//                     }
//                 }
//             }
//             return nge;
//         }

//     }
// };


// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> nge(nums1.size(), -1);  // Initialize result array with -1

//         for (int i = 0; i < nums1.size(); i++) {
//             for (int j = 0; j < nums2.size(); j++) {
//                 if (nums1[i] == nums2[j]) {
//                     if (j + 1 < nums2.size() && nums2[j + 1] > nums1[i]) {
//                         nge[i] = nums2[j + 1]; 
//                     }
//                     break;  
//                 }
//             }
//         }

//         return nge;
//     }
// };


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums1.size(), -1);  // Initialize result array with -1
        
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {//jb equal milgya dusri array mein
                    // if (j + 1 < nums2.size()) {  //yeh necessary nhi hai ab kyunki last wale ke case ko for loop se handle kr de
                        for (int k = j + 1; k < nums2.size(); k++) {
                            if (nums2[k] > nums1[i]) {
                                nge[i] = nums2[k];  // Found the next greater element
                                break;
                            }
                        }
                    // }
                    break;  
                }
            }
        }

        return nge;
    }
};