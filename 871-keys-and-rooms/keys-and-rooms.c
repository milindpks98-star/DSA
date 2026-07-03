void dfs(int **rooms,int roomsSize,int *roomsColSize,int roomNo,bool *visited)
{
    visited[roomNo]=true;
    for(int i=0;i<roomsColSize[roomNo];i++)
    {
        if(visited[rooms[roomNo][i]]==false)
        dfs(rooms,roomsSize,roomsColSize,rooms[roomNo][i],visited);
    }
    
}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool *visited=calloc(roomsSize,sizeof(bool));
    int roomNo=0;
    dfs(rooms,roomsSize,roomsColSize,roomNo,visited);
    for(int i=0;i<roomsSize;i++)
    {
        if(visited[i]==false)
        return false;
    }

    return true;
}