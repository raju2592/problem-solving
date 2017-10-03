#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct l{
	char num[22];
	struct l *left;
	struct l *right;
} node;

node *root;
int no_entry,printed;

void add_tree(char *arr,node **p)
{
	if((*p)==NULL)
	{
		*p=(node *) malloc(sizeof(node));
		strcpy((*p)->num,arr);
		(*p)->left=NULL;
		(*p)->right=NULL;
	}
	else
	{
		if(strlen(arr)<strlen((*p)->num)) add_tree(arr,&(*p)->left);
		else if(strlen(arr)>strlen((*p)->num)) add_tree(arr,&(*p)->right);
		else if(strlen(arr)==strlen((*p)->num))
		{
			if(strcmp(arr,(*p)->num)<0) add_tree(arr,&(*p)->left);
			else if(strcmp(arr,(*p)->num)>0) add_tree(arr,&(*p)->right);
		}
	}
}

void inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		if(printed==no_entry-1) printf("%s",p->num);
		else printf("%s ",p->num);
		printed++;
		inorder(p->right);
	}
}



int main()
{
	char num[21],ans[22],cpy_num[21],bhagfol[21];
	int len,i,sum,temp,j,namai,m,k;
	while(1)
	{
		root=NULL;
		gets(num);
		no_entry=0;
		printed=0;
		if(strlen(num)==1 && num[0]=='0') break;
		else if(strlen(num)==1 && num[0]!='0')
		{
			puts(num);
			continue;
		}
		len=strlen(num);
		for(i=0;i<10;i++)
		{
			sum=0;
			strcpy(cpy_num,num);
			temp=i;
			for(j=0;j<len;j++) cpy_num[j]-=48;
			if(temp!=0)
			{

		    	for(j=len-1;j>=0;j--)
				{
			    	if(cpy_num[j]>=temp)
					{
						cpy_num[j]-=temp;
						break;
					}
					else
					{
						cpy_num[j]=10+cpy_num[j]-temp;
						temp=1;
					}
				}
			}
			for(j=0;j<len;j++) sum=sum+cpy_num[j];
			if(sum%9==0)
			{
				namai=0;
				j=0;
				k=0;
				while(j<len)
				{
					namai=namai*10+cpy_num[j];
					bhagfol[k]=namai/9;
					namai=namai%9;
					j++;
					k++;
				}

				bhagfol[k]=i;
				temp=0;
				m=0;
				for(j=0;j<=k;j++)
				{
					if(temp==0)
					{
						if(bhagfol[j]!=0)
						{
							temp=1;
							ans[m]=bhagfol[j];
							m++;
						}
					}
					else
					{
						ans[m]=bhagfol[j];
						m++;
					}
				}
				ans[m]=0;
				for(j=0;j<m;j++) ans[j]+=48;
				add_tree(ans,&root);
				no_entry++;
				i+=8;
			}
		}
		inorder(root);
		printf("\n");
	}

	return 0;
}

