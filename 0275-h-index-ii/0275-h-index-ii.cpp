class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int first = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            int dist = n - mid;
            if(arr[mid]>=dist){
                first = dist;
                right = mid -1;
            }
            else left = mid + 1;
        }
        return first;
      
    }
};