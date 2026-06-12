char* minWindow(char* s, char* t) {
  int len1=strlen(s);
  int len2=strlen(t);
  int left=0;
  int minsize=INT_MAX;
  int h1[256]={0};
  int h2[256]={0};
  int required_match=0;
  int formed_match=0; 
  int str_idx=0;

  for(int i=0;i<len2;i++)
  {
    if(h2[(unsigned char)t[i]]==0)
    {
        required_match++;
    }
    h2[(unsigned char)t[i]]++;
  }

  for(int right=0;right<len1;right++)
  {
    h1[(unsigned char)s[right]]++;
    if(h2[(unsigned char)s[right]]>0 && h1[(unsigned char)s[right]]==h2[(unsigned char)s[right]])
    {
        formed_match++;
    }
    

    while(formed_match==required_match)
    {
        int size=right-left+1;
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
  {
    return "";
  }

char *result=malloc((minsize+1)*sizeof(char));
strncpy(result,s+str_idx,minsize);
result[minsize]='\0';

return result;


}