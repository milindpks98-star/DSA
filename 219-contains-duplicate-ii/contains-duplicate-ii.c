typedef struct{
    int key;
    int index;
    bool used; 
}hashnode;
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int size=numsSize*2+1;
    hashnode *table=calloc(size,sizeof(hashnode));
   

    for(int i=0;i<numsSize;i++)
    {
        int idx=((nums[i]%size)+size)%size;
            
            while(table[idx].used)
            {
                if(table[idx].key==nums[i])
                {
                     if(i-table[idx].index<=k)
                     {
                        free(table);
                        return true;
                     }
                }
                idx=(idx+1)%size;
                
                
            } 
            
            table[idx].key=nums[i];
            table[idx].used=true;
            table[idx].index=i;
          

    }return false;
}