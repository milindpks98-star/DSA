int totalFruit(int* fruits, int fruitsSize) {
    int type=0;
    int left=0;
    int *count=calloc(100001,sizeof(int));
    int maxfruits=0;
    for(int right=0;right<fruitsSize;right++)
    {
       
        if(count[fruits[right]]==0)
        {
            type++;
        }
        
        count[fruits[right]]++;
    
        
        while(type>2)
        {
            count[fruits[left]]--;
            if(count[fruits[left]]==0)
            {
                type--;
            }
        left++;
        }
        int windowsize=right-left+1;
        if(windowsize>maxfruits)
        {
            maxfruits=windowsize;
        }
        


    }return maxfruits;
    
}