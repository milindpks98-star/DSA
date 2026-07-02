/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int **image,int rows,int col,int r,int c,int old_color,int new_color)
{
    if(r<0||r>=rows ||  c<0||c>=col)
    return;
    if(image[r][c]!=old_color)
    return;
    image[r][c]=new_color;
    dfs(image,rows,col,r-1,c,old_color,new_color);
    dfs(image,rows,col,r+1,c,old_color,new_color);
    dfs(image,rows,col,r,c-1,old_color,new_color);
    dfs(image,rows,col,r,c+1,old_color,new_color);
}
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
   
   *returnSize=imageSize;
   *returnColumnSizes=imageColSize;
   int old_color=image[sr][sc];
   if(old_color==color)
   return image;
   dfs(image,imageSize,imageColSize[0],sr,sc,old_color,color);
   return image;
}