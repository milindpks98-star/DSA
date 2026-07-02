int dfs(int **grid,int rows,int cols,int r, int c)
{
    
 

    if(r<0 || r>=rows || c<0 ||c>=cols)
    {
        return 0;
    }
    if(grid[r][c]==0)
    return 0;
    grid[r][c]=0;
   
    return 1
     +dfs(grid,rows,cols,r-1,c)  
     +dfs(grid,rows,cols,r+1,c)
     +dfs(grid,rows,cols,r,c-1)
     +dfs(grid,rows,cols,r,c+1); 
    
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int max=0;
    for(int i=0;i<gridSize;i++)
    {
        for(int j=0;j<gridColSize[0];j++)
        {
            if(grid[i][j]==1)
            {
                
                int area=dfs(grid,gridSize,gridColSize[0],i,j);
                if(area>max)
                max=area;
            }
        }
    }return max;
}