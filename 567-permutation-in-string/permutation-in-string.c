

bool checkInclusion(char* s1, char* s2) {
 int h1[256]={0};
 int h2[256]={0};

 int left=0;
int l1=strlen(s1);
int l2=strlen(s2);
if(l1>l2)return false;

for(int i=0;i<l1;i++)
{
    h1[(unsigned char)s1[i]]++;
}

for(int right=0;right<l2;right++)
{
    h2[(unsigned char)s2[right]]++;

    while(right-left+1>l1)
    {
        h2[(unsigned char)s2[left]]--;
        left++;
    }

    if(memcmp(h1,h2,sizeof(h1))==0)
    return true;


}
return false;
}
