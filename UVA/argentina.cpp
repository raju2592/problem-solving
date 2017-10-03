#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

class player
{
	public:
    char name[25];
    int attack;
    int defend;
    void set(char *name,int attack,int defend);
    bool operator>(player p);
};
void insertion_sort_descending(player arr[],int l,int r)
{
    int i,j;
	player key;
    for(i=l+1;i<=r;i++)
    {
        j=i-1;
		key=arr[i];
        while(j>=l && key>arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void insertion_sort_by_name(player arr[],int l,int r)
{
    int i,j;
	player key;
    for(i=l+1;i<=r;i++)
    {
        j=i-1;
		key=arr[i];
        while(j>=l && strcmp(key.name,arr[j].name)<0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void player::set(char *name,int attack,int defend)
{
    strcpy(this->name,name);
    this->defend=defend;
    this->attack=attack;
}
bool player::operator>(player p)
{
    if(attack>p.attack) return true;
    else if(attack<p.attack) return false;
    else
    {
        if(defend<p.defend) return true;
        else if(defend>p.defend) return false;
        else
        {
            int d=strcmp(name,p.name);
            if(d<0) return true;
            else return false;
        }
    }
}
int main()
{
    int t,c,i,attack,defend;
    char name[25];
    player arr[10];
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        for(i=0;i<10;i++)
        {
            scanf("%s %d %d",name,&attack,&defend);
            arr[i].set(name,attack,defend);
        }
        insertion_sort_descending(arr,0,9);
        insertion_sort_by_name(arr,0,4);
        insertion_sort_by_name(arr,5,9);
        printf("Case %d:\n",c);
        printf("(");
        for(i=0;i<=3;i++) printf("%s, ",arr[i].name);
        printf("%s)\n(",arr[i].name);
        i++;
        for(;i<=8;i++) printf("%s, ",arr[i].name);
        printf("%s)\n",arr[i].name);
    }

    return 0;
}
