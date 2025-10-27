class Solution {
    public void setZeroes(int[][] matrix) {
        
        int m = matrix.length;
        int n= matrix[0].length;//for cols     

        boolean[] rows = new boolean[m];//check for rows
        boolean[] column = new boolean[n];//check for cols

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    rows[i]=true;
                    column[j]=true;
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(rows[i] || column[j]) 
                {
                    matrix[i][j]=0;            
                }
            }
        }


    }
}