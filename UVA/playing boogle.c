#include<stdio.h>
#include<string.h>
char boogle[4][6],words[102][18];
int visited[5][5];
int search(int r,int c,char *w)
{
    char str[18];
    int ret,i;
    if(strlen(w)==1) 
	{
		if(boogle[r][c]==w[0]) return 1;
		else return 0;
	}
    else
    {
        if(w[0]!=boogle[r][c]) return 0;
        else
        {
			ret=0;
            strcpy(str,w);
            for(i=1;i<=strlen(str);i++) str[i-1]=str[i];
            visited[r][c]=1;
            if(r+1<4 && visited[r+1][c]==0)
			{
				ret=search(r+1,c,str);
				visited[r+1][c]=0;
			}
			if(ret==1) return ret;
            if(r-1>=0 && visited[r-1][c]==0) 
			{
				ret=search(r-1,c,str);
				visited[r-1][c]=0;
			}
			if(ret==1) return ret;
            if(c+1<4 && visited[r][c+1]==0) 
			{
				ret=search(r,c+1,str);
				visited[r][c+1]=0;
			}
			if(ret==1) return ret;
            if(c-1>=0 && visited[r][c-1]==0) 
			{
				ret=search(r,c-1,str);
				visited[r][c-1]=0;
			}
			if(ret==1) return ret;
            if(r+1<4 && c+1<4 && visited[r+1][c+1]==0) 
			{
				ret=search(r+1,c+1,str);
				visited[r+1][c+1]=0;
			}
			if(ret==1) return ret;
            if(r+1<4 && c-1>=0 && visited[r+1][c-1]==0) 
			{
				ret=search(r+1,c-1,str);
				visited[r+1][c-1]=0;
			}
			if(ret==1) return ret;
            if(r-1>=0 & c+1<4 && visited[r-1][c+1]==0) 
			{
				ret=search(r-1,c+1,str);
				visited[r-1][c+1]=0;
			}
			if(ret==1) return ret;
            if(r-1>=0 && c-1>=0 && visited[r-1][c-1]==0) 
			{
				ret=search(r-1,c-1,str);
				visited[r-1][c-1]=0;
			}
            return ret;

        }
    }
}
int main()
{
    int t,c,m,i,j,k,a,b,found,points[]={0,0,0,1,1,2,3,5,11,11,11,11,11,11,11,11,11},score;
    char f;
    scanf("%d",&t);
	gets(words[101]);
    for(c=1;c<=t;c++)
    {   gets(words[101]);/*the blank line*/
        for(i=0;i<4;i++) gets(boogle[i]);
		scanf("%d",&m);
		gets(words[101]);
        for(i=0;i<m;i++) gets(words[i]);
        score=0;
        for(a=0;a<m;a++)
        {
            f=words[a][0];
            found=0;
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(boogle[i][j]==f)
                    {
                        for(k=0;k<5;k++)
                            for(b=0;b<5;b++) visited[k][b]=0;
                        found=search(i,j,words[a]);
                    }
                    if(found==1) break;
                }
                if(found==1) break;
            }
            if(found==1) score+=points[strlen(words[a])];
        }
        printf("Score for Boggle game #%d: %d\n",c,score);
    }
    return 0;
}
