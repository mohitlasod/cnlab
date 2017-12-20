//Priority Queue

#include<stdio.h>
#include<stdlib.h>
int hpq[10],lpq[10],fronth=-1,rearh=-1,frontl=-1,rearl=-1,sizeh,sizel;

void insert(int *queue,int *front,int *rear,int *size,int data)
{
	if(*rear==*size)
	{
		printf("\nQueue Overflow\n");
		return;
	}
	if(*rear==-1)
		*front=0;
	queue[++*rear]=data;
}

void delete()
{
	if(rearh==-1)
	{
		if(rearl==-1)
		{
			printf("\nBoth Queues are Empty!\n");
			return;
		}
		
		printf("Deleted Element from Low PQ is %d\n",lpq[frontl]);
		if(frontl==rearl)
			frontl=rearl=-1;
		else
			frontl++;
		return;
		

	}

	printf("Deleted Element from High PQ is %d\n",hpq[fronth]);
	
	if(fronth==rearh)
		fronth=rearh=-1;
	else
		fronth++;
	return;

}

void display()
{
	int i;
	if(fronth==-1 && frontl==-1)
	{
		printf("\nHPQ Empty\n");
		printf("LPQ Empty\n");
		return;
	}
	else if(fronth==-1 && frontl!=-1)
	{
		printf("\nHPQ Empty\n");
		printf("\nLPQ Elements are:-\n");
		for(i=frontl;i<=rearl;i++)
			printf("%d\t",lpq[i]);
		return;
	}
	else if(fronth!=-1 && frontl==-1)
	{
		printf("\nHPQ Elements are:-\n");
		for(i=fronth;i<=rearh;i++)
			printf("%d\t",hpq[i]);
		printf("\nLPQ Empty\n");
		return;
	}
	else
	{
		printf("\nHPQ Elements are:-\n");
		for(i=fronth;i<=rearh;i++)
			printf("%d\t",hpq[i]);
		printf("\nLPQ Elements are:-\n");
		for(i=frontl;i<=rearl;i++)
			printf("%d\t",lpq[i]);
		return;
	}
}


void main()
{
	int ch,elem,p;
	printf("\nEnter HPQ Size: ");
	scanf("%d",&sizeh);
	printf("\nEnter LPQ Size: ");
	scanf("%d",&sizel);

	do
	{
		printf("\n\t\t**MENU**\t\t\n");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter Your Choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter Data: ");
				scanf("%d",&elem);
				printf("\nEnter Priority (1-High/0-Low):");
				scanf("%d",&p);
				if(p==1)
					insert(hpq,&fronth,&rearh,&sizeh,elem);
				else if(p==0)
					insert(lpq,&frontl,&rearl,&sizel,elem);
				else
					printf("\nInvalid Choice!\n");
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nInvalid Choice!\n");
		}

	}while(ch!=4);	
}	
