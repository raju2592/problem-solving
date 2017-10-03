#include<stdio.h>
#include<math.h>
#include<string.h>
#define ll long
ll dp[1005][1005],ch[1005][1005],prev[26][1005];
char fi[1005][1005];
char str[1005];
void print(ll l,ll r)
{
    if(l==r)
    {
        if(ch[l][r]==1) printf("%c",str[l]);
        return;
    }
    if(l>r) return;
    if(ch[l][r]==1)
    {
        printf("%c",str[l]);
        print(l+1,prev[str[l]-'a'][r]-1);
        if(prev[str[l]-'a'][r]>l) printf("%c",str[l]);
    }
    else print(l+1,r);

}
int main()
{
    ll i,j,k,l,m,n;
    while(scanf("%s",str)!=EOF)
    {
        l=strlen(str);
		memset(ch,-1,sizeof(ch));
        for(i=0;i<26;i++)
        {
            if(str[0]-'a'!=i) prev[i][0]=-1;
            else prev[i][0]=0;
        }
        for(i=0;i<26;i++)
        {
            for(j=1;j<l;j++)
            {
                if(str[j]-'a'==i) prev[i][j]=j;
                else prev[i][j]=prev[i][j-1];
            }
        }
        for(i=0;i<l;i++)
        {
            dp[i][i]=1;
            ch[i][i]=1;
            fi[i][i]=str[i];
            dp[i+1][i]=0;
			ch[i+1][i]=0;
        }
        for(i=2;i<=l;i++)
        {
            for(j=0;j<=l-i;j++)
            {
                dp[j][j+i-1]=dp[j+1][j+i-1];
                ch[j][j+i-1]=0;
                fi[j][j+i-1]=fi[j+1][j+i-1];
                k=prev[str[j]-'a'][j+i-1];
                if(k==j)
                {
                    if(1==dp[j][j+i-1] && str[j]<fi[j+1][j+i-1])
                    {
                        dp[j][j+i-1]=1;
                        ch[j][j+i-1]=1;
                        fi[j][j+i-1]=str[j];
                    }
                }
                else if(k>j)
                {
                    if(2+dp[j+1][k-1]>dp[j][j+i-1])
                    {
                        dp[j][j+i-1]=2+dp[j+1][k-1];
                        ch[j][j+i-1]=1;
                        fi[j][j+i-1]=str[j];
                    }
                    else if(2+dp[j+1][k-1]==dp[j][j+i-1])
                    {
                        ll len=dp[j][j+i-1];
                        len=(ll) ceil((float) len/2);
                        ll l1,r1,l2,r2;
                        l1=j,r1=j+i-1,l2=j+1,r2=j+i-1;
                        if(str[j]<fi[l2][r2]) ch[l1][r1]=1,fi[l1][r1]=str[j];
                        else if(str[j]>fi[l2][r2]) ch[l1][r1]=0,fi[l1][r1]=fi[l2][r2];
                        else
                        {
                            len--;
                            l1=j+1,r1=k-1;
                            while(ch[l2][r2]==0) l2++;
							r2=prev[str[l2]-'a'][r2];
                            l2++;
							r2--;
                            while(len>0)
                            {

                                if(ch[l1][r1]==1 && ch[l2][r2]==1)
                                {
                                    if(fi[l1][r1]<fi[l2][r2])
                                    {
                                        ch[j][j+i-1]=1;fi[j][j+i-1]=str[j];
                                        break;
                                    }
                                    else if(fi[l1][r1]>fi[l2][r2])
                                    {
                                        ch[j][j+i-1]=0;fi[j][j+i-1]=fi[j+1][j+i-1];
                                        break;
                                    }
                                    else
                                    {

                                        r1=prev[str[l1]-'a'][r1]-1;
                                        l1=l1+1;

                                        r2=prev[str[l2]-'a'][r2]-1;
										l2=l2+1;
                                    }
                                    len--;
                                }
                                else if(ch[l1][r1]==0)
                                {
                                    while(ch[l1][r1]==0) l1++;
									r1=prev[str[l1]-'a'][r1];
                                }
                                else if(ch[l2][r2]==0)
                                {
                                    while(ch[l2][r2]==0) l2++;
									r2=prev[str[l2]-'a'][r2];
                                }
                            }
                        }
                    }
                }
            }
        }
        print(0,l-1);
        puts("");
    }
    return 0;
}
