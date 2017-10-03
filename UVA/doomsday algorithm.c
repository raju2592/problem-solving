#include<stdio.h>
int main()
{
    int t,m,d,day_num,i;
    int months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    char days[][20]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&d);
        day_num=0;
        for(i=1;i<m;i++) day_num+=months[i];
        day_num+=d;
        if(day_num>=157)
        {
            printf("%s\n",days[(day_num-157+2)%7]);
        }
        else
        {
            printf("%s\n",days[(9-(157-day_num)%7)%7]);
        }
    }
    return 0;
}
