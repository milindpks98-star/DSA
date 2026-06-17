int calculatedays(int *weights,int weightsSize,int k)
{
     int days = 1;
    int currentLoad = 0;

    for(int i = 0; i < weightsSize; i++)
    {
        if(currentLoad + weights[i] > k)
        {
            days++;
            currentLoad = weights[i];
        }
        else
        {
            currentLoad += weights[i];
        }
    }

    return days;
}   

int shipWithinDays(int* weights, int weightsSize, int days) {
    int left=0;
    int right=0;
    
    for(int i=0;i<weightsSize;i++)
    {
        
        if(weights[i]>left)
        {
            left=weights[i];
        }

        right+=weights[i];

        
        

    }
    
    while(left<right)
    {
        int mid=left+(right-left)/2;
        int d=calculatedays(weights,weightsSize,mid);
        if(d<=days)
        {
            
            right=mid;
        }
        else
        left=mid+1;
    }

return left;
}