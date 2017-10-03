#include<stdio.h>
#include<string.h>
char mem[36][1005],num[50];
int len;
int calc(int s)
{
    if(s==len) return 0;
    if(num[s]=='2')
    {
        int i,j;
        if(s==len-1) return 0;
        for(i=0,j=s+1;j<=len;i++,j++) mem[s][i]=num[j];
        return 1;
    }
    else if(num[s]=='3')
    {
        int i=calc(s+1);
        if(i)
        {
            mem[s][0]=0;
            strcpy(mem[s],mem[s+1]);
            strcat(mem[s],"2");
            strcat(mem[s],mem[s+1]);
            return 1;
        }
        else return 0;
    }
    else return 0;
}
int main()
{
    int i,j,k;
    while(gets(num))
    {
        if(!strcmp(num,"0")) break;
        len=strlen(num);
        k=1;
        for(i=0;i<len;i++) if(num[i]=='0') k=0;
        if(!k) printf("NOT ACCEPTABLE\n");
        else
        {
            k=calc(0);
            if(!k) printf("NOT ACCEPTABLE\n");
            else puts(mem[0]);
        }
    }
    return 0;
}
