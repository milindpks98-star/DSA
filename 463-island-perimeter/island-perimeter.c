int dfs(int **grid,int rows,int cols,int r,int c)
{
    if(r<0 || r>=rows || c<0 || c>=cols)
    {
        return 1;
    }
    if(grid[r][c]==0)
    return 1;
    if(grid[r][c]==-1)
    return 0;
    grid[r][c]=-1;

   return
    + dfs(grid,rows,cols,r-1,c)
    + dfs(grid,rows,cols,r+1,c)
    + dfs(grid,rows,cols,r,c-1)
    + dfs(grid,rows,cols,r,c+1);
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int peri=0;
   for(int i=0;i<gridSize;i++)
   {
    for(int j=0;j<gridColSize[0];j++)
    {
        if(grid[i][j]==1)
        peri=dfs(grid,gridSize,gridColSize[0],i,j);
    }
   } 
   return peri;
    
}