/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int **result;
 int *path;
 int pathsize;
 void dfs(int **graph,int graphSize,int* graphColSize,int node,int* returnSize,int **returnColumnSizes)
 {
    path[pathsize++]=node;
    if(node==graphSize-1)
    {
        result[*returnSize]=malloc(pathsize*sizeof(int *));
        memcpy(result[*returnSize], path, pathsize * sizeof(int));
        (*returnColumnSizes)[*returnSize]=pathsize;
        (*returnSize)++;

        pathsize--;
        return;
    }
    
    for(int i=0;i<graphColSize[node];i++)
    {
        
        
           
            dfs(graph,graphSize,graphColSize,graph[node][i],returnSize,returnColumnSizes);
       
    }
    pathsize--;

 }
int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {
    result=malloc(10000*sizeof(int *));
    *returnColumnSizes=malloc(10000*sizeof(int));
    path =malloc(graphSize*sizeof(int));
    pathsize=0;
    *returnSize=0;
  
    dfs(graph,graphSize,graphColSize,0,returnSize,returnColumnSizes);
    return result;
}