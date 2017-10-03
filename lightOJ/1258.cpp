#include<cstdio>
#include<cstring>
using namespace std;

int pi[1000006];
char ss[1000006],srev[1000006];

int main()
{
    int t,cs=0,i,j,k,len;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",ss);
        len=strlen(ss);
        for(i=0,j=len-1;i<len;i++,j--) srev[i]=ss[j];

        /* compute prefix function for reverse string*/

        pi[0]=0;
        k=0;
        for(i=1;i<len;i++)
        {
            while(k>0 && srev[k]!=srev[i]) k=pi[k-1];
            if(srev[k]==srev[i]) k++;
            pi[i]=k;
        }

        /* end of prefix function computation */

        /*Match pattern */

        k=0;
        for(i=0;i<len;i++)
        {
            while(k>0 && srev[k]!=ss[i]) k=pi[k-1];
            if(srev[k]==ss[i]) k++;
        }

        /* last k chars form a palindrome */
        printf("Case %d: %d\n",++cs,k+2*(len-k));
    }
    return 0;
}
