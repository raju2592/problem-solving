#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int i,j,k,p,l,t;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        scanf("%d %d",&p,&l);
        p-=l;
        vector<int> out;
        k=floor(sqrt(p));
        for(i=1;i<=k;i++)
        {
            if(p%i==0)
            {
                if(i>l) out.push_back(i);
                if(p/i>l && p/i!=i) out.push_back(p/i);
            }
        }
        if(out.size()==0) printf("Case %d: impossible\n",c);
        else
        {
            sort(out.begin(),out.end());
            printf("Case %d:",c);
            for(i=0;i<out.size();i++) printf(" %d",out[i]);
            puts("");
        }
    }
    return 0;
}
