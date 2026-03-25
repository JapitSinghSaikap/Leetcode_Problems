class Solution {
public:
   #define ll long long
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();


        ll total=0;
        for(auto& row:grid){
            for(auto&x  :row){
                total+=x;
            }
        }

        if(total%2) return false; 

        ll target=total/2;

        ll curr=0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                curr+=grid[i][j];
            }

            if(curr==target) return true;
        }
        
        curr=0;
        for (int j=0;j<n-1;j++) {
            for (int i=0;i<m;i++) {
                curr+=grid[i][j];
            }
            if (curr==target) return true;
        }


        return false;
    }
};