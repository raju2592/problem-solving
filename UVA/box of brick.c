#include<stdio.h>
#include<stdlib.h>

typedef struct X{

	int n;

	int *p;

	struct X* next;
} node;


node *head=NULL;

void main()
{
	node *current;

	int i,sum,j,temp,ans;

	head=(node *) malloc(sizeof(node));

	current=head;

	while(1)
	{
		scanf("%d",&current->n);

		if(current->n==0)
		{
			current->p=NULL;

			current->next=NULL;

			break;

		}

		current->p=(int *) malloc(current->n*sizeof(int));

		for(i=0;i<current->n;i++) scanf("%d",&current->p[i]);

		/*for(i=0;i<current->n;i++) printf("%5d",current->p[i]);*/

		current->next=(node *) malloc(sizeof(node));

		current=current->next;

	}

	current=head;

	for(i=1;current->n!=0;i++)
	{
		/*for(j=0;j<current->n;j++) printf("%5d",current->p[j]);

		printf("\n");

		current=current->next;*/

		sum=0;

		for(j=0;j<current->n;j++) sum=sum+current->p[j];


		temp=sum/current->n;

		ans=0;

		for(j=0;j<current->n;j++)
		{
			if(current->p[j]<temp) ans=ans+(temp-current->p[j]);

		}

		printf("Set #%d\n",i);

		printf("The minimum number of moves is %d.\n\n",ans);

		current=current->next;

	}





}



			
