class Solution {
public:
    vector<int>dir = {0,1,0,-1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();//row
        queue<pair<int,int>> qu;
        int m=mat[0].size();//col
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    qu.push({i,j});//is coordinate 
                }else{
                    mat[i][j]=-1;
                }
            }
        }
        while(!qu.empty()){
            auto[x,y] = qu.front();
            qu.pop();
            for(int i=0;i<4;i++){
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                //out of bounds conditon check krleni saari & already visited na ho
                if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==-1 ){
                    qu.push({nx,ny});
                    mat[nx][ny]=mat[x][y]+1;
                }
            }
        }

        return mat;
    }
};