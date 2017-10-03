#include<stdio.h>
#include<math.h>

int main()
{
	int A,B,C,N,i,j,x,y,z,solved,k,lim,temx,temy,temz;
	float temp;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d %d %d",&A,&B,&C);
		solved=0;
		lim=floor(sqrt(C));
		for(i=0;i<=lim;i++)
		{
			for(j=i+1;j<=lim;j++)
			{
				temp=C-i*i-j*j;
				if(temp<0) break;
				temp=sqrt(temp);
				if(floor(temp)==ceil(temp) && floor(temp)>=j)
				{
					if(i*j*(int) temp==B)
					{
						temx=i;
						temy=j;
						temz=(int) temp;
						if(temx+temy+temz==A) 
						{
							if(solved==0 && temy!=temz)
							{
								solved=1;
								x=temx;
								y=temy;
								z=temz;
							}
						
						}
						else if(temz-temx-temy==A)
						{
							if(solved==0)
							{
								x=-temy;
								y=-temx;
								z=temz;
								solved=1;
							}
							else
							{
								if(-temy<x)
								{
									x=-temy;
									y=-temx;
									z=temz;

								}
							}
						}

					}
				}
			}
			
		}
		if(solved==1) printf("%d %d %d\n",x,y,z);
		else printf("No solution.\n");
	}
	return 0;
}