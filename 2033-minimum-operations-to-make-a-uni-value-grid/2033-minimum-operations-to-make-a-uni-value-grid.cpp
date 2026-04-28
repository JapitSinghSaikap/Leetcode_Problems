class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        int col = grid[0].size();
        int row = grid.size();
       
        for( int i = 0 ; i < row ; i++ ){
            for( int j = 0 ; j < col ; j++ ){
                arr.push_back( grid[i][j] );
            }
        }
         int count = 0;
        sort(arr.begin(), arr.end()); 
        int n = arr.size();
        int median = arr[n/2];
       
        for( int i = 0 ; i < n ; i++ ){
            int diff = abs( median-arr[i] );
            if (diff%x!= 0 ) return -1;
            count += diff/x ;
        }
        return count;
    }
};