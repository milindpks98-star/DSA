int *color;
bool dfs(int **graph,int *graphColSize,int node,int current_color)
{
    color[node]=current_color;
    
   
    
    for(int i=0;i<graphColSize[node];i++)
    {
        int neighbour=graph[node][i];
        if(color[neighbour]==-1)
         {
            if(!dfs(graph,graphColSize,neighbour,1-current_color))
            {
                return false;
            }
         }
         else if(color[neighbour]==current_color)
         return false;
    }
    return true;


}
bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    color=malloc(graphSize*sizeof(int));
    // memset(color,-1,graphSize*sizeof(int));
    for(int i=0;i<graphSize;i++)
    {
        color[i]=-1;
    }
    for(int i=0;i<graphSize;i++)
    {
        if(color[i]==-1)
        {
            if(!dfs(graph,graphColSize,i,0))
            {
                free(color);
                return false;
            }
        }

    }return true;
}