#include <malloc.h>
#include <string.h>

char* replace(char* s, char* from, char* to)
{
    int stringLen,fromLen,toLen;
    int i=0,j,k;
    int flag=0,start,end;
    stringLen=strlen(s);
    fromLen=strlen(from);
    toLen=strlen(to);
    char *str = malloc((stringLen+1)* sizeof(char));

    for(i=0;i<stringLen;i++){
        flag=0;
        start=i;
        for(j=0;s[i]==from[j];j++,i++){
            if(j==fromLen-1){
                flag=1;
                end=i;
            }
            if(flag==0)
                i-=j;
            else{
                for(j=start;j<end;j++){
                    for(k=start;k<stringLen;k++){
                        s[k]=s[k+1];
                        stringLen--;
                        i--;
                    }
                }
                for(j=start;j<start+toLen;j++){
                    for(k=stringLen;k>=j;k--){
                        s[k+1]=s[k];
                        s[j]=to[j-start];
                        stringLen++;
                        i++;
                    }
                }
            }
        }
    }
    *str = *s;
    return str;
}