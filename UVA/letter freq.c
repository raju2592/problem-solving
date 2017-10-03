#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct X{
	char c;
	int fre;
	struct X *left;
	struct X *right;
} node;

void get_maxfreq(node *p);
void print(int n,node *p);
void add_tree(char ch,node **p);
void print_tree(node *p)
{
	if(p!=NULL)
	{
		print_tree(p->left);
		printf("%c",p->c);
		print_tree(p->right);
	}
}

node *head=NULL;
int max=0;

void main()
{
	int n,i,j;
	char str[210];

	scanf("%d\n",&n);

	for(i=0;i<n;i++)
	{
		head=NULL;
		max=0;
		gets(str);
		for(j=0;j<strlen(str);j++)
		{
			if((str[j]>='a' && str[j]<='z') || (str[j]>='A' && str[j]<='Z'))
				add_tree(tolower(str[j]),&head);
		}
		get_maxfreq(head);
		print(max,head);
		printf("\n");
	}
}

void get_maxfreq(node *p)
{
	if(p!=NULL)
	{
		if(p->fre>max) max=p->fre;
		get_maxfreq(p->left);
		get_maxfreq(p->right);
	}

}

void print(int n,node *p)
{
	if(p!=NULL)
	{
		print(n,p->left);
		if(n==p->fre) printf("%c",p->c);
		print(n,p->right);
	}
}

void add_tree(char ch,node **p)
{
	if(*p==NULL)
	{
		(*p)=(node *) malloc(sizeof(node));
		(*p)->c=ch;
		(*p)->fre=1;
		(*p)->left=NULL;
		(*p)->right=NULL;
	}
	else
	{
		if(ch==(*p)->c) (*p)->fre++;
		else if(ch<(*p)->c) add_tree(ch,&(*p)->left);
		else if(ch>(*p)->c) add_tree(ch,&(*p)->right);
	}
}



