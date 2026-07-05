void heapifyup(int *heap,int index)
{
    while(index>0)
    {
        int parent=(index-1)/2;
        if(heap[parent]>heap[index])
        {int temp=heap[index];
        heap[index]=heap[parent];
        heap[parent]=temp;
        index=parent;}
        else
        {
            break;
        }
    }
}
void insert(int *heap,int *heapsize,int num)
{
    heap[*heapsize]=num;
    (*heapsize)++;
    heapifyup(heap,*heapsize-1);
}
void heapifyDown(int *heap,int heapsize,int index)
{
    while(1)
    {
    int min=index;
    int left=2*index+1;
    int right=2*index+2;
    if(left<heapsize && heap[left]<heap[min])
    {
        min=left;
    }
    if(right<heapsize && heap[right]<heap[min])
    {
        min=right;
    }
    if(min==index)
    break;

    int temp=heap[index];
    heap[index]=heap[min];
    heap[min]=temp;
    index=min;
    }

}
int findKthLargest(int* nums, int numsSize, int k) {
    int *heap=malloc(numsSize*sizeof(int));
    int heapsize=0;
    for(int i=0;i<numsSize;i++)
    {
        if(heapsize<k)
        {
            insert(heap,&heapsize,nums[i]);
        }
        else if(nums[i]>heap[0])
        {
            heap[0]=nums[i];
            heapifyDown(heap,heapsize,0);
        }
    }
    return heap[0];
}