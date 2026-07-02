void dfs(char **grid,int rows,int columns,int r,int c)
{
    
    if(r<0||r>=rows || c<0||c>=columns)
    return ;
    if(grid[r][c]=='0')
    {
        return;
    }
    grid[r][c]='0';

    dfs(grid,rows,columns,r-1,c);
    dfs(grid,rows,columns,r+1,c);
    dfs(grid,rows,columns,r,c-1);
    dfs(grid,rows,columns,r,c+1);

     


}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int islands=0;
   for(int i=0;i<gridSize;i++)
   {
    for(int j=0;j<gridColSize[0];j++)
    {
        if(grid[i][j]=='1')
        {
            islands++;
            dfs(grid,gridSize,gridColSize[0],i,j);
        }
    }
   }
   return islands;
}