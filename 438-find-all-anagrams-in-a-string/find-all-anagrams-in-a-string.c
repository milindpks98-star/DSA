/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    int h1[256]={0};//for s
    int h2[256]={0};//for p
    int l1=strlen(s);
    int l2=strlen(p);
    int *result=calloc(l1*2,sizeof(int));
    // if(l2>l1)return false;
   int i=0;
    for(int i=0;i<l2;i++)
    {
        h2[(unsigned char)p[i]]++;
    }
    int left=0;
    for(int right=0;right<l1;right++)
    {
        h1[(unsigned char)s[right]]++;

        while(right-left+1>l2)
        {
            h1[(unsigned char)s[left]]--;
            left++;
        }
        
        if(memcmp(h1,h2,sizeof(h2))==0)
        {
            
            result[i]=left;
            i++;
            
        }
    }
    *returnSize=i;
return result;
}