class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //binary search approach
        int n = arr.size();
        int left = 0;
        int right = n-1;
        while(left<right){
            int mid = (left+right)/2;
            if(arr[mid+1]>arr[mid]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
    return left;
    }
};