#include<stdio.h>
#include<string.h>

int n,dp[55][55];
char arr[55][55];
int ch[2][55][55];

int test(int a,int b,int c,int d)
{
    if(a==b && c==d) return 1;
    if(ch[0][a][b]>ch[1][a][b])
    {
        if(arr[a][ch[0][a][b]]<arr[c][ch[0][c][d]]) return 1;
        return 0;
    }
    if(arr[a][ch[0][a][b]]<arr[c][ch[0][c][d]]) return 1;
    else if(arr[a][ch[0][a][b]]>arr[c][ch[0][c][d]]) return 0;
    else return test(ch[0][a][b],ch[1][a][b],ch[0][c][d],ch[1][c][d]);
}
int calc(int b,int e)
{
	int i,j,k;
    if(dp[b][e]!=-1) return dp[b][e];
    if(b==e) return dp[b][e]=0;
    dp[b][e]=1;
    ch[0][b][e]=e;
    ch[1][b][e]=b;
    for(i=b+1;i<e;i++)
    {
        for(j=e-1;j>=i;j--)
        {
            if(arr[b][i]==arr[e][j])
            {
                k=2+calc(i,j);
                if(k>dp[b][e])
                {
                    dp[b][e]=k;
                    ch[0][b][e]=i;
                    ch[1][b][e]=j;
                }
                else if(k==dp[b][e])
                {
                    if(arr[b][i]<arr[b][ch[0][b][e]])
                    {
                        ch[0][b][e]=i;
                        ch[1][b][e]=j;
                    }
                    else if(arr[b][i]==arr[b][ch[0][b][e]] && test(i,j,ch[0][b][e],ch[1][b][e]))
                    {
                        ch[0][b][e]=i;
                        ch[1][b][e]=j;
                    }
                }
            }
        }
    }
    return dp[b][e];
}

void print(int a,int b)
{
    if(a==b) return;
    if(ch[0][a][b]==b) printf("%c",arr[a][b]);
    else
    {
        printf("%c",arr[a][ch[0][a][b]]);
        print(ch[0][a][b],ch[1][a][b]);
        printf("%c",arr[a][ch[0][a][b]]);
    }
}

int main()
{
    int t,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++) gets(arr[i]);
        memset(dp,-1,sizeof(dp));
        calc(0,n-1);
        print(0,n-1);
        printf("\n");
    }
    return 0;
}
/*
1
5
*AAZZ
A*CZZ
AC*BZ
ZZB*A
ZZZA*
*/

/*
1
28
*CQKQIUNWYBXYFZXEQJVTVNCNNYY
C*AKMRNOGVBBXUMKPEQGUMHZHBWK
QA*MBLJLBJXZLKZFVPFFNEEKKUPM
KKM*DLKPLJRZJOKYSZPQJHBKSVIW
QMBD*BULZWYCTOIYNLMWMRRKXXJT
IRLLB*BVORKBIPLQMVITRVOEUPGR
UNJKUB*ISMQVFSBJQPTYVNQECCBS
NOLPLVI*CDZCJDZPCBMTHQWJTNHT
WGBLZOSC*FYARXFJRUTOWULVYAEW
YVJJWRMDF*NGKKNJUDAPHXBHJVGL
BBXRYKQZYN*ZAJIVZCIMNLUJFYZN
XBZZCBVCAGZ*JKTFPFACJDEPCLJK
YXLJTIFJRKAJ*TMSZRZJDAJTUQOE
FUKOOPSDXKJKT*HMAPXHIKOVXDYH
ZMZKILBZFNITMH*JXKRHSZGBGHEN
XKFYYQJPJJVFSMJ*FZCVSGTSLBSH
EPVSNMQCRUZPZAXF*USPGWJMTGSB
QEPZLVPBUDCFRPKZU*MTQVTDXWIE
JQFPMITMTAIAZXRCSM*OKGIVHJBE
VGFQWTYTOPMCJHHVPTO*PBESNHWA
TUNJMRVHWHNJDISSGQKP*DDBKRUN
VMEHRVNQUXLDAKZGWVGBD*PQTQXU
NHEBROQWLBUEJOGTJTIEDP*YBUAI
CZKKKEEJVHJPTVBSMDVSBQY*KJCX
NHKSXUCTYJFCUXGLTXHNKTBK*DGQ
NBUVXPCNAVYLQDHBGWJHRQUJD*DD
YWPIJGBHEGZJOYESSIBWUXACGD*P
YKMWTRSTWLNKEHNHBEEANUIXQDP*
*/
