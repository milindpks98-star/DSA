char* minWindow(char* s, char* t) {
    int len1=strlen(s);
    int len2=strlen(t);
    int left=0;
    int right;
    int h1[256]={0};
    int h2[256]={0};
    int str_idx=0;
    

    int minsize=INT_MAX;
    if(len2>len1)
    return "";

    int required_match=0;
    for(right=0;right<len2;right++)
    {
        if(h2[(unsigned char) t[right]]==0)
        {
            required_match++;
        }
        h2[(unsigned char)t[right]]++;
    }

    int formed_match=0;
    for(int i=0;i<len1;i++)
    {
        h1[(unsigned char)s[i]]++;
        if(h2[(unsigned char)s[i]]>0 && h1[(unsigned char)s[i]]==h2[(unsigned char)s[i]])
        {
            formed_match++;
        }

        while(required_match==formed_match)
        {
            int size=i-left+1;
             if(size<minsize)
               {
                minsize=size;
                str_idx=left;
               }
               h1[(unsigned char)s[left]]--;
            if(h2[(unsigned char)s[left]]>0 && h1[(unsigned char)s[left]]<h2[(unsigned char)s[left]])
            {
                formed_match--;
            }
            left++;
        }
      
     
    }
    if(minsize==INT_MAX)
     return "";

    char *sub=malloc((minsize+1)*sizeof(char));
    strncpy(sub,s+str_idx,minsize);
    sub[minsize]='\0';
return sub;

}