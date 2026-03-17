class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();   
        int m=matrix[0].size();
        vector<int> heights(m,0);
        int maxArea=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    heights[j]+=1;
                }else{
                    heights[j]=0;
                }
            }

            vector<int> temp=heights;

            sort(temp.begin(),temp.end(),greater<int>());

            for(int j=0;j<m;j++){
                int area=temp[j]*(j+1);
                maxArea=max(maxArea,area);
            }
        }

        return maxArea;
    }
};